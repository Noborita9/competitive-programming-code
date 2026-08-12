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

const int N = 1010;
const int ST = 55;
int dp[N][ST][ST];

struct KMP {
    string s; int n; vec<int> p; vec<vec<int>> dfa;
    KMP(string &s_): s(s_), n(SZ(s_)), p(SZ(s_) + 1), dfa(SZ(s_)+1, vec<int>(26)) {
        L(i,1,n) p[i + 1] = nxt(p[i], s[i]); // Calculate phi
    }
    int nxt(int i, char c) {for (;i;i=p[i])if(i<n&&c==s[i])return i+1; return s[0]==c;}
    void build_dfa(){
        dfa[0][s[0]-'a'] = 1; // WARN: check lower_case vs upper
        L(i,1,n+1)L(c,0,26) // If complicated char set use map
            if (i<n&&s[i]=='a'+c)dfa[i][c]=i+1;
            else dfa[i][c]=dfa[p[i]][c]; // fallar en i e ir al c
    }
    int go(int v, char c){return dfa[v][c-'a'];}
};

void solve()
{
    string c, s, t; cin >> c >> s >> t;
    int n = SZ(c);
    int p = SZ(s);
    int q = SZ(t);
    KMP ks(s), kt(t);
    ks.build_dfa();
    kt.build_dfa();
    const int oo = 1e9;
    auto go = [&](auto && r, int ix, int u, int v) -> int {
        if (ix == n){
            return 0;
        }
        if (dp[ix][u][v] != -oo) return dp[ix][u][v];
        if (c[ix] == '*'){
            L(i,0,26)
            {
                // calculate transition

                int delta = 0;
                int nu = ks.go(u, 'a' + i);
                int nv = kt.go(v, 'a' + i);
                if (nu == p) delta ++;
                if (nv == q) delta --;
                dp[ix][u][v] = max(
                    dp[ix][u][v],
                    delta + r(r, ix + 1, nu, nv)
                );
            }
        } else {    
            int nu = ks.go(u, c[ix]);
            int nv = kt.go(v, c[ix]);
            int delta = 0;
            if (nu == p) delta ++;
            if (nv == q) delta --;
            // cout << "Here" << ix << " " << u << " " << v << " " << delta << "\n";
            dp[ix][u][v] = max(
                dp[ix][u][v],
                delta + r(r, ix + 1, nu, nv)
            );   
        }
        
        return dp[ix][u][v];
    };
    L(i,0,n+1)L(j,0,ST)L(k,0,ST) dp[i][j][k] = -oo;
    // L(i,0,ST)L(j,0,ST) dp[0][i][j] = 0;
    int ans = go(go, 0, 0, 0);

    // int ans = -oo;
    // L(i,0,ST)L(j,0,ST) ans = max(ans,dp[n-1][i][j]);
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