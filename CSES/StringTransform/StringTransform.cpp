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
    string s; cin >> s;
    int n = SZ(s);
    vec<int> nxt(n);
    iota(ALL(nxt), 0);
    stable_sort(ALL(nxt), [&](int l, int r){return s[l] < s[r];});
    int j = nxt[0];
    vec<char> out(n);
    L(i,0,n-1){
        j=nxt[j];
        cout << s[j];
    }
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