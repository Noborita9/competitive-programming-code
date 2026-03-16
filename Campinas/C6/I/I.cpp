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

struct trie {
    map<char,int> ch;
    vec<int> a, b;
    trie() {}
};
const int N = 800'010;

vec<trie> t;
int sz[N];
void init(){
    t.clear();
    t.reserve(N);
    t.pb(trie());
}
void add(string &s, int ix, bool n){
    int v = 0;
    for (const char &c: s) {
        if (!t[v].ch[c]) {
            t[v].ch[c] = SZ(t);
            t.pb(trie());
        }
        v = t[v].ch[c];
    }
    if (n) t[v].a.pb(ix);
    else t[v].b.pb(ix);
}

void solve()
{
    int n; cin >> n;
    init();
    L(i,0,n) {
        string s; cin >> s;
        add(s, i, 1);
    }
    L(i,0,n) {
        string s; cin >> s;
        add(s, i, 0);
    }
    // cout << "Trie loaded " << endl;

    vec<pair<int, int>> out;
    out.reserve(n);
    ll ans = 0;
    auto go = [&](auto && dfs, int u, int d) -> void {
        sz[u] = 1;
        if (t[u].ch.empty()) {
            while(SZ(t[u].a) && SZ(t[u].b)) {
                out.eb(t[u].a.back(), t[u].b.back());
                ans += d;
                t[u].a.pop_back();
                t[u].b.pop_back();
            }
            return;
        }
        int gi = SZ(t);
        for (const auto &[k, v]: t[u].ch) {
            dfs(dfs, v, d + 1);
            sz[u] += sz[v];
            if (sz[v] > sz[gi]) gi = v;
        }
        // ixs[u] = ixs[gi];
        // cout << "Heredero " << endl;
        if (SZ(t[u].a) + SZ(t[u].b) >= SZ(t[gi].a) + SZ(t[gi].b)) {
            for (const int v: t[gi].a) t[u].a.pb(v); 
            for (const int v: t[gi].b) t[u].b.pb(v); 
            t[gi].a.clear();
            t[gi].b.clear();
        } else {
            t[u].a.swap(t[gi].a);
            t[u].b.swap(t[gi].b);
            for (const int v: t[gi].a) t[u].a.pb(v); 
            for (const int v: t[gi].b) t[u].b.pb(v); 
            t[gi].a.clear();
            t[gi].b.clear();
        }
        
        for (const auto &[k, v]: t[u].ch) if (v != gi) {
            for (const int x: t[v].a) t[u].a.pb(x); 
            for (const int x: t[v].b) t[u].b.pb(x); 
            t[v].a.clear();
            t[v].b.clear();
        }

        while(SZ(t[u].a) && SZ(t[u].b)) {
            out.eb(t[u].a.back(), t[u].b.back());
            ans += d;
            t[u].a.pop_back();
            t[u].b.pop_back();
        }
    };

    go(go, 0, 0);
    cout << ans << "\n";
    // for (const auto x: ht[ixs[0]].first) cout << x << " "; cout << "\n";
    // for (const auto x: ht[ixs[0]].second) cout << x << " "; cout << "\n";
    for (const auto &[i, d]: out) {
        cout << i + 1 << " " << d + 1 << "\n";
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