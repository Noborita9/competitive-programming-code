// #pragma GCC target ("avx2")
// #pragma GCC optimize ("Ofast")
// #pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define L(i, j, n) for (int i = (j); i < (int)n; i ++)
#define SZ(x) int((x).size())
#define ALL(x) begin(x),end(x)
#define vec vector
#define pb push_back
#define eb emplace_back

using ll = long long;
using ull = unsigned long long;
using ld = long double;

// struct ST {
//     vec<pair<int,int>> st; int k, N;
//     ST(int n): k(1), N(n) {
//         while(k<=n)k<<=1;
//         st.assign(2*k, {0,0});
//         L(i,0,k) st[i + k] = {0, i};
//         for (int i = k - 1; i ; i --) st[i] = max(st[2 * i], st[2 * i + 1]);
//     }
//     void upd(int x, int w){
//         x += k; 
//         if (st[x].first >= w) return; // just increase st[x]
//         st[x] = {w, x - k};
//         while(x >>= 1) st[x] = max(st[2 * x], st[2 * x + 1]);
//     }
//     pair<int,int> query(int l, int r) {
//         pair<int,int> mx;
//         for (l += k, r += k; l < r; l >>= 1, r >>= 1){
//             if (l & 1) mx = max(mx, st[l++]);
//             if (r & 1) mx = max(mx, st[--r]);
//         }
//         return mx;
//     }
//     void print(){
//         L(i,0,N) cout << st[i +k].first << " ";
//         cout << "\n";
//     }
// };

// static constexpr ll ms[] = {INT_MAX};
static constexpr ull b = 500'0123123;
struct StrHash { // Hash polinomial con exponentes decrecientes.
	vec<ll> hs[2], bs[2];
	StrHash(string const& s) {
		int n = SZ(s);
		L(k, 0, 1) {
			hs[k].resize(n+1), bs[k].resize(n+1, 1);
			L(i, 0, n) {
				hs[k][i+1] = (hs[k][i] * b + s[i]);
				bs[k][i+1] =  bs[k][i] * b        ;
			}
		}
	}
	inline ull get(int idx, int len) const { // Hashes en `s[idx, idx+len)`.
		ll h[2];
		L(k, 0, 1) {
			h[k] = hs[k][idx+len] - hs[k][idx] * bs[k][len];
		}   
		return h[0];
	}
};


const int N = 5005;

int nxt[N][N];
pair<int,int> suff[N][N];


void solve()
{
    string s; cin >> s;
    int n = SZ(s);
    // vec<ST> st(n, ST(n + 1)); // invoke(devil)
    StrHash hash(s);
    L(i,0,n+1)L(j,0,n+1)nxt[i][j]=-1;
    for (int j = n - 1; j >= 0; j --){
        pair<int,int> mx = {-1, -1};
        for (int i = n - 1; i >= j; i --) {
            int len = i - j + 1;
            // lexico check with the string at i + 1
            if (i + 1 == n) {
                // I am full
                suff[j][i] = {1, n};
                mx = {1, n};
            } else {
                int minLen = 1;
                int ilen = n - i - 1;
                int lo = 1; int hi = min(ilen, len);
                if (hash.get(j, len) == hash.get(i + 1, ilen)) {
                    // it's the same string so it's not possible
                    suff[j][i] = mx;
                    continue;
                }
                int clen = min(len, ilen);
                if (hash.get(j, clen) == hash.get(i + 1, clen)) {
                    if (clen != ilen) {
                        int q_idx = i + 1 + clen - 1 + 1;
                        if (q_idx < n){
                            auto [wi, pi] = suff[(i+1)] [q_idx];
                            if (wi > 0){
                                int val = wi + 1;
                                suff[j][i] = {val, i};
                                mx = max(mx, suff[j][i]);
                                nxt[j][ i] = pi;
                            }
                            
                        }
                    }
                    suff[j][i] = mx;

                    continue;
                }
                while(lo <= hi) {
                    int m = (lo + hi) / 2;
                    if (hash.get(j, m) == hash.get(i + 1, m)) {
                        // cout << "SAME: " << s.substr(j, m) << " - " << s.substr(i + 1, m) << "\n";
                        lo = m + 1;
                    } else {
                        minLen = m;
                        hi = m - 1;
                    }
                }
                // cout << "CMP: " << s.substr(j, len) << " vs " << s.substr(i + 1, ilen) << "\n";
                // cout << minLen << " == " << len << " || " << s[j+minLen - 1] << " <= " << s[i + 1 + minLen - 1] << "\n";
                if (s[j+minLen - 1] < s[i + 1 + minLen - 1] || (s[j+minLen - 1] == s[i + 1 + minLen - 1] && len < ilen)) {
                    int q_idx = i + 1 + minLen - 1 + (s[j+minLen - 1] == s[i + 1 + minLen - 1]);
                    if (q_idx < n) {
                        auto [wi, pi] = suff[(i+1)][q_idx];
                        if (wi == 0) {
                            suff[j][i] = mx;
                            continue;
                        }
                        int val = wi + 1;
                        suff[j][i] = {val, i};
                        nxt[j][i] = pi;
                        mx = max(mx, suff[j][i]);
                        suff[j][i] = mx;
                    } else {
                    suff[j][i] = mx;

                    }
                } else {
                suff[j][i] = mx;

                }
            }

        }
    }


    // L(i,0,n) cout << suff[0][i].first << " "; cout << "\n";
    
    auto [iv, it] = suff[0][0];
    int pit = 0;
    cout << iv << "\n";
    while (it != -1){
        cout << s.substr(pit, it - pit + 1) << "\n";
        int tit = it;
        it = nxt[pit][it];
        pit = tit + 1;
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