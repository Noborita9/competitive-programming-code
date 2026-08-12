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
    vec<int> a(n); 
    const int K = 20;
    const int masks = 1 << K;
    vec<int> sor(masks), sand(masks), sandnd(masks), sandnu(masks); 
    L(i,0,n) {
        cin >> a[i];
        sor[a[i]] ++;
        sand[a[i]] ++;
    }
    L(i,0,K) {
        L(mask, 1, masks)
        {
            int cmask = (~mask) & (masks - 1);
            if (mask & (1 << i)) {
                sor[mask] += sor[mask ^ (1<< i)];
            }
            if ((mask & (1 << i)) == 0) {
                sand[mask] += sand[mask ^ (1<< i)];
            }
        }
    }
    L(i,0,n){
        cout << sor[a[i]] << " " << sand[a[i]] << " " << (n - sor[(~a[i]) & ((1<<K)-1)]) << "\n";
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