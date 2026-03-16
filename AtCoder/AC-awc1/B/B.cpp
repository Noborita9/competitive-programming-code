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
    int n, l, r; cin >> n >> l >> r;
    int id = 1e9;
    int score = 0;
    L(i,0,n){
        int x; cin >> x;
        if (l <= x && x <= r) {
            if (score == x) id=min(id, i + 1);
            if (score < x) {
                id = i + 1;
                score = x;
            }
        }
    }
    if (id == 1e9) {
        cout << "-1\n";
        return;
    }
    cout << id << "\n";
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