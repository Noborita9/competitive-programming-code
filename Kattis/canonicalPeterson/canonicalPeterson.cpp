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
    vec<int> c(n); L(i,0,n) cin >> c[i];
    reverse(ALL(c));
    bool cano = true;
    auto greedy = [&](int x) -> vec<int> {
        vec<int> coins(n + 1);
        L(i,0,n){
            int tms = x / c[i];
            x -= tms * c[i];
            coins[i] += tms;
            coins[n] += tms;
        }
        return coins;
    };
    L(i,1,n)
    {
        int tv = c[i - 1] - 1;
        vec<int> coins = greedy(tv);
        L(j,i,n)
        {
            int ntv = c[j];
            int usedCoins = 1;
            L(p,0, j + 1){
                ntv += coins[p] * c[p];
                usedCoins += coins[p];
            }
            vec<int> ncoins = greedy(ntv);
            if (usedCoins < ncoins[n]) {
                cano = false;
                break;
            }
        }
        if (!cano) break;
    }
    
    if (!cano) cout << "non-";
    cout << "canonical\n";
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