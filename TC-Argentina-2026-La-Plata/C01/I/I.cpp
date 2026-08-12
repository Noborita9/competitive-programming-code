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

void solve()
{
    int n, m, q; cin >> n >> m >> q;
    vec<int> w(n); L(i,0,n) cin >> w[i];
    const int masks = 1 << n;
    vec<int> ap(masks);
    L(i,0,m){
        string s; cin >> s;
        int x = 0;
        L(j,0,n) if (s[j] == '1') x |= 1 << j;
        ap[x] ++;
    }
    vec<int> ans(q);
    vec<vec<pair<int,int>>> qs(masks);
    L(i,0,q)
    {
        string s; cin >> s;
        int x = 0;
        L(j,0,n) if (s[j] == '1') x |= 1 << j;
        int k; cin >> k;
        qs[x].eb(i, k);
    }

    L(mask, 0, masks)
    {
        if (qs[mask].empty()) continue;
        vec<int> occ(101);
        L(omask, 0, masks)
        {
            int dt = 0;
            L(j,0,n) if ((mask & (1<<j)) == (omask & (1<<j))) 
            {
                dt += w[j];
            }
            if (dt <= 100) {
                occ[dt] += ap[omask];
            }
        }
        L(i,1,101) occ[i] += occ[i - 1];
        for (const auto &[ix, k]: qs[mask]) ans[ix] = occ[k];
    }

    L(i,0,q) cout << ans[i] << "\n";
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