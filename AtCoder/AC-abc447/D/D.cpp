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
    string s; cin >> s;
    map<char, deque<int>> M;
    int n = SZ(s);
    L(i,0,n){
        M[s[i]].pb(i);
    }
    int ops = 0;
    while (1){
        if (M['A'].empty()) break;
        if (M['B'].empty()) break;
        if (M['C'].empty()) break;
        int aix = M['A'].front();
        M['A'].pop_front();
        int bix = 0;
        while (SZ(M['B'])){
            bix = M['B'].front();
            M['B'].pop_front();
            if(bix > aix) break;
            else bix = 0;
        }
        if (bix == 0) break;
        int cix = 0;
        while (SZ(M['C'])){
            cix = M['C'].front();
            M['C'].pop_front();
            if(cix > bix) break;
            else cix = 0;
        }
        if (cix == 0) break;
        ops ++;
    }
    cout << ops << "\n";
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