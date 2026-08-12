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

int s;
void solve()
{
    int best = 0;
    vec<int> bset;
    int n; cin >> n;
    while(n--)
    {
        int k; cin >> k;
        vec<int> c(k); L(i,0,k) cin >> c[i];
        int sm = *max_element(ALL(c)) * s;
        vec<vec<bool>> dp(s+1, vec<bool>(sm + 1));
        L(i,0,s+1)dp[i][0] = 1;
        L(p, 0, sm + 1) {
            L(si, 1, s + 1) {
                L(j,0,k){
                    int v = c[j];
                    if (p - v < 0) break;
                    dp[si][p] = (dp[si][p] || dp[si - 1][p - v]);
                }
            }
        }
        int kacc = 0;
        L(i,1,sm + 1) {
            bool pos = 0;
            L(j,0,s+1) pos = pos || dp[j][i];
            if (!pos) break;
            kacc = i;
        }
        // cout << kacc << "\n";
        if (kacc > best) {
            best = kacc;
            bset.swap(c);
        } else if (kacc == best) {
            if (SZ(c) < SZ(bset)){
                bset.swap(c);
            } else if (SZ(c) == SZ(bset))
            {
                bool swap = false;
                for (int i = k - 1; i >= 0; i --){
                    if (bset[i] < c[i]) break;
                    if (c[i] < bset[i]) {
                        swap = true;
                    }
                }
                if (swap) bset.swap(c);
            }
        }
    }

    cout << "max coverage = "<< setw(3) << best << " :";
    int ln = SZ(bset);
    L(i,0,ln) {
        cout << setw(3) << bset[i];
    }
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 0;
    //cin >> TT;
    while (1)
    {
        cin >> s;
        if (s == 0) break;
        solve();
        cout << "\n";
    }
}