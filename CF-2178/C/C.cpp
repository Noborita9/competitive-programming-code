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
    vec<ll> a(n), ai(n);
    L(i,0,n) {
        cin >> a[i];
        ai[i] = -a[i];
    }
    // if (n == 2){
    //     cout << max(a[0], -a[1]) << "\n";
    //     return;
    // }
    ll post = accumulate(ALL(a), 0ll);
    post -= a[0];
    ll prev = a[0];
    ll score = max(a[0], -post);
    L(i,1,n){
        post -= a[i];
        score = max(score, prev - post); // skipping a[i]
        // cout << "Skiping: " << a[i] << " => "<< prev - post << " -> " << prev << " - " << post << "\n";
        prev += abs(a[i]);
    }    
    cout << score << "\n";
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