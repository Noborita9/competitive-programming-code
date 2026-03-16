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
    int n; cin >> n;
    int df = 0;
    map<int, int> M; // M[delta] = max(ix)
    string s; cin >> s;
    L(i,0,n){
        if (s[i] == 'a') df ++;
        else df --;
    }
    if (df == 0){
        cout << "0\n";
        return;
    }
    int tg = df; // I need to remove that much
    int ans = n + 1;
    int ac = 0;
    // cout << "Got: " << tg << "\n";
    M[0] = 0;
    L(i,0,n){
        if (s[i] == 'a') ac ++;
        else ac --;
        // cout << ac << " - " << ac - df << "\n";
        if (M.count(ac - df)) {
            ans = min(ans, (i + 1) - M[ac - df]);
        }
        M[ac] = i + 1;
    }
    if (ans >= n){
        cout << "-1\n";
        return;
    }
    cout << ans << "\n";
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
    }
}