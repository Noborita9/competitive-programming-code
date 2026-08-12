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
struct hopcroft_karp {
	int n, m; // n is Left Partition Size, m is Right Partition Size
	vec<vec<int>> g;
	vec<int> dist, nxt, ma, mb;
	hopcroft_karp(int n_, int m_) : n(n_), m(m_), g(n),
		dist(n), nxt(n), ma(n, -1), mb(m, -1) {}
	void add(int a, int b) { g[a].pb(b); }
	bool dfs(int i) {
		for (int &id = nxt[i]; id < g[i].size(); id++) {
			int j = g[i][id];
			if (mb[j] == -1 or (dist[mb[j]] == dist[i]+1 and dfs(mb[j]))) {
				ma[i] = j, mb[j] = i;
				return true;
			}
		}
		return false;
	}
	bool bfs() {
		L(i,0,n) dist[i] = n;
		queue<int> q;
		L(i,0,n) if(ma[i]==-1) {
			dist[i] = 0; q.push(i);
		}
		bool rep = 0;
		while (q.size()) {
			int i = q.front(); q.pop();
			for (int j : g[i]) {
				if (mb[j] == -1) rep = 1;
				else if (dist[mb[j]] > dist[i] + 1) {
					dist[mb[j]] = dist[i] + 1;
					q.push(mb[j]);
				}
			}
		}
		return rep;
	}
	int matching() {
		int ret = 0;
		for (auto& i : g) shuffle(ALL(i), rng);
		while (bfs()) {
			L(i,0,n) nxt[i]=0;
			L(i,0,n) if (ma[i]==-1 and dfs(i)) ret++;
		}
		return ret;
	}
	
};

void solve()
{
    int n; cin >> n;
    hopcroft_karp mt(n, 2 * n);
    L(i,0,n){
        int p, q; cin >> p >> q;
        p --; q --;
        mt.add(i, p);
        mt.add(i, q);
    }
    cout << (mt.matching() == n ? "possible" : "impossible") << "\n";
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
    }
}