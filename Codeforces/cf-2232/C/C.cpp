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
    int n, x, s; cin >> n >> x >> s;
    string S; cin >> S;
    int ans = 0;
    int lo = 0;
    int hi = n;

    auto f = [&](int t) -> int {
        int act = 0;
        deque<int> dq;
        int fans = 0;
        int taken = 0;
        L(i,0,n){
            if (S[i] == 'A'){
                if (act < t){
                    if (taken >= x) continue;
                    fans ++;
                    dq.pb(s - 1);
                    act ++;
                    taken++;
                    if (s == 1) dq.pop_front();
                } else {
                    if (SZ(dq)){
                        dq.front() --;
                        fans ++;
                        if (dq.front() == 0) dq.pop_front();
                    }
                }
            } else if (S[i] == 'I') {
                if (taken >= x) continue;
                dq.pb(s - 1);
                taken ++;
                fans ++;
                if (s == 1) dq.pop_front();

            } else if (S[i] == 'E') {
                if (SZ(dq)){
                    dq.front() --;
                    fans++;
                    if (dq.front() == 0) dq.pop_front();
                }
            }
        }
        return fans;
    };  

    // L(i,0,n + 1){
    //     cout << i << ": " << f(i) << "\n";
    // }
    
    while (lo <= hi)
    {
        int m = (lo + hi) / 2;
        if (f(m) >= f(m + 1)) {
            ans = m;
            hi = m - 1;
        } else {
            lo = m + 1;
        }
    }
    
    
    cout << f(ans) << "\n";
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