#include <bits/stdc++.h>
using namespace std;
#define L(i,j,n) for(int i=j;i<int(n);i++)
#define ALL(x) begin(x),end(x)
#define SZ(x) int(x.size())
#define pb push_back
#define eb emplace_back
#define vec vector
using ll=long long;
using ld=long double;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
struct kuhn {
	int n, m;
	vector<vector<int>> g;
	vector<int> vis, ma, mb;
	kuhn(int n_, int m_) : n(n_), m(m_), g(n),
		vis(n+m), ma(n, -1), mb(m, -1) {}
	void add(int a, int b) { g[a].push_back(b); }
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
		for (auto& i : g) shuffle(i.begin(), i.end(), rng);
		while (aum) {
			aum = 0;
            L(j,0,m) vis[n+j] = 0;
            L(i,0,n) if (ma[i]==-1 and dfs(i)) ret++,aum=1;
		}
		return ret;
	}
};

using iii = tuple<int,int, int>;

void solve(){
    int n, m; cin >> n >> m;
    vec<iii> E;
    L(i,0,m){
        int u, v, d; cin >> u >> v >> d;
        u --; v--;
        E.eb(d, u, v);
    }
    sort(ALL(E));
    auto check = [&](int t) -> bool {
        kuhn hp(n, n);
        for (const auto &[d, u, v]: E) {
            if (d > t) break;
            // cout << u << " " << v << " " << d << "\n";
            hp.add(u, v);
        }
        int mt = hp.matching();
        // cout << mt << "\n";
        return mt == n;
    };
    int lo = 0;
    const int oo = 1e9 + 1;
    int hi = 1e9 + 1;
    int ans = oo;
    while(lo <= hi) {
        int md = lo + ((hi - lo) / 2);
        if (check(md)) {
            hi = md - 1;
            ans = md;
        } else lo = md + 1;
    }
    if (ans == oo) ans = -1;
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int TT=1;
    // cin>>TT;
    while(TT--){
        solve();
    }
}