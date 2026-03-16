#include <bits/stdc++.h>
using namespace std;

#define L(i,j,n) for (int i = (j); i < (int)n; i ++)
#define pb push_back
#define SZ(x) int(x.size())
#define ALL(x) begin(x),end(x)
#define vec vector

using ll = long long;
using ld = long double;

template<class T>void imp(vec<T> out){
    for (T o: out) cout << o << " ";
    cout << "\n";
}

vec<int> zfun(const string &w){
    int n = SZ(w), l = 0, r = 0; vec<int> z(n);
    z[0] = n;
    L(i, 1, n){
        if (i <= r) {z[i] = min(r - i + 1, z[i - l]);}
        while(i + z[i] < n && w[z[i]] == w[i + z[i]]) {z[i]++;}
        if (i + z[i] - 1 > r) {
            l = i, r = i +z[i] - 1;
        }
    }
    return z;
}

void solve()
{
    string a, b; cin >> a >> b;
    int n = SZ(b);
    int m = SZ(a);
    vec<int> phi(n);
    L(i, 1, n){
        int j = phi[i - 1];
        while(j > 0 && b[i] != b[j]) j = phi[j - 1];
        if (b[i] == b[j]) j ++;
        phi[i] = j;
    }
    string p = b + "$" + a;
    // imp(phi);
    vec<int> z = zfun(p);
    // cout << p << "\n";
    // imp(z);
    vec<int> lens(n + 1);
    L(i, n + 1, SZ(z)) {
        if (z[i]) lens[z[i]] ++;
    }
    for (int i = n - 1; i >= 0; i --){
        lens[i] += lens[i + 1];
    }

    vec<ll> ans(n, -1);
    auto go = [](ll k){
        return (k * (k + 1))/ 2ll;
    };
    auto calc = [&](auto && dp, int u) -> ll {
        // cout << u << "\n";
        if (ans[u] != -1) return ans[u];
        if (phi[u] == 0) {
            return ans[u] = go(lens[u + 1]) * (u + 1);
        }
        return ans[u] = dp(dp, phi[u] - 1);
    };
    L(i,0,n){
        ll ans = calc(calc, i);
        // cout << "Calc: " << ans << "\n";
        cout << ans << " ";
    }    
    cout << "\n";
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    cin >> TT;
    while(TT--)
    {
        solve();
    }
}