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

int n;
void solve()
{
    vec<int> a(n); L(i,0,n) cin >> a[i];
    vec<int> lis(n, 1);
    for (int i = n - 2; i >= 0; i --){
        for (int j = i + 1; j < n; j ++){
            if (a[i] < a[j]) {
                lis[i] = max(lis[i], 1 + lis[j]);
            }
        }
    }
    int ans = *max_element(ALL(lis));
    cout << ans << " ";
    int f = -1;
    int mx = -1;
    L(it,0,ans)
    {
        // I have to look from f + 1
        int lwst = 1e9;
        int ix = -1;
        int lval = ans - it;
        L(j, f + 1, n) {
            if (lval == lis[j] && lwst > a[j] && a[j] > mx) {
                lwst = a[j];
                ix = j;
            }
        }
        cout << ix << " ";
        f = ix;
        mx = a[ix];
    }
    cout << "\n";
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    //cin >> TT;
    while (1)
    {
        cin >> n; if (n == 0) break;
        solve();
    }
}