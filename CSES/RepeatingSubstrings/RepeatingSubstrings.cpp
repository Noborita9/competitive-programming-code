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

static constexpr ll ms[] = {1'000'000'007, 1'000'000'403};
static constexpr ll b = 500'000'000;
struct StrHash { // Hash polinomial con exponentes decrecientes.
	vec<ll> hs[2], bs[2];
	StrHash(string const& s) {
		int n = SZ(s);
		L(k, 0, 2) {
			hs[k].resize(n+1), bs[k].resize(n+1, 1);
			L(i, 0, n) {
				hs[k][i+1] = (hs[k][i] * b + s[i]) % ms[k];
				bs[k][i+1] =  bs[k][i] * b         % ms[k];
			}
		}
	}
	ll get(int idx, int len) const { // Hashes en `s[idx, idx+len)`.
		ll h[2];
		L(k, 0, 2) {
			h[k] = hs[k][idx+len] - hs[k][idx] * bs[k][len] % ms[k];
			if (h[k] < 0) h[k] += ms[k];
		}
		return (h[0] << 32) | h[1];
	}
};

void solve()
{
    string s; cin >> s;
    int n = SZ(s);
    StrHash hs(s);
    int lo = 1;
    int hi = n - 1;
    int ans = -1; // index
    int len = 0;
    // with lo

    auto check = [&](int l) -> int {
        unordered_map<ll, int> M;
        int ans = -1;
        L(i,0,n){
            if (i + l - 1 >= n) break;
            ll h = hs.get(i, l);
            if (M[h]) {
                return M[h] - 1;
            } 
            M[h] = i + 1;
        }
        return ans;
    };

    while (lo <= hi){
        int m = (lo + hi) / 2;
        int r = check(m);
        if (r == -1) {
            hi = m - 1;
        } else {
            ans = r;
            len = m;
            lo = m + 1;
        }
    }

    if (ans == -1) {
        cout << "-1\n";
    } else {
        L(i,0,len) {
            cout << s[ans + i];
        }
        cout << "\n";
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