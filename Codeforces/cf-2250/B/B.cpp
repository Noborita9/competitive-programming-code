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
    int n, k; cin >> n >> k;
    if (k == 0){
        int b = 0;
        L(i,0,n) {
            cout << b;
            b = 1 - b;
        }
        cout << "\n";
        return;
    }
    int ones = k / 2;
    int twos = k - ones;
    string sol = "";
    L(i,0,ones + 1) {
        sol += "1";
    }
    L(i,0,twos + 1) {
        sol += "0";
    }
    int rem = n - (ones + 1) - (twos + 1);
    if (rem < 0) {
        cout << "-1\n";
        return;
    }
    int b = 1;
    L(i,0,rem){
        sol += ('0' + b);
        b = 1- b;
    }

    if (SZ(sol) != n) {
        cout << "-1\n";
        return;
    }
    int kc = 0;
    int k0 = 0;
    int k1 = 0;
    L(i,0,n){
        if (sol[i] == '1') k1++;
        if (sol[i] == '0') k0++;
        if (i > 0 && sol[i] == sol[i - 1]) kc++;
    }
    if ((kc != k) || (abs(k0 - k1) > 1)){
        cout << "-1\n";
        return;
    }
    cout << sol << "\n";
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