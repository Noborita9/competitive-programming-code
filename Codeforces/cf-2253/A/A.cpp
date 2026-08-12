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

const int N = 2e5 + 10;
bool p[N];

void solve()
{
    int n; cin >> n;
    cout << (!p[n + 1] ? "YES" : "NO") << "\n";
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    cin >> TT;
    for (int i = 2; i < N; i ++) {
        if (p[i]) continue;
        for (int j = i + i; j < N; j += i) p[j] = 1;
    }
    while (TT--)
    {
        solve();
    }
}