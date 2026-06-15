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

struct DSU {
    vec<int> par, sz;
    DSU(int n): par(n), sz(n, 1) {iota(ALL(par), 0);}
    int find(int a){return a == par[a] ? a : par[a] = find(par[a]);}
    void join(int a, int b){
        a=find(a);b=find(b);
        if(a==b)return;
        if(sz[b]>sz[a])swap(a,b);
        par[b]=a;
        sz[a]+=sz[b];
    }
};

using ii = pair<int,int>;
using iii = tuple<ll, int, int>;

void solve()
{
    int n;  cin >> n;
    DSU ds(n + 1);
    vec<ii> p; p.reserve(n);
    p.eb(0,0);
    L(i,0,n) {
        ll x, y; cin >> x >> y;
        p.eb(x, y);
    }  
    vec<ll> c(n + 1), k(n + 1);
    L(i,1,n+1)cin >> c[i];
    L(i,1,n+1)cin >> k[i];

    vec<iii> E; E.reserve(((n + 1) * (n + 2)) / 2);
    
    L(i,1,n+1){
        E.emplace_back(c[i], 0, i);
        L(j,i+1,n+1)
        {
            ll dist = abs(p[i].first - p[j].first) + abs(p[i].second - p[j].second);
            ll price = k[i] + k[j];
            E.emplace_back(dist * price, i, j);
        }
    }
    sort(ALL(E));
    int edges = 0;
    ll ans = 0;
    vec<int> g;
    vec<ii> conn;
    for (const auto &[w, i, j]: E){
        if (ds.find(i) == ds.find(j)) continue;
        ds.join(i, j);
        if (i != 0 && j != 0) {
            conn.eb(i, j);
        } else g.eb(j);
        ans += w;
        if (++edges == n) break;
    }
    cout << ans << "\n";
    cout << SZ(g) << "\n";
    for (int gi: g) cout << gi << " "; cout << "\n";
    cout << SZ(conn) << "\n";
    for (auto [l, r]: conn) cout << l << " " << r << "\n";
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