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
    int n, m; cin >> n >> m;
    if (m > n) {
        cout << "No\n";
        return;
    }
    vec<int> l(m), r(m), ord(m);
    L(i,0,m){
        cin >> l[i] >> r[i];
        l[i] --; r[i] --;
        ord[i] = i;
    }
    sort(ALL(ord), [&](int a, int b) {
        if (r[a] != r[b]) return r[a] < r[b];
        return l[a] < l[b];
    });
    set<int> slots;
    L(i,0,n) slots.insert(i);
    L(i,0,m)
    {
        int u = ord[i];
        auto it = slots.lower_bound(l[u]);
        if (it == end(slots) || *it > r[u]) {
            cout << "No\n";
            return;
        }
        slots.erase(it);
    }

    cout << "Yes\n";
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