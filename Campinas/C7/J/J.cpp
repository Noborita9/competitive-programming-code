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
    vec<int> back(n + 2);
    vec<int> a(n + 1);
    L(i,0,n){
        cin >> a[i + 1];
        back[a[i + 1]] = i + 1;
    }
    vec<int>out(n + 1);
    int c = 0;

    L(i, 2, n + 1){
        if (back[a[i] + 1] < back[a[i - 1] + 1]) c ++;
        out[a[i]] = c;
    }
    if (c >= 26) {
        cout << "-1\n";
        return;
    }
    L(i, 1, n + 1) cout << (char)(out[i] + 'a');
    cout << "\n";
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