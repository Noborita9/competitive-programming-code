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

const int BLOCK_SIZE = 475;


void solve()
{
    int n, m; cin >> n >> m;
    vec<int> x(n), y(n); L(i,0,n) cin >> x[i] >> y[i];

    vec<vec<int>> mat(BLOCK_SIZE, vec<int>(BLOCK_SIZE));
    
    vec<int> delta(m + 10);
    int curDelta = 0;
    vec<int> last(n);
    L(t,0,m)
    {
        int op, k; cin >> op >> k;
        curDelta += delta[t];
        k --;
        if (op == 1) {
            // add
            if (x[k] + y[k] < BLOCK_SIZE) {
                L(j,0, y[k]) mat[x[k] + y[k]][(t + x[k] + j) % (x[k] + y[k])]++;
            } else {
                int ct = t + x[k];
                while(true) {
                    if (ct > m) break;
                    delta[ct] ++;
                    ct += y[k];
                    if (ct > m) break;
                    delta[ct] --;
                    ct += x[k];
                }
            }
            last[k] = t;
            // L()
        } else {
            // remove
            if (x[k] + y[k] < BLOCK_SIZE) {
                L(j,0, y[k]) mat[x[k] + y[k]][(last[k] + x[k] + j) % (x[k] + y[k])]--;
            } else {
                int ct = last[k] + x[k];
                while(true) {
                    if (ct > m) break;
                    delta[ct] --;
                    if (ct <= t && t < ct + y[k]) curDelta --;
                    ct += y[k];
                    if (ct > m) break;
                    delta[ct] ++;
                    ct += x[k];
                }
            }
        }

        // ans query
        int ans = curDelta;
        L(i,1,BLOCK_SIZE) ans += mat[i][t % i];
        cout << ans << "\n";
    }
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