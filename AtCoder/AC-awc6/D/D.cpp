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

using ii = pair<int,int>; // i, in/out

void solve()
{
    int n, m; cin >> n >> m;
    vec<int> l(m), r(m), ord(m);
    iota(ALL(ord),0);
    L(i,0,m) cin >> l[i] >> r[i];
    sort(ALL(ord),[&](int a, int b){return l[a] < l[b];});
    set<ii> s;
    int j = 0; // j -> l[j] <= nx
    int nx = 1; // I got to cover nx
    int op = 0;
    while (1){
        // cout << j << " " << nx << " " << op << " => " << SZ(s) << endl; 
        while (j < m && l[ord[j]] <= nx) {
            s.insert({r[ord[j]], ord[j]});
            j++;
        }
        while(SZ(s) && begin(s)->first < nx){
            s.erase(begin(s)); // does not cover
        }
        if (s.empty()) {
            break;
        }
        nx = rbegin(s)->first + 1;
        op ++;
        if (nx > n) break;
    }
    if (nx <= n) {
        cout << "-1\n";
        return;
    }
    cout << op << "\n";
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