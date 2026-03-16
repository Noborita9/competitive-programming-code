#include <bits/stdc++.h>
using namespace std;

#define L(i,j,n) for (int i = (j);i<(int)n; i ++)
#define pb push_back
#define vec vector
#define SZ(x) int(x.size())
#define ALL(x) begin(x),end(x)
#define eb emplace_back

using ll = long long;
using ld = long double;


void solve()
{
    int n; cin >> n;
    map<string, int> M;
    L(i,0,n){
        string s; cin >> s;
        M[s]++;
    }
    string best = "NONE";
    int tms = 0;
    for (const auto [k, v]: M){
        if (v > n - v) {
            best = k;
            tms = v;
        }
    }
    cout << best << "\n";
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    // cin >> TT;
    while(TT--){
        solve();
    }
}