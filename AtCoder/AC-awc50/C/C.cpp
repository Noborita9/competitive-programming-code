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
    int q; cin >> q;
    int xr = 0;
    vec<int> st;
    map<int, int> last;
    int LOP = 0;
    L(qi,1,q+1)
    {
        string op; cin >> op;
        if (op == "REMOVE") {
            xr ^= st.back();
            st.pop_back();
        } else if (op == "LOOK") {
            LOP ++;
            if (!last[xr]) {
                cout << "-1\n";
            } else {
                cout << last[xr] << "\n";
            }
            last[xr] = LOP;
        } else {
            int c; cin >> c;
            xr ^= c;
            st.pb(c);
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