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
    string s, t; cin >> s >> t;
    vec<int> a(26), b(26);
    for (char c: s) a[c - 'a'] ++;
    for (char c: t) b[c - 'a'] ++;
    L(i,0,26){
        if (b[i] < a[i]) {
            cout << "Impossible\n";
            return;
        }
        b[i] -= a[i]; // keep on b the ones I can freely use
    }
    vec<int> out;
    out.reserve(SZ(t));
    L(i,0,SZ(s)){
        L(j,0,s[i]-'a'){
            while(b[j]){
                out.pb(j);
                b[j]--;
            }
        }
        out.pb(s[i]-'a');
    }    
    L(i,0,26) while(b[i]) {
        out.pb(i);
        b[i]--;
    }
    for (int o: out) cout << (char)('a'+o);
    cout << "\n";

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