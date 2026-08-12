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

const int N = 8010;
vec<short> pos(N + 1, - 1);
int TT = 1;
void solve()
{
    int n; cin >> n;
    vec<short> a(n);
    L(i,0,n) cin >> a[i];
    auto mark = [&](int x) {
        if (x > n) return;
        pos[x] = TT;
    };
    L(len,2,n+1){
        int sm = 0;
        L(i,0,len) sm += a[i];
        mark(sm);
        L(i,len,n){
            sm -= a[i-len];
            sm += a[i];
            mark(sm);
        }
    }
    int ans = 0;
    L(i,0,n) ans += pos[a[i]]==TT;
    cout << ans << "\n";
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> TT;
    while (TT--)
    {
        solve();
    }
}