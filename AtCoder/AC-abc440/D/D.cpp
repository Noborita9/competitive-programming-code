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
    int n, q; cin >> n >> q;
    vec<int> a(n); L(i,0,n) cin >> a[i];
    sort(ALL(a));
    set<int> s;
    L(i,0,n) s.insert(a[i]);
    vec<int> x(q), y(q);
    L(i,0,q) cin >> x[i] >> y[i];
    vec<pair<int,int>> t;
    t.reserve(n + q);
    L(i,0,n)t.pb({a[i],0});
    L(i,0,q)if(s.find(x[i])==end(s)) { // cant find it
        s.insert(x[i]); // don't repeat x
        t.pb({x[i], 1}); // this can be used
    
    }
    t.pb({0,0});
    sort(ALL(t));
    int ln = SZ(t);
    vec<int> pref(ln);
    L(i,1,ln) pref[i] = pref[i - 1] + t[i].first-t[i-1].first + t[i].second - 1;
    // L(i,0,ln) cout << t[i].first << " ";
    // cout << "\n";
    // L(i,0,ln) cout << pref[i] << " ";
    // cout << "\n";
    L(i,0,q){
        int c_x = x[i];
        int c_y = y[i];
        // It's not base case hard
        if (c_x > a.back()) {
            cout << c_x + c_y - 1 <<"\n";
            continue;
        }
        if (c_x == a.back()){
            cout << c_x + c_y << "\n";
            continue;
        }
        pair<int, int> sr = {c_x, 1};
        auto lb = lower_bound(ALL(t), sr); // Yo se que hay un punto en x
        int ix = lb - begin(t);
        int base = pref[ix];
        auto nx = lower_bound(ALL(pref), base + c_y);
        nx --;
        int nix = nx - begin(pref);
        c_y -= *nx - (base - t[ix].second);
        // cout << "Found: " << nix << " " << *nx << " v " << base << "\n";
        // cout << c_y << "\n";
        if (c_y == 0 && !t[nix].second){
            cout << t[nix].first - 1 << "\n"; 
        } else {
            cout << t[nix].first + c_y << "\n";
        }
        // cout << ix << "\n";
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