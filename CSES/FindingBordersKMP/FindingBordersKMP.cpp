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
        dfa[0][s[0]-'a'] = 1; // WARN: check lower_case vs upper
        L(i,1,n+1)L(c,0,26) // If complicated char set use map
            if (i<n&&s[i]=='a'+c)dfa[i][c]=i+1;
            else dfa[i][c]=dfa[p[i]][c]; // fallar en i e ir al c
    }
    int go(int v, char c){return dfa[v][c-'a'];}
};

void solve()
{
    string s; cin >> s;
    int n = SZ(s);
    KMP kmp(s);
    int v = n;
    vec<int> borders;
    do {
        v = kmp.p[v];
        if (v) borders.pb(v);
    } while(v);
    reverse(ALL(borders));
    for (int b: borders) cout << b << " "; cout << "\n";
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