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

const ll MOD = (ll)1e9+7ll;
ll modmul(ll a, ll b){
    a*=b;
    if (a>=MOD)a%=MOD;
    return a;
}
ll modsum(ll a,ll b){
    a+= b;
    if (a>=MOD)a%=MOD;
    return a;
}
ll modminus(ll a, ll b){
    return (((a-b)%MOD)+MOD)%MOD;
}

void solve()
{
    string s; cin >> s;
    int n = SZ(s);
    vec<ll> dp(n + 1, 0);
    vec<ll> dpL(26); // per letter
    vec<int> a(n+1); L(i,0,n)a[i+1]=s[i]-'a';
    dp[0] = 1;
    L(i,1,n+1){
        dp[i] = modminus(modmul(dp[i-1],2),dpL[a[i]]);
        dpL[a[i]] = dp[i-1];
    }
    dp[n] = modminus(dp[n], 1);
    cout << dp[n] << "\n";
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