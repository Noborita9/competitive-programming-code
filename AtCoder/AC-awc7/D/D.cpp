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

const int N = 505;
int b[N][N];

void solve()
{
    int n, a, c; cin >> n >> a >> c;
    L(i,0,a) {
        int rx, ry, lx, ly;
        cin >> rx >> ry >> lx >> ly;
        rx--;ry--;lx--;ly--;
        L(j,rx,lx+1){
            L(k,ry,ly+1){
                b[j][k] |= 1;
            }
        }
    }
    L(i,0,c) {
        int rx, ry, lx, ly;
        cin >> rx >> ry >> lx >> ly;
        rx--;ry--;lx--;ly--;
        L(j,rx,lx+1){
            L(k,ry,ly+1){
                b[j][k] |= 2;
            }
        }
    }

    int tot = 0;
    L(i,0,n){
        L(j,0,n){
            tot += b[i][j]==3;
        }
    }
    cout << tot  << "\n";
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