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
    int n, k; cin >> n >> k;
    vec<vec<string>> s(n);
    L(i,0,n){
        int m; cin >> m;
        s[i].reserve(m);
        L(j,0,m){
            string x; cin >> x;
            s[i].pb(x);
        }
    }
    int pairs =0;
    L(i,0,n){
        L(j,i+1,n){
            int tot = 0;
            for (const string &l: s[i]) {
                for (const string &r: s[j]) {
                tot += l == r;
                if (tot == k) break;
            }
            if (tot == k) break;
            }
            if (tot == k) pairs++;
        }
    }
    cout << pairs << "\n";
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