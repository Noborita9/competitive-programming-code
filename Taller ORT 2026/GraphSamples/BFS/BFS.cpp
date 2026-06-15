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

void solve()
{
    vector<vector<int>> adj(n); // Lista de adyancecia
    vector<bool> vis(n); // lista de visitados
    queue<int> q; // Cola FIFO
    q.push(inicio);
    vis[inicio] = true;
    while (!q.empty()){
        int nodoActual = q.front(); // Yo lo nombro u normalmente
        q.pop();
        for (int nodoVecino: adj[nodoActual]) {
            if (!vis[nodoVecino]) { // Si nadie lo vio todavia
                                    // Entonces esta en la siguiente capa
                vis[nodoVecino] = true;
                q.push(nodoVecino); // Quiero explorarlo luego
            }
        }
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