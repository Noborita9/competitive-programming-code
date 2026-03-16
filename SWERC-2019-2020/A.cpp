#include <bits/stdc++.h>
using namespace std;

#define L(i,j,n) for (int i = (j);i<(int)n; i ++)
#define pb push_back
#define vec vector
#define SZ(x) int(x.size())
#define ALL(x) begin(x),end(x)
#define eb emplace_back

using ll = long long;
using ld = long double;

struct pt {
    int x, y;
};

int dist(const pt &l, const pt &r){
    return (int)ceil(hypot(l.x-r.x, l.y-r.y));
}

using iii = tuple<int, int, int>;

void solve()
{
    auto read_pt = []() -> pt {
        int x, y; cin >> x >> y;
        return pt{x, y};
    };
    pt start = read_pt();
    pt end = read_pt();
    int b; cin >> b;
    int car; cin >> car;
    int t; cin >> t;
    vec<int> c(t); 
    L(i,0,t) {
        cin >> c[i];
    }

    int n; cin >> n;
    vec<pt> st(n + 2);
    st[0] = start;
    st[n + 1] = end;
    const int oo = (int)1e9;
    vec<vec<int>> adj(n + 2, vec<int>(n + 2, oo));
    vec<vec<int>> cost(n + 2, vec<int>(n + 2, oo));
    vec<vec<int>> g(n + 2);
    g[0].pb(n + 1);
    g[n + 1].pb(0);
    adj[0][0] = adj[n+1][n+1] = 0;
    cost[0][0]=cost[n+1][n+1] = 0;
    adj[0][n + 1] = adj[n + 1][0] = dist(st[0], st[n + 1]);
    cost[0][n + 1] = cost[n + 1][0] = car * adj[0][n+1]; 
    vec<vec<array<int, 2>>> links(n);
    L(i,0,n){
        st[i + 1] = read_pt();
        adj[0][i+1] = adj[i+1][0] = dist(st[0], st[i+1]);
        adj[n+1][i+1] = adj[i+1][n+1] = dist(st[n+1], st[i+1]);
        adj[i+1][i+1] = 0;
        cost[i+1][i+1] = 0;
        L(j,0,i) {
            adj[i + 1][j + 1] = adj[j + 1][i + 1] = dist(st[i+1],st[j+1]);
        }
        int l; cin >> l;
        L(j,0,l){
            int sto, tr; cin >> sto >> tr;
            links[i].pb({sto, tr});
        }
        cost[i + 1][0] = cost[0][i + 1] = min(cost[i + 1][0], car * adj[0][i+1]);
        g[0].pb(i+1);
        g[i+1].pb(0);
        
        cost[i + 1][n+1] = cost[n+1][i + 1] = min(cost[i + 1][n+1], car * adj[n+1][i+1]);
        g[n+1].pb(i+1);
        g[i+1].pb(n+1);

        // L(k,0,n+2){
        //     L(j,0,n+2){
        //         cout << adj[k][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n\n";
    }
    L(i,0,n){
        for (auto [sto, tr]: links[i]){
            // cout << "Add link: " << i + 1 << " to " << sto + 1 << " with " << c[tr - 1] << " * " << adj[sto + 1][i + 1] << " == " << c[tr-1] * adj[sto+1][i + 1]<<"\n"; 
            cost[i + 1][sto+1] = cost[sto+1][i + 1] = min(cost[i + 1][sto+1], c[tr-1] * adj[sto+1][i + 1]); // from i to stop
            g[i+1].pb(sto+1);
            g[sto+1].pb(i+1);
        }
    }

    // L(i,0,n+2){
    //     L(j,0,n+2){
    //         cout << adj[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    

    // L(i,0,n+2){
    //     L(j,0,n+2){
    //         cout << cost[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    
    // L(i,0,n+2){
    //     for (int v: g[i]){
    //         cout << i << " -> "<< v << "\n";
    //     }
    // }
    priority_queue<iii, vec<iii>, greater<iii>> pq;
    vec<vec<int>> mcost(n + 2, vec<int>(b + 1, oo));
    mcost[0][0] = 0; // mcost[u][b] = minCost to reach u using b
    pq.push({0,0,0}); // {cost, b, u}
    // L(i,0,n+2){
    //     L(j,0,b+1){
    //         cout << mcost[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    while(SZ(pq)){
        auto [cs, bu, u] = pq.top();pq.pop();
        // cout << cs << " " << bu << " " << u << "\n";
        if (u == n + 1) { // I found the best
            break;
        }
        if (mcost[u][bu] != cs) continue; // Got better before
        for (int v: g[u]) {
            if (cost[u][v] == oo) continue;
            int nbu = bu + adj[u][v];
            if (nbu > b) continue;
            int cst = cs + cost[u][v];
            if (mcost[v][nbu] > cst) {
                mcost[v][nbu] = cst;
                // cout << "Going: " << u << " -> " << v << " w " << cst  << " having : " << cost[u][v] << " n " << nbu << "\n";
                pq.push({cst, nbu, v});
            }
        }
    }
    int best = oo;
    // L(i,0,n+2){
    //     L(j,0,b+1){
    //         cout << mcost[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    L(i,0,b + 1){
        best = min(best, mcost[n + 1][i]);
    }
    if (best == oo) cout << "-1\n";
    else cout << best << "\n";
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    // cin >> TT;
    while(TT--){
        solve();
    }
}