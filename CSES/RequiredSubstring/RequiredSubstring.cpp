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

struct KMP {
    string s; int n; vec<int> p; vec<vec<int>> dfa;
    KMP(string &s_): s(s_), n(SZ(s_)), p(SZ(s_) + 1), dfa(SZ(s_)+1, vec<int>(26)) {
        L(i,1,n) p[i + 1] = nxt(p[i], s[i]); // Calculate phi
    }
    int nxt(int i, char c) {for (;i;i=p[i])if(i<n&&c==s[i])return i+1; return s[0]==c;}
    void build_dfa(){
        dfa[0][s[0]-'a'] = 1;
        L(i,1,n+1)L(c,0,26)
            if (i<n&&s[i]=='a'+c)dfa[i][c]=i+1;
            else dfa[i][c]=dfa[p[i]][c]; // fallar en i e ir al c
    }
    int go(int v, char c){return dfa[v][c-'a'];}
};

const ll MOD = (ll)1e9 + 7ll;

void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    int m = SZ(s);
    for (char &c: s) c=tolower(c);
    KMP kmp(s);
    kmp.build_dfa();
    // dp[i][j] = string largo i que matchea j
    vec<vec<ll>> dp(n + 1, vec<ll>(m + 1, -1));
    auto go = [&](auto && calc, int i, int v) -> ll {
        if (dp[i][v] != -1) return dp[i][v];
        if (i == n) return dp[i][v] = v == m;
        if (v == m) return dp[i][v] = (26ll * calc(calc, i + 1, v)) % MOD;
        ll ans = 0;
        L (k,0,26) (ans += calc(calc, i + 1, kmp.go(v, 'a' + k))) %= MOD;
        return dp[i][v] = ans;
    };
    ll ans = go(go, 0, 0);
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