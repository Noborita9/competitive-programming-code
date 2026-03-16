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
    int n, q; cin >> n >> q;
    vec<int> a(n);
    L(i,0,n) cin >> a[i];
    multiset<int> M;
    L(i,0,n) M.insert(a[i]);
    L(qi,0,q){
        int k; cin >> k;
        vec<int> p(k);
        L(i,0,k){
            int x; cin >> x;
            x --;
            p[i] = a[x];
            M.erase(M.find(p[i]));
        }
        cout << *begin(M) << "\n";
        L(i,0,k) M.insert(p[i]);
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