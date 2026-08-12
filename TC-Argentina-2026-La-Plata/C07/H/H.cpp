#include <bits/stdc++.h>
using namespace std;

#define L(i, j, n) for (int i = (j); i < (int)n; i ++)
#define SZ(x) int((x).size())
#define ALL(x) begin(x),end(x)
#define vec vector
#define pb push_back
#define eb emplace_back
#define mset(x, v) memset(x,v,sizeof(x))

using ll = long long;
using ld = long double;
const int N = 20;
const int masks = 1 << N;

const int MAXN = 45;
bool g[MAXN][MAXN];
int dp1[masks], dp2[masks];

void solve()
{
    int n, m; cin >> n >> m;
    map<string, int> M;
    int ix = 0;    
    vec<int> ppl;
    L(i,0,n)
    {
        int op; cin >> op;
        if (op == 1) {
            // make graph edges
            for (int p: ppl) {
                for (int p2: ppl) if (p != p2) {
                    g[p][p2] = g[p2][p] = 1;
                }
            }
            ppl.clear();
        } else {
            string p; cin >> p;
            if (!M[p]) M[p] = ++ix;
            ppl.pb(M[p]-1);
        }
    }
    for (int p: ppl) {
        for (int p2: ppl) if (p != p2) {
            g[p][p2] = g[p2][p] = 1;
        }
    }
    ppl.clear();
    int b1 = min(20, m);
    int lm = 1 << b1;
    int ans = 0;
    L(mask,1,lm){
        bool pos = 1;
        L(bit,0,b1) {
            if (mask & (1 << bit)) {
                L(other, bit + 1, b1) {
                    if ((mask & (1 << other)) && g[bit][other]) {
                        pos = 0;
                    }
                }
                dp1[mask] = max(dp1[mask], dp1[mask ^ (1 << bit)]);
            }
        }
        if (pos){
            // cout << bitset<4>(mask) << " " << __builtin_popcount(mask) << "\n";
            dp1[mask] = max(dp1[mask], __builtin_popcount(mask));
        }
        ans = max(dp1[mask], ans);
    }
    int b2 = min(m, m - 20);
    if (b2 <= 0) {
        cout << ans << "\n";
        return;
    }
    // cout << ans << "\n";
    int rm = 1 << b2;
    L(mask,1,rm){
        bool pos = 1;
        int cmask = (1 << 20) - 1;
        L(bit,0,b2) {
            if (mask & (1 << bit)) {
                L(other, bit + 1, b2) {
                    if ((mask & (1 << other)) && g[bit+b1][other+b1]) {
                        pos = 0;
                    }
                }
                L(other, 0, b1) if (g[other][bit + b1]) {
                    cmask = cmask & (~(1 << other));
                }
                dp2[mask] = max(dp2[mask], dp2[mask ^ (1 << bit)]);
            }
        }
        if (pos){
            // cout << bitset<4>(mask) << " " << __builtin_popcount(mask) << "\n";
            dp2[mask] = max(dp2[mask], __builtin_popcount(mask));
            ans = max(dp2[mask], ans);
            ans = max(dp2[mask] + dp1[cmask], ans);
        }
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