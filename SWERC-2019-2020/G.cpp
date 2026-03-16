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


void solve()
{
    int s, l, n; cin >> s >> l >> n;
    map<string, int> indicesByName;
    vec<string> names(s);
    L(i, 0, s) {
        cin >> names[i];
        indicesByName[names[i]];
    }
    int ix = 0;
    for (auto [k,v]: indicesByName){ 
        indicesByName[k] = ix++;
    }
    sort(ALL(names), [&](const string &a,const  string &b) {
        return indicesByName[a] < indicesByName[b];
    });
    vec<vec<int>> adj(s, vec<int>(s));
    L(i, 0, l) {
        string a, b; cin >> a >> b;
        int u = indicesByName[a];
        int v = indicesByName[b];    
        adj[u][v] = adj[v][u] = 1;
    }
    vec<int> ord(n);
    L(i,0,n) {
        string x; cin >> x;
        ord[i] = indicesByName[x];
    }
    stable_sort(ALL(ord), [&](int a, int b){
        if (!adj[a][b]) return false;
        return a < b;
    });
    L(i,0,n) cout << names[ord[i]] << " ";
    cout << "\n";
    // input logs:
    // for(auto n: names) cout << n << '\n';
    // L(i, 0, s) cout << names[i] << ": "  << indicesByName[names[i]] << '\n';
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