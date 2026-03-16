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

const int N = 1e7 + 10;
using ii = pair<ll, ll>;
ll mx[2][N];

const ll mod = (ll)998'244'353ll;
ll binPow(ll a, ll b) {
    ll r = 1;
    while(b>0){
        if(b&1) r = (r * a) % mod;
        a = (a*a)%mod;
        b>>=1;
    }
    return r;
}
ll divi(ll a, ll b){
    return a * binPow(b, mod - 2) % mod;
}

void solve()
{
    int n; cin >> n;
    vec<ll> a(n);
    L(i,0,n) cin >> a[i];
    vec<vec<ii>> pm(n);
    set<ll> pms;
    L(j,0,n){
        ll t = a[j];
        for (ll i = 2; i * i <= t; i ++){
            if (t % i == 0){
                pm[j].pb({i, 0});
                while(t % i == 0){
                    t /= i;
                    pm[j].back().second ++;
                }
            }
        }
        if (t > 1) {
            pm[j].pb({t, 1});
        }
    }
    ll lm = 1;
    L(i,0,n){
        for (const auto [v, x]: pm[i]) {
            if (mx[1][v] < x) mx[1][v] = x;
            if (mx[0][v] < mx[1][v]) swap(mx[0][v], mx[1][v]);
            pms.insert(v);
        }
    }

    for (const ll pr: pms) {
        lm = (lm * binPow(pr, mx[0][pr])) % mod; // Esto forma el LCM modulo mod
    }
    // ahora tengo que probar por cada uno sacarlo
    L(i,0,n){
        ll nlm = lm; // So i don't need to restore
        for (const auto [v, x]: pm[i]) {
            ll use = mx[0][v] == x ? mx[1][v] : mx[0][v];
            nlm = divi(nlm, binPow(v, mx[0][v]));
            nlm = nlm * binPow(v, use) % mod;            
        }
        cout << nlm << " ";
    }
    cout << "\n";
    L(i,0,n){
        for (const auto [v, x]: pm[i]) {
            mx[0][v] = mx[1][v] = 0;
        }
    }
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