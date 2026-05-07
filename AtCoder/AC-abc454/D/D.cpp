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
    string a, b; cin >> a >> b;
    auto strippxxp = [](string &s) -> string {
        int n = SZ(s);
        vec<int> keep(n, 1);
        L(i,0,n - 1) {
            if (s[i] == 'x' && s[i + 1] == 'x') {
                // try to strip
                int l = i - 1;
                int r = i + 2;
                while (l >= 0 && r < n && s[l] == '(' && s[r] == ')') {
                    keep[l] = 0;
                    keep[r] = 0;
                    l --;
                    r ++;
                }
            }
        }
        string out = "";
        L(i,0,n) if (keep[i]) out += s[i];
        return out;
    };
    a = strippxxp(a);
    // cout << "A: " << a << "\n";
    b = strippxxp(b);
    // cout << "b: " << b << "\n";
    if (a == b) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
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