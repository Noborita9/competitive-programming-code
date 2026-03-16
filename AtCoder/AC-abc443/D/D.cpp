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
    vec<ll> a(n);
    L(i,0,n) {
        cin >> a[i];
        a[i] = n - a[i];
    }
    ll tot = 0;
    vec<ll> out(n);
    vec<int> vis(n);
    vec<vec<int>> q(n + 1);
    L(i,0,n) q[a[i]].pb(i);
    for (int i = n; i >= 1; i --){
        queue<int> qp;
        for (int j: q[i]) if (!vis[j]) {
            qp.push(j);
            vis[j] = 1;
        }
        while(SZ(qp)){
            int u = qp.front(); qp.pop();
            out[u] = i;
            int nx = u + 1;
            if (nx < n && !vis[nx]) {
                q[i - 1].pb(nx);
            }
            int pv = u - 1;
            if (pv >= 0 && !vis[pv]) {
                q[i - 1].pb(pv);
            }
        }
    }
    L(i,0,n){
        tot += out[i] - a[i];
    }
    // L(i,0,n) cout << out[i] << " "; cout << "\n"
    cout << tot << "\n";
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