#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
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
void solve(){
    ll x; cin >> x;
    int d3 = 0;
    int d2 = 0;
    ll t = x;
    while (t % 3 == 0) d3++, t/=3;
    while (t % 2 == 0) d2++, t/=2;
    if (t > 1 || d2 > d3) return void(cout << "-1\n");
    cout << d3 + (d3 - d2) << "\n";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    cin >> TT;
    while (TT--) {solve();}
}
// IF NEEDED FOR FILE READ
// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);