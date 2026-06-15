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
    ll n, s, t, k; cin >> n >> s >> t >> k;
    if (n <= 3){
        cout << "1\n";
        return;
    }
    if (t < s) swap(s, t);
    // cout <<"From: " << s << " " << t << "\n";
    ll distL = t - s;
    ll distR = n - t + s;
    // cout << distL << " " << distR << "\n";
    ll dist = min(distL, distR);
    // cout << dist << "\n";
    cout << k + dist << "\n";
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