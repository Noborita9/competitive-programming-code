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

struct trie {
    map<char, int> ch;
    bool w;
    trie(): w(0) {}
};
vec<trie> t;
void init_trie() {t.clear();t.pb(trie());}
void add_string(const string &s){
    int v = 0;
    for (const char c: s) {
        if (!t[v].ch[c]) {
            t[v].ch[c]=SZ(t);
            t.pb(trie());
        }
        v=t[v].ch[c];
    }
    t[v].w = 1;
}
int go(int v, char c){return t[v].ch[c];}

const ll MOD = (ll)1e9+7;
void solve()
{
    string s; cin >> s;
    int m; cin >> m;
    init_trie();
    L(i,0,m){
        string p; cin >> p;
        add_string(p);
    }
    int n = SZ(s);
    vec<ll> dp(n + 1);
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i --){
        int v = 0, j = 0;
        do{
            if (i + j >= n) break;
            v = go(v, s[i+j]);
            if (t[v].w) (dp[i] += dp[i + j + 1]) %= MOD;
            j ++;
        } while (v);
    }
    cout << dp[0] << "\n";
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