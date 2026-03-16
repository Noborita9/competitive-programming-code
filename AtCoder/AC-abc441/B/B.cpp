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
    string s, t; cin >> s >> t;
    vec<int> st(260), tt(260);
    for (char c: s) st[c] = 1;
    for (char c: t) tt[c] = 1;
    int q; cin >> q;
    while(q--)
    {
        string p ; cin >> p;
        bool tak = true;
        for (char c: p) {
            tak = tak && st[c];
        }
        
        bool ao = true;
        for (char c: p){
            ao = ao && tt[c];
        }
        if (ao == tak) {
            cout << "Unknown\n";
        } else if (ao) {
            cout << "Aoki\n";
        } else {

            cout << "Takahashi\n";
        }
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