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
    vec<int> w(n + 2); L(i,0,n) cin >> w[i + 1];
    auto check = [&](int k) -> bool {
        vec<int> a(n + 2);
        L(i,1,n+1){
            if (w[i] == k) return false;
            if (w[i] > k) a[i + 1] ++;
            if (w[i] < k) a[i - 1] ++;
        }
        L(i,1,n+1) if (a[i] != 1) return false;
        return true;
    };
    L(i,1,n+1){
        if (check(w[i] - 1) || check(w[i] + 1))
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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