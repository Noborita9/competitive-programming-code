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
    vec<int> nums;
    nums.reserve(n);
    L(i,0,n){
        string s; cin >> s;
        int neg = s[0] == '-';
        if (neg) continue;
        if (SZ(s) >= 7) continue;
        int x = 0;
        for (char c: s){
            x = x * 10 + c-'0';
        }
        nums.pb(x);
    }
    if (nums.empty()){
        cout << "0\n";
        return;
    }
    sort(ALL(nums));
    int mx = 0;
    for (int x: nums) if (mx == x) mx ++;
    cout << mx << "\n";
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