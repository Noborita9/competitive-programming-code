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
    int cc;
    DSU(int n) :par(n), sz(n, 1), cc(n) {iota(ALL(par),0);}
    int find(int a){return a == par[a] ? a : par[a] = find(par[a]);}
    void join(int a, int b){
        a = find(a); b=find(b);
        if(a==b)return;
        if(sz[b]>sz[a])swap(a,b);
        par[b]=a;
        sz[a]+=sz[b];
        cc--;
    }
};

const ll mod = (ll)998'244'353;

void solve()
{
    int n, m; cin >> n >> m;
    DSU ds(n);
    vec<pair<int,int>> edges(m);
    L(i,0,m){
        cin >> edges[i].first >> edges[i].second;
        edges[i].first --;
        edges[i].second --;
    }
    vec<ll> p2(m + 1);
    p2[0] = 1;
    L(i,1,m + 1) p2[i] = (p2[i-1]*2ll)%mod;
    ll cost = 0;
    for (int i = m; i > 0; i --){
        auto [u, v] = edges[i - 1];
        if (ds.cc == 2) {
            // only join same component
            if (ds.find(u) != ds.find(v)) { // will reconnect graph
                cost += p2[i];
                cost %= mod;
            }
        } else {
            // always join
            ds.join(u, v);
        }
    }
    cout << cost << "\n";
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