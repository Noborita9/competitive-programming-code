#include <bits/stdc++.h>
using namespace std;

#define L(i, j, n) for (int i = (j); i < (int)n; i ++)
#define SZ(x) int((x).size())
#define ALL(x) begin(x),end(x)
#define vec vector
#define pb push_back
#define eb emplace_back

using ll = long long;
using ld = long double;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
struct kuhn {
	int n, m;
	vec<vec<int>> g;
	vec<int> vis, ma, mb;
	kuhn(int n_, int m_) : n(n_), m(m_), g(n),
		vis(n+m), ma(n, -1), mb(m, -1) {}
	void add(int a, int b) { g[a].pb(b); }
	bool dfs(int i) {
		vis[i] = 1;
		for (int j : g[i]) if (!vis[n+j]) {
			vis[n+j] = 1;
			if (mb[j] == -1 or dfs(mb[j])) {
				ma[i] = j, mb[j] = i;
				return true;
			}
		}
		return false;
	}
	int matching() {
		int ret = 0, aum = 1;
		for (auto& i : g) shuffle(ALL(i), rng);
		while (aum) {
			aum = 0;
            L(j,0,m) vis[n+j] = 0;
            L(i,0,n) if (ma[i]==-1 and dfs(i)) ret++,aum=1;
		}
		return ret;
	}
};
pair<vec<int>, vec<int>> recover(kuhn& K) { // min cover
	K.matching(); 
	int n = K.n, m = K.m;
	for (int i = 0; i < n+m; i++) K.vis[i] = 0;
	for (int i = 0; i < n; i++) if (K.ma[i] == -1) K.dfs(i);
	vector<int> ca, cb; // flip vis check to max indep set
	for (int i = 0; i < n; i++) if (!K.vis[i]) ca.push_back(i);
	for (int i = 0; i < m; i++) if (K.vis[n+i]) cb.push_back(i);
	return {ca, cb};
}

using ii = pair<ll,ll>;
void solve()
{
    int n, m; cin >> n >> m;
    vec<ii> p; p.reserve(n);
    auto dist = [&](const ii f, const ii s) -> ld {
        ll dx = f.first - s.first;
        ll dy = f.second - s.second;
        return sqrtl(dx * dx + dy * dy);
    };
    L(i,0,n){
        ll x, y; cin >> x >> y; p.eb(x, y);
    }
    vec<ii> ip; ip.reserve(m);
    L(i,0,m){
        ll x, y; cin >> x >> y; ip.eb(x, y);
    }
    kuhn mt(n - 1, m);

    L(i,0,n - 1)
    {
        int ni = i;
        int nj = i + 1;
        ld d = dist(p[ni], p[nj]);
        L(j,0,m) {
            if (d * 2 >= dist(p[ni], ip[j]) + dist(ip[j], p[nj])) {
                mt.add(ni, j);
            }
        }
    }

    mt.matching();
    vec<ii> tr;
    L(i,0,n) {
        tr.pb(p[i]);
        if (i < n - 1 && mt.ma[i] != -1) {
            tr.pb(ip[mt.ma[i]]);
        }
    };
    cout << SZ(tr) << "\n";
    L(i,0,SZ(tr)) {
        cout << tr[i].first << " " << tr[i].second;
        if (i + 1 < SZ(tr)) cout << " ";
    }
    cout << "\n";
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
        if (TT) cout << "\n";
    }
}