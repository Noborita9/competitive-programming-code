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

const ll mod = 998'244'353;
inline ll modsum(ll a, ll b){
    a += b;
    if ( a >= mod) a -= mod;
    return a;
}
inline ll modmul(ll a, ll b){
    a *= b;
    if (a >= mod) a %= mod;
    return a;
}

ll binPow(ll a,ll b){
    ll r = 1;
    while(b>0){
        if (b&1) r = r * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return r;
}

void solve()
{
    int n, k; cin >> n >> k;
    vec<ll> A(n + 1); // how many double palindromes
    L(i,1,n + 1){
        if (i & 1){
            A[i] = (1LL * i * binPow(k, (i + 1) / 2)) % mod;
        } else {
            ll m = i / 2;
            ll p = binPow(k, m);
            A[i] = (m * p) % mod;
            A[i] = (A[i] + (m * ((p * k)%mod)) % mod) % mod;
        }
    }

    for (int i = 1; i <= n; i ++){
        for (int j = 2 * i; j <= n; j += i){
            ll minus = (1LL * (j / i) * A[i]) % mod;
            A[j] = (A[j] - minus + mod) % mod;
        }
    }

    ll ans = 0;

    for (int i = 1; i <= n; i ++){
        ll times = n / i; // how many times this happens
        ans = (ans + (times * A[i]) % mod) % mod;
    }
    cout << ans << "\n";
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