#include <bits/stdc++.h>
using namespace std;

#define L(i, j, n) for (int i = (j); i < (int)n; i ++)
#define SZ(x) int((x).size())
#define ALL(x) begin(x),end(x)
#define vec vector
#define pb push_back

const int oo = 1e9;

struct node {
    int ch[26];   // Trie transitions
    int next[26]; // Computed transitions (memoized)
    int link = -1;
    int p = 0;
    char pch = 0;
    vec<int> ixs;
    int minx = oo;

    node(int p_ = 0, char pch_ = 0) : p(p_), pch(pch_) {
        memset(ch, -1, sizeof(ch));
        memset(next, -1, sizeof(next));
    }
};

vec<node> t;

void init_aho() {
    t.clear();
    t.pb(node()); // Add root
}

void add_string(const string &s, const int ix) {
    int v = 0;
    for (const char raw_c : s) {
        int c = raw_c - 'a';
        if (t[v].ch[c] == -1) {
            t[v].ch[c] = SZ(t);
            t.pb(node(v, c)); // Store parent v and char c
        }
        v = t[v].ch[c];
    }
    t[v].ixs.pb(ix);
}

// Forward declaration
int go(int v, int c);

int link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0) {
            t[v].link = 0;
        } else {
            // Recursive formula: link(v) = go(link(parent), parent_char)
            t[v].link = go(link(t[v].p), t[v].pch);
        }
    }
    return t[v].link;
}

int go(int v, int c) {
    if (t[v].next[c] == -1) {
        if (t[v].ch[c] != -1) {
            t[v].next[c] = t[v].ch[c];
        } else {
            // If at root, stay at root. Else follow failure link.
            t[v].next[c] = (v == 0 ? 0 : go(link(v), c));
        }
    }
    return t[v].next[c];
}

void solve() {
    string s; cin >> s;
    int n = SZ(s);
    
    init_aho();
    
    int m; cin >> m;
    vec<string> ps(m);
    L(i, 0, m) {
        cin >> ps[i];
        add_string(ps[i], i);
    }
    
    // Scan Phase
    {
        int v = 0;
        L(i, 0, n) {
            int c = s[i] - 'a';
            v = go(v, c); // Lazy evaluation happens here
            t[v].minx = min(t[v].minx, i);
        }
    }
    
    // Build Suffix Link Graph for propagation
    // Note: We need to ensure links are computed for all nodes used in propagation
    // (Though they likely are if we visited them, to be safe we call link(u))
    vec<vec<int>> g(SZ(t));
    for (int i = 1; i < SZ(t); i++) {
        g[link(i)].pb(i);
    }
    
    vec<int> ans(m);
    vec<int> dp(SZ(t), -1);

    auto calc = [&](auto && dfs, int u) -> int {
        if (dp[u] != -1) return dp[u];
        
        int mn = t[u].minx;
        for (int v : g[u]) {
            int val = dfs(dfs, v);
            mn = min(mn, val);
        }
        
        for (int ix : t[u].ixs) {
            ans[ix] = (mn == oo ? -1 : mn);
        }
        return dp[u] = mn;
    };
    
    calc(calc, 0);
    
    L(i, 0, m) {
        if (ans[i] == -1) {
            cout << "-1\n";
        } else {
            cout << (ans[i] - SZ(ps[i]) + 2) << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}