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

#define RB(x) ((x) < n ? r[x] : 0)
void csort(vec<int>& sa, vec<int>& r, int k) {
	int n = SZ(sa);
	vec<int> f(max(255, n)), t(n);
	L(i,0, n) ++f[RB(i+k)];
	int sum = 0;
	L(i,0, max(255, n)) f[i] = (sum += f[i]) - f[i];
	L(i,0, n) t[f[RB(sa[i]+k)]++] = sa[i];
	sa = t;
}
vec<int> compute_sa(string& s){ // O(n*log2(n))
	int n = SZ(s) + 1, rank;
	vec<int> sa(n), r(n), t(n);
	iota(ALL(sa), 0);
	L(i,0, n) r[i] = s[i];
	for (int k = 1; k < n; k *= 2) {
		csort(sa, r, k), csort(sa, r, 0);
		t[sa[0]] = rank = 0;
		L(i, 1, n) {
			if(r[sa[i]] != r[sa[i-1]] || RB(sa[i]+k) != RB(sa[i-1]+k)) ++rank;
			t[sa[i]] = rank;
		}
		r = t;
		if (r[sa[n-1]] == n-1) break;
	}
	return sa; // sa[i] = i-th suffix of s in lexicographical order
}
vec<int> compute_lcp(string& s, vec<int>& sa){
	int n = SZ(s) + 1, K = 0;
	vec<int> lcp(n), plcp(n), phi(n);
	phi[sa[0]] = -1;
	L(i, 1, n) phi[sa[i]] = sa[i-1];
	L(i,0,n) {
		if (phi[i] < 0) { plcp[i] = 0; continue; }
		while(s[i+K] == s[phi[i]+K]) ++K;
		plcp[i] = K;
		K = max(K - 1, 0);
	}
	L(i,0, n) lcp[i] = plcp[sa[i]];
	return lcp; // lcp[i] = longest common prefix between sa[i-1] and sa[i]
}

void solve()
{
    string s; cin >> s;
    int n = SZ(s);
    vec<int> sa = compute_sa(s);
    vec<int> lcp = compute_lcp(s, sa);
    vec<ll> cnt(n + 3);
    L(i, 1, n + 1) {
        cnt[lcp[i] + 1]++;
        int ln = n - sa[i];
        cnt[ln + 1] --;
    }
    L(i,1,n+1){
        cnt[i] += cnt[i - 1];
        cout << cnt[i] << " ";
    }
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