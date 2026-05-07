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

bitset<30010> dp;
void solve()
{
    int n; cin >> n;
    vec<int> out(n);
    map<int,int> v;
    v[2] = 2;
    v[3] = 3;
    v[4] = 4;
    v[5] = 5;
    v[6] = 5;
    v[7] = 7;
    v[8] = 6;
    v[9] = 6;
    v[10] = 7;
    bool all1 = true;
    vec<int> a(n);
    int sm = 0;
    vec<vec<int>> pos(11);
    L(i,0,n){
        cin >> a[i];
        all1 = all1 && a[i] == 1;
        
        if (a[i] != 1) {
            sm += v[a[i]];
            pos[a[i]].pb(i);
        }
    }
    if (all1){
        cout << "POSSIBLE\n";
        cout << 1;
        L(i,0,n-1)cout<<0;
        cout << "\n";
        return;
    }
    if (sm % 2 != 0) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    dp[0] = 1;
    int ln = sm / 2;
    vec<int> prev(ln + 1, -1);
    L(i,0,n) if (a[i] != 1){
        if (dp[ln]) break;
        int d = v[a[i]];
        for (int j = ln; j >= d; j --) if (!dp[j]) {
            if (dp[j - d]) {
                dp[j] = 1;
                prev[j] = i;
            }
        }
    }
    if (!dp[ln]){
        cout << "IMPOSSIBLE\n";
        return;
    }
    int f = ln;
    while(f>0){
        int x = prev[f];
        f -= v[a[x]];
        out[x] = 1;
    }
    cout << "POSSIBLE\n";
    L(i,0,n) cout << out[i]; cout << "\n";
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