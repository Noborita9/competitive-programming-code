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

const int N = 1e6 + 10;
const ll oo = (ll)1e18;

vec<ll> pms;

void solve()
{
    int n; cin >> n;
    L(i,0,n){
        cout << (pms[i]*pms[i+1]) << " ";
    }
    cout << "\n";
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    cin >> TT;
    vec<int> crib(N);
    L(i,2,N){
        if (crib[i]) continue;
        for(int j = 2 * i; j < N; j += i) crib[j]=1;
        pms.pb(i);
    }
    // cout << SZ(pms) << endl;
    while (TT--)
    {
        solve();
    }
}