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

using pii = pair<int, int>;
struct Manacher {
	vec<int> p;
	Manacher(string const& s) {
		int n = SZ(s), m = 2*n+1, l = -1, r = 1;
		vec<char> t(m); L(i, 0, n) t[2*i+1] = s[i];
		p.resize(m); L(i, 1, m) {
			if (i < r) p[i] = min(r-i, p[l+r-i]);
			while (p[i] <= i && i < m-p[i] && t[i-p[i]] == t[i+p[i]]) ++p[i];
			if (i+p[i] > r) l = i-p[i], r = i+p[i];
		}
	} // Retorna palindromos de la forma {comienzo, largo}.
	pii at(int i) const {int k = p[i]-1; return pair{i/2-k/2, k};}
	pii odd(int i) const {return at(2*i+1);} // Mayor centrado en s[i].
	pii even(int i) const {return at(2*i);} // Mayor centrado en s[i-1,i].
};

void solve()
{
    string s; cin >> s;
    int n = SZ(s);
    Manacher man(s);
    int ix = 0;
    int ln = 1;
    L(i,0,n) {
        pii odd = man.odd(i);
        pii even = man.even(i);
        if (odd.second > ln) {
            ix = odd.first;
            ln = odd.second;
        }
        if (even.second > 0 && even.second > ln) {
            ln = even.second;
            ix = even.first;
        }   
    }

    L(i,0,ln) cout << s[ix + i]; cout << "\n";
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