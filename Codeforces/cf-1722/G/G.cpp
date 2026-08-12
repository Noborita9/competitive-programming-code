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
    vec<int> out; out.reserve(n);
    auto go = [&](auto && rec, int k) -> void {
        if (k < 0) {
            cout << "Minus " << k << endl;
            return;
        }
        if (k == 0){
            return;
        } else if (k == 1) {
            out.pb(0);
            return;
        } else if (k == 2) {
            out[0] += 1 << 25;
            out.pb(0);
            out.pb(1<<25);
            return;
        } else if (k == 3){
            out.pb(2);
            out.pb(1);
            out.pb(3);
            return;
        } else if (k == 4) {
            out.pb(2);
            out.pb(1);
            out.pb(3);
            out.pb(0);
            return; // all of this seems like trash
        }
        int r = 1 << (bit_width((unsigned int)k) - 1);

        int le = r;
        int ri = r * 2 - 1;
        while (le < ri) {
            out.pb(le);
            out.pb(ri);
            le ++;
            ri --;
            k -= 2;
        }
        rec(rec, k);
    };
    go(go, n);
    int xoi = 0;
    int xop = 0;
    L(i,0,n) cout << out[i] << " ";
    cout<<"\n";
    // cout << "Have: " << (xoi ^ xop) << "\n";
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