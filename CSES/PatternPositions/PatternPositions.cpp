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

const int oo = 1e9;
struct node {
    map<char, int> ch, next;
    int link = - 1;
    int p; char pch;
    vec<int> ixs;
    int minx;
    node(int p_=-1, char pch_=-1, int ix_=-1): p(p_), pch(pch_), ixs({}), minx(oo) {}
};
vec<node> t;
void init_aho() {
    t.clear();t.pb(node());
}
void add_string(const string &s, const int ix) {
    int v = 0;
    for (const char c: s){
        if (!t[v].ch[c]){
            t[v].ch[c] = SZ(t);
            t.eb(v,c);
        }
        v = t[v].ch[c];
    }
    t[v].ixs.pb(ix);

}

int go(int v, char c);

int link(int v) {
    if (t[v].link == -1){
        if (!v||!t[v].p) t[v].link=0;
        else t[v].link = go(link(t[v].p), t[v].pch);
    }
    return t[v].link;
}

int go(int v, char c) {
    if (!t[v].next.count(c)){
        if (t[v].ch.count(c)) t[v].next[c] = t[v].ch[c];
        else t[v].next[c]= v==0? 0 : go(link(v), c);
    }
    return t[v].next[c];
}


void solve()
{
    string s; cin >> s;
    int n = SZ(s);
    init_aho();
    int m; cin >> m;
    vec<string> ps(m);
    L(i,0,m) {
        cin >> ps[i];
        add_string(ps[i], i);
    }
    {
        int v = 0;
        L(i,0,n){
            const char c = s[i];
            v = go(v, c);
            t[v].minx = min(t[v].minx, i);
        }
    }
    
    vec<vec<int>> g(SZ(t));
    vec<int> dp(SZ(t), oo + 1);
    auto build = [&](auto && dfs, int u) -> void {
        if (u > 0) {
            g[link(u)].pb(u);
        }
        for (const auto &[ch, v]: t[u].ch)  {
            // g[u].pb(v);
            dfs(dfs, v);
        }
    };  
    build(build, 0);
    vec<int> ans(m);
    auto calc = [&](auto && dfs, int u) -> int {
        if (dp[u] != oo + 1) return dp[u];
        int mn = t[u].minx;
        for (const auto &v: g[u]) {
            mn = min(mn, dfs(dfs, v));
        }
        for (const int ix: t[u].ixs) ans[ix] = mn == oo ? -1 : mn;
        return dp[u] = mn;
    };
    calc(calc, 0);
    L(i,0,m) {
        if (ans[i] == -1) {
            cout << "-1\n";
            continue;
        }
        int sz = SZ(ps[i]);
        cout << (ans[i] - sz + 2) << "\n";
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