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

struct node {
    int ch[26], next[26]; // Full DFA Transitions
    int link = 0; ll times = 0; // Suffix Link
    vec<int> ixs; // Indices of patterns ending here
    
    node() { memset(ch, -1, sizeof(ch));}
};
vec<node> t; vec<int> bfs_order; // easy traverse from short to longer words
void init_aho() {t.clear();t.pb(node());bfs_order.clear();}
void add_string(const string &s, const int ix) {
    int v = 0;
    for (char c_raw : s) {
        int c = c_raw - 'a';
        if (t[v].ch[c] == -1) {
            t[v].ch[c] = SZ(t);
            t.pb(node());
        }
        v = t[v].ch[c];
    }
    t[v].ixs.pb(ix);
}
void build_aho() {
    bfs_order.pb(0); // Root is first
	L(c,0,26){
        if (t[0].ch[c] != -1) {
            t[0].next[c] = t[0].ch[c];
            bfs_order.pb(t[0].ch[c]);
        } else t[0].next[c] = 0;
    }
    L(q, 1, SZ(bfs_order)){ // warn: 1 not 0!
        int u = bfs_order[q];
		L(c,0,26){
            if (t[u].ch[c] != -1) {
                int v = t[u].ch[c];
                t[u].next[c] = v;
                t[v].link = t[t[u].link].next[c];
                bfs_order.pb(v);
            } else t[u].next[c] = t[t[u].link].next[c];
        }
    }
}

void solve()
{
    string s; cin >> s;
    int n = SZ(s);
    int m; cin >> m;
    init_aho();
    L(i,0,m){
        string p;
        cin >> p;
        add_string(p, i);
    }
    build_aho();
    int state = 0;
    L(i,0,n){
        state = t[state].next[s[i] - 'a'];
        t[state].times ++;
    }
    vec<ll> dp(SZ(t));
    vec<ll> ans(m);
    for (int i = SZ(t) - 1; i > 0; i --){
        int u = bfs_order[i];
        dp[u] += t[u].times;
        dp[t[u].link] += dp[u];
        for(int ix: t[u].ixs) ans[ix] = dp[u];
    }

    L(i,0,m){
        cout << (ans[i]>0?"YES":"NO") << "\n";
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