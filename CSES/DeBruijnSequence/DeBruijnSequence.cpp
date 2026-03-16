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

// Directed version (uncomment commented code for undirected)
struct edge {
    int y;
//    list<edge>::iterator rev;
    edge(int y):y(y){}
};
const int N = (1<<16);
list<edge> g[N];
void add_edge(int a, int b){
    g[a].push_front(edge(b));//auto ia=g[a].begin();
//    g[b].push_front(edge(a));auto ib=g[b].begin();
//    ia->rev=ib;ib->rev=ia;
}
vec<int> p;
void go(int x){
    while(g[x].size()){
        int y=g[x].front().y;
        //g[y].erase(g[x].front().rev);
        g[x].pop_front();
        go(y);
    }
    p.push_back(x);
}
vec<int> get_path(int x){ // get a path that begins in x
// check that a path exists from x before calling to get_path!
    p.clear();go(x);reverse(p.begin(),p.end());
    return p;
}

void solve()
{
    int n; cin >> n;
    if (n == 1){
        cout << "01\n";
        return;
    }
    int masks = 1<<(n-1);
    int submask =masks - 1;
    L(mask, 0, masks) {
        // from mask -> (mask << 1) 
        // g[mask].
        g[mask].pb((mask << 1) & submask);
        g[mask].pb(((mask << 1) | 1) & submask); // build forward

        // g[mask >> 1].pb(mask);
        // g[(mask >> 1) | (1<<(n-2))].pb(mask);
        // cout << bitset<2>(mask >> 1) << " -> " << bitset<2>(mask) << "\n";
        // cout << bitset<2>((mask >> 1) | (1<<(n-2))) << " -> " << bitset<2>(mask) << "\n";
        // cout << bitset<2>(mask) << " -> " << bitset<2>(mask >> 1) << " , " << bitset<2>((mask >> 1) | (1<<(n-2))) << "\n";
    }
    L(i,0,n - 1) cout << "0";
    // cout << "\n";
    get_path(0);
    // for (int x: p){
    //     cout << bitset<2>(x) << "\n";
    // }
    L(i,0,SZ(p) - 1){
        int to = p[i + 1];
        cout << (to & 1) << "";
    }
    cout << "\n";
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