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

const ll mod = (ll)998244353;

ll bpow(ll a, ll b){
    ll res = 1;
    a %= mod;
    while(b>0){
        if (b&1) res = res * a % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
ll divi(ll a, ll b){
    return a * bpow(b, mod - 2) % mod;
}

inline ll modsum(ll a, ll b){
    a += b; if (a >= mod) a-=mod; return a;
}
inline ll modmin(ll a,ll b){
    a -= b;
    if (a < 0) a += mod;
    return a;
}
inline ll modmul(ll a, ll b){
    return a * b % mod;
}


void solve()
{
    int n; cin >> n;
    vec<ll> a(n); L(i,0,n) cin >> a[i];
    vec<ll> h(n + 1);
    h[1] = 1;
    L(i,1, n + 1) h[i] = modsum(h[i - 1], divi(1, i));
    vec<ll>w(n);
    w[0] = h[n];
    L(i,1,n) w[i] = modsum(w[i - 1], modmin(h[n - i], h[i]));
    ll ans = 0;
    L(i,0,n) {
        ans = modsum(ans, modmul(w[i], a[i]));
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