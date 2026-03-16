#include <bits/stdc++.h>
using namespace std;

#define L(i, j, n) for (int i = (j); i < (int)n; i ++)
#define SZ(x) int((x).size())
#define ALL(x) begin(x),end(x)
#define vec vector
#define pb push_back
#define eb emplace_back

#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds;
template<typename Key, typename Val=null_type>
using indexed_set = tree<Key, Val, less<Key>, rb_tree_tag,
                         tree_order_statistics_node_update>;
// indexed_set<char> s;
// char val = *s.find_by_order(0); // acceso por indice
// int idx = s.order_of_key('a'); // busca indice del valor
template<class Key,class Val=null_type>using htable=gp_hash_table<Key,Val>;
// como unordered_map (o unordered_set si Val es vacio), pero sin metodo count

using ll = long long;
using ld = long double;

using pt = pair<int, int>;
struct edge {
    int w;
    ll v;
    int cat;
    bool operator<(const edge &rhs) const {
        return v < rhs.v;
    }
};

void solve()
{
    int n; cin >> n;
    vec<pt> p;
    p.reserve(n);
    L(i,0,n){
        ll x, y; cin >> x >> y;
        p.eb(x, y);
    }
    // map<pt, set<edge>> G;
    map<ll, vec<edge>> G;
    // htable<ll, vec<edge>> ix;
    // vec<vec<edge>> G;
    const ll e10 = (ll)1e10;
    const ll e8 = (ll)1e8;
    auto hs = [](const pt &x) -> ll {
        return (e8 + x.first) * e10 + x.second;
    };
    // int MX = n * n * 8;
    // G.reserve(MX);
    int nxt = 1;
    auto add = [&](const pt u, const pt v, int k, int cat) -> void {
        ll hu = hs(u);
        ll hv = hs(v);
        G[hu].pb({k, hv, cat});
        G[hv].pb({k, hu, cat});
        // if (!ix[hs(u)]) ix[hs(u)] = nxt++, G.pb({});
        // if (!ix[hs(v)]) ix[hs(v)] = nxt++, G.pb({});
        // int uix = ix[hs(u)] - 1;
        // int vix = ix[hs(v)] - 1;
        // // cout << uix << " " << vix << " " << SZ(G) << endl;
        // G[uix].pb({k, vix, cat});
        // G[vix].pb({k, uix, cat});
    };

    auto dist = [&](const pt &a, const pt &b) -> ll {
        return abs(a.first - b.first) + abs(a.second - b.second);
    };
    L(i,0,n)
    {
        L(j,i + 1,n)
        {
            {
                pt p1 = pt{p[i].first, p[j].second};
                int kp1i = dist(p[i], p1);
                add({p[i].first, p[i].second + kp1i}, {p[i].first, p[i].second - kp1i}, kp1i, i);
                int kp1j = dist(p[j], p1);
                add({p[j].first - kp1j, p[j].second}, {p[j].first + kp1j, p[j].second}, kp1j, j);
            }
            {
                pt p2 = pt{p[j].first, p[i].second};
                int kp2i = dist(p[i], p2);
                add({p[i].first + kp2i, p[i].second}, {p[i].first - kp2i, p[i].second}, kp2i, i);
                int kp2j = dist(p[j], p2);
                add({p[j].first, p[j].second + kp2j}, {p[j].first, p[j].second - kp2j}, kp2j, j);
            }
        }
    }
    int ln = SZ(G);
    const int WHITE = 0;
    const int GRAY = 1;
    const int BLACK = 2;
    map<ll, int> vis;
    ll ans = 0;
    ll cycSum = 0;
    vec<bool> visCat(n);
    // cout << "Cyclework" << endl;
    auto go =[&](auto && dfs, const ll u, const ll par) -> bool {
        vis[u] = GRAY;
        for (const auto &[k, v, ct]: G[u]) if (v != par) {
            if (visCat[ct]) {
                vis[u] = BLACK;
                return false;
            }
            if (vis[v] == WHITE) {
                visCat[ct] = 1;
                bool cycf = dfs(dfs, v, u);
                visCat[ct] = 0;
                if (cycf) {
                    cycSum += 2LL * k;
                    vis[u] = BLACK;
                    return true;
                }
            } else if (vis[v] == GRAY) {
                // I have seen v and it's not my par
                cycSum += 2LL * k;
                vis[u] = BLACK;
                return true;
            }
        }
        vis[u] = BLACK;
        return false; // cycle
    };
    for (const auto &[u, e]: G){
        if (!vis[u]) {
            go(go, u, -1);
            ans = max(cycSum, ans);
            cycSum = 0;
        }
    }
    // L(u,0,ln) if (!vis[u]) {
    //     go(go, u, -1);
    //     ans = max(cycSum, ans);
    //     cycSum = 0;
    // }
    cout << ans << "\n";
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