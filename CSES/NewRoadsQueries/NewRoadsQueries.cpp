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

struct RollbackUF { // Required
	vec<int> e; vector<pair<int,int>> st;
	RollbackUF(int n) : e(n, -1) {}
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : find(e[x]); }
	int time() { return SZ(st); }
	void rollback(int t) {
		for (int i = time(); i --> t;)
			e[st[i].first] = st[i].second;
		st.resize(t);
	}
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		st.push_back({a, e[a]});
		st.push_back({b, e[b]});
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

void solve()
{
    int n, m, q; cin >> n >> m >> q;
    vec<pair<int,int>> edges; edges.reserve(m+1); edges.eb(-1,-1);
    vec<pair<int,int>> qs; qs.reserve(q);
    L(i,0,m){
        int u, v; cin >> u >> v;
        edges.eb(u - 1, v - 1);
    }
    L(i,0,q){
        int u, v; cin >> u >> v;
        qs.eb(u - 1, v - 1);
    }
    vec<int> ans(q, -1);
    vec<int> qtime(m + 1);
    RollbackUF ds(n);
    int q_cur = 0;
    auto st_upd = [&](int i_q, bool op) {
        if (op) {
            qtime[i_q] = ds.time();
            ds.join(edges[i_q].first, edges[i_q].second);
        } else {
            ds.rollback(qtime[i_q]);
        }
    };

    auto calc = [&](auto && rec, int low, int high, vec<int> &own) -> void {
        if (own.empty()) return;
        int mid = (low + high) / 2;
        while (q_cur < mid) st_upd(++q_cur, 1);
        while (q_cur > mid) st_upd(q_cur--, 0); 
        vec<int> left, right;
        for (int o: own) {
            auto [u, v] = qs[o];
            if (ds.find(u) == ds.find(v)){
                ans[o] = mid;
                left.pb(o);
            } else right.pb(o);
        }
        own.clear();
        if (low < high) {
            rec(rec, low, mid, left);
            rec(rec, mid + 1, high, right);
        }
    };

    vec<int> owners(q);
    iota(ALL(owners), 0);
    calc(calc, 1, m, owners);
    
    L(i,0,q) {
        if (qs[i].first == qs[i].second) ans[i] = 0;
        cout << ans[i] << "\n";
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