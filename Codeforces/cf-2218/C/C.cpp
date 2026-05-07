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
    int n; cin >> n;
    vec<int> out(3 * n);
    int it = 3 * n;
    int sm = 0;
    L(i,0,n){
        int a = 3 * i;
        int b = a + 1;
        int c = a + 2;
        out[a] = i + 1;
        out[c] = it --;
        out[b] = it --;
        sm += out[b];
    }

    for (int o: out) cout << o << " ";
    cout << "\n";
    // cout << "Sums: " << sm << "\n";
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
    }
}