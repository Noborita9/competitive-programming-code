#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
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

const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

void solve(){
    int n,m;
    cin >> n >> m;
    vec<vec<int>> g(n);
    vec<int> vi(n, WHITE);
    L(i,0,m){
        int u,v;cin>>u>>v;
        u--;v--;
        g[u].pb(v);g[v].pb(u);
    }
    vec<int> cyc_path;
    auto cycle = [&](auto && dfs, int u, int par) -> bool {
        vi[u] = GRAY;
        for (int v: g[u]) if (v != par && vi[v] != BLACK) {
            if (vi[v] == WHITE) {
                // antes de ir
                if (dfs(dfs, v, u)) { // estoy en el ciclo
                    cyc_path.pb(u); // me agrego al ciclos
                    if (u == cyc_path[0]) {
                        // Ya no tengo que agregar mas nada
                        return false;
                    }
                    vi[u] = BLACK; // Termine de procesar
                    return true;
                }
                // sino
            } else if (vi[v] == GRAY && cyc_path.empty()) { // Para no encontrar 2 ciclos tengo que chequear que no complete uno
                cyc_path.pb(v);
                cyc_path.pb(u);
                vi[u] = BLACK;
                return true;
            }
        }
        vi[u] = BLACK;
        return false;
    };

    L(i,0,n) if (vi[i] == WHITE) {
        cycle(cycle, i, - 1);
        if (SZ(cyc_path)) {
            cout << SZ(cyc_path) << "\n";
            for (int nodo: cyc_path) {
                cout << nodo+1 << " ";
            }
            cout << "\n";
            return;
        }
    }
    cout << "IMPOSSIBLE" << '\n';
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    //cin >> TT;
    while (TT--) {solve();}
}
// IF NEEDED FOR FILE READ
// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);