#include <bits/stdc++.h>
using namespace std;

#define L(i, j, n) for (int i = (j); i < (int)n; i ++)
#define SZ(x) int((x).size())
#define ALL(x) begin(x),end(x)
#define vec vector
#define pb push_back

using ll = long long;
using ld = long double;

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
			for (int j = 0; j < m; j++) vis[n+j] = 0;
			aum = 0;
			for (int i = 0; i < n; i++)
				if (ma[i] == -1 and dfs(i)) ret++, aum = 1;
		}
		return ret;
	}
};

void solve()
{
    int n, m, e; cin >> n >> m >> e;
    kuhn hk(n, m);
    while(e--)
    {
        int u, v; cin >> u >> v;
        hk.add(u, v);
    }
    int ans = hk.matching();
    cout << ans << "\n";
    L(i,0,m) if (hk.mb[i] != -1){
    cout << hk.mb[i] << " " << i << "\n"; 
    }
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    //cin >> TT;
    while (TT--)
    {
        solve();
    }
}