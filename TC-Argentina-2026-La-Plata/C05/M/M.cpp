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

const int K = 20;
const int N = 2e5 + 10;
int up[K][N];

void solve()
{
    int n, m, q; cin >> n >> m >> q;
    vec<int> b(n); L(i,0,n) {int x; cin >> x; b[x - 1] = i;}
    vec<int> a(m + 1); L(i,0,m) {int x; cin >> x; a[i + 1] = b[x - 1];}
    vec<int> best(m + 1);
    vec<int> last(n);
    L(i,1,m + 1)
    {
        up[0][i] = last[(a[i] - 1 + n) % n];
        L(j,1,K) up[j][i] = up[j - 1][up[j - 1][i]];
        int bL = i;
        for (int bit = K - 1; bit >= 0; bit --) if ((n - 1) & (1 << bit))
        {
            bL = up[bit][bL];
        }
        last[a[i]] = i;
        best[i] = max(bL, best[i - 1]);
    }
    while(q--)
    {
        int l, r; cin >> l >> r;
        cout<< (best[r] >= l ? 1 : 0);
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