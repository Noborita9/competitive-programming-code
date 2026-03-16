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

template<class Char=char>vec<int> zfun(const basic_string<Char>& w) {
	int n = SZ(w), l = 0, r = 0; vec<int> z(n);
  z[0] = w.length();
	L(i, 1, n) {
		if (i <= r) {z[i] = min(r - i + 1, z[i - l]);}
		while (i + z[i] < n && w[z[i]] == w[i + z[i]]) {++z[i];}
		if (i + z[i] - 1 > r) {l = i, r = i + z[i] - 1;}
	}
	return z;
}

void solve()
{
    string s; cin >> s;
    int n = SZ(s);
    vec<int> z = zfun(s);
    KMP kmp(s);
    z[0] = 0;
    L(i,0,n) cout << z[i] << " ";
    cout << "\n";
    L(i,0,n) cout << kmp.p[i+1] << " ";
    cout << "\n";
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