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

int n;
void solve()
{
    vec<int> a(n); L(i,0,n) {
        cin >> a[i]; a[i] *= -1;
    }
    vec<int> lis;
    lis.pb(a.back());
    vec<int> mx(n, 1);
    vec<vec<int>> ixs(n+1);
    ixs[1].pb(n-1);
    for (int i = n - 2; i >= 0; i --){
        if (a[i] > lis.back()){
            lis.pb(a[i]);
            mx[i] = SZ(lis);
        } else {
            auto it = lower_bound(ALL(lis), a[i]) - begin(lis);
            lis[it] = a[i];
            mx[i] = it + 1; // how much of a lis ends in a[i]
        }
        ixs[mx[i]].pb(i);// I end up having the lesser ones on the end of the bector
    }
    int ans = *max_element(ALL(mx));
    cout << ans << "\n";
    assert(ixs[ans].size() > 0);
    int lst = ixs[ans].back();
    cout << lst << " ";
    int lstix = lst;
    lst = a[lst];
    L(it,1,ans)
    {
        // cout << "Preget" << endl;
        // cout << lst << " >= " << a[ixs[ans - it].back()] << endl;
        while (lst >= a[ixs[ans - it].back()] && lstix >= ixs[ans-it].back()) {
            ixs[ans-it].pop_back();
        }
        // cout << "Preprint" << endl;
        lst = ixs[ans-it].back();
        cout << lst << " ";
        lstix = lst;
        lst = a[lst];
    }
    cout << "\n";
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 64;
    //cin >> TT;
    while (TT--)
    {
        cin >> n;
        if (!cin.good() || cin.eof()) break;
        solve();
    }
}