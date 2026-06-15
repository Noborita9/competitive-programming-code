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

const int N = 5e5 + 10;
int pref[26][N];
const int ALPHA = 26;
vec<int> pos[ALPHA][ALPHA];

void solve()
{
    int n, q; cin >> n >> q;
    string s; cin >> s;

    L(i,0,n)
    {
        L(j,0,26)
        {
            pref[j][i + 1] += pref[j][i] + (s[i] - 'a' == j);
        }
    }
    auto getPref = [&](int l, int r, int lt) -> int {
        return pref[lt][r] - pref[lt][l - 1];
    };
    L(i,1,n) {
        pos[s[i - 1] - 'a'][s[i] - 'a'].pb(i);
    }
    
    while(q--)
    {
        int l, r; cin >> l >> r;
        int freq = 1;
        vec<int> valid;
        L(j,0,ALPHA) {
            int f = getPref(l, r, j);
            if (f == freq){
                valid.pb(j);
            }else if (f > freq){
                freq = f;
                valid.clear();
                valid.pb(j);
            }
        }
        if (freq == 1){
            cout << r - l + 1 << "\n";
            continue;
        }
        vec<int> par(ALPHA), sz(ALPHA, 1);
        auto find = [&](auto && rec, int u) -> int {
            if (par[u] == u) return u;
            return par[u] = rec(rec, par[u]);
        };
        auto join = [&](int u, int v) {
            u = find(find, u);
            v = find(find, v);
            if (u == v) return;
            if (sz[v] > sz[u]) swap(u, v);
            par[v] = u;
            sz[u] += sz[v];
        };
        iota(ALL(par), 0);
        // cout << "Freq: " << freq << "\n";
        for (int i: valid)
        {
            for (int j: valid) if (i != j)
            {
                auto start = lower_bound(ALL(pos[i][j]), l);
                auto endit = upper_bound(ALL(pos[i][j]), r - 1);
                int diff = distance(start, endit);
                if (diff == freq){
                    // cout << "Using: " << (char)('a'+i) << " -> " << (char)('a'+j) << "\n";
                    join(i, j);
                }
            }
        }
        int ans = 1;
        L(i,0,ALPHA){
            ans = max(ans, sz[find(find, i)]);
        }
        cout << ans << "\n";
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