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
		for (int &id = nxt[i]; id < SZ(g[i]); id++) {
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
	vec<int> cover[2]; // if cover[i][j] = 1 -> node i, j is part of cover
	void konig() {
		cover[0].assign(n,1); // n left size
		cover[1].assign(m,0); // m right size
		auto go = [&](auto&& me, int u) -> void {
			cover[0][u] = false;
			for (auto v : g[u]) if (!cover[1][v]) {
				cover[1][v] = true;
				me(me,mb[v]);
			}
		};
		L(u,0,n) if (ma[u] < 0) go(go,u);
	}
};

void solve()
{
    int n; cin >> n;
    hopcroft_karp mt(n, 3 * n);
    map<ll, int> h;
    vec<array<ll,2>> ps(n);
    int ix = 1;
    L(i,0,n){
        ll x, y; cin >> x >> y;
        ps[i] = {x, y};
        if (!h[x + y]) h[x+y] = ix++;
        if (!h[x - y]) h[x-y] = ix++;
        if (!h[x * y]) h[x*y] = ix++;
        mt.add(i, h[x + y] - 1);
        mt.add(i, h[x - y] - 1);
        mt.add(i, h[x * y] - 1);
    }
    int mtx = mt.matching();
    if (mtx < n) {
        cout << "impossible\n";
        return;
    }
    L(i,0,n) {
        auto [x, y] = ps[i];
        if (h[x+y]-1 == mt.ma[i]) {
            cout << x << " + " << y << " = " << x+y << "\n";
        } else if (h[x - y] - 1 == mt.ma[i]) {
            cout << x << " - " << y << " = " << x-y << "\n";
        } else {
            cout << x << " * " << y << " = " << x*y << "\n";
        }
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