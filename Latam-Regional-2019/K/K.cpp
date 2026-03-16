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

vec<int> FFT(vec<int> a, vec<int> b){
    vec<int> res(SZ(a) + SZ(b) - 1);
    L(i,0,SZ(a)) L(j,0,SZ(b)) res[i + j] += a[i]*b[j];
    return res;
}

void solve()
{
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