#include <bits/stdc++.h>
using namespace std;

#define L(i, j, n) for (int i = (j); i < (int)n; i++)
#define SZ(x) int((x).size())
#define vec vector
#define pb push_back

const int oo = 1e9;

struct node {
    int ch[26], next[26]; // Full DFA Transitions
    int link = 0, minx = oo; // Suffix Link
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
    for (int c = 0; c < 26; c++) {
        if (t[0].ch[c] != -1) {
            t[0].next[c] = t[0].ch[c];
            // link[child] is already 0
            bfs_order.pb(t[0].ch[c]); // Record order
        } else {
            t[0].next[c] = 0;
        }
    }
    L(q, 1, SZ(bfs_order)){ // warn: 1 not 0!
        int u = bfs_order[q];
        for (int c = 0; c < 26; c++) {
            if (t[u].ch[c] != -1) {
                int v = t[u].ch[c];
                t[u].next[c] = v;
                t[v].link = t[t[u].link].next[c];
                bfs_order.pb(v); // Record order
            } else t[u].next[c] = t[t[u].link].next[c];
        }
    }
}

void solve() {
    string s; cin >> s;
    init_aho();
    
    int m; cin >> m;
    vec<int> sz(m);
    L(i, 0, m) {
        string p; cin >> p;
        sz[i] = SZ(p);
        add_string(p, i);
    }

    build_aho();
    // 1. SCAN: Blazing fast DFA traversal
    {
        int v = 0;
        L(i, 0, SZ(s)) {
            v = t[v].next[s[i] - 'a'];
            t[v].minx = min(t[v].minx, i);
        }
    }
    // 2. PROPAGATE: Linear Reverse Iteration
    // Iterate from End to Start (Long patterns -> Short suffixes)
    for (int i = SZ(bfs_order) - 1; i >= 0; i--) {
        int u = bfs_order[i];
        int fail = t[u].link;
        // Propagate min_index up to the suffix
        t[fail].minx = min(t[fail].minx, t[u].minx);
    }

    L(i, 0, m) {
        // Collect answer from the specific node where pattern ended
        // The propagation step ensured t[v].minx includes matches of super-strings
        int v = 0;
        // Re-traverse or just store node index in add_string? 
        // Better: We stored indices in t[v].ixs!
        // But wait, we need to output in order 0..m-1.
        // We can't easily map i -> node unless we stored it.
        // Let's re-traverse to find the node for pattern i (cheap enough)
        // OR better: Create a direct lookup array
    }
    
    // Efficient Output Construction
    vec<int> final_ans(m);
    L(u, 0, SZ(t)) {
        for (int ix : t[u].ixs) {
            final_ans[ix] = (t[u].minx == oo ? -1 : t[u].minx);
        }
    }

    L(i, 0, m) {
        if (final_ans[i] == -1) cout << "-1\n";
        else cout << (final_ans[i] - sz[i] + 2) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}