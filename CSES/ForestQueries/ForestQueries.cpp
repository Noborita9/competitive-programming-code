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

#define LSO(S) (S & -S)
struct BIT { // 1-Index
    vec<vec<int>> B;
    int n; // BUILD: N * N * log(N) * log(N)
    BIT(int n_ = 1): B(n_+1,vec<int>(n_+1)), n(n_) {}
    void add(int i, int j, int delta){ // log(N) * log(N)
        for(int x = i; x <= n; x += LSO(x))
        for(int y = j; y <= n; y += LSO(y))
            B[x][y] += delta;
    }
    int sum(int i, int j){ // log(N) * log(N)
        int tot = 0;
        for(int x = i; x > 0; x -= LSO(x))
        for(int y = j; y > 0; y -= LSO(y))
            tot += B[x][y];
        return tot;
    } // {x1 <= x2 && y1 <= y2}
    int getSum(int x1, int y1, int x2, int y2) {return sum(x2, y2) - sum(x2, y1 - 1) - sum(x1 - 1, y2) + sum(x1-1,y1-1);}
};

void solve()
{
    int n, q; cin >> n >> q;
    vec<vec<bool>> f(n, vec<bool>(n));
    BIT bit(n + 1);
    L(i,0,n){
        L(j,0,n){
            char c; cin >> c;
            bit.add(i + 1, j + 1, c == '*');
        }
    }
    // L(i,0,n){
    //     L(j,0,n){
    //         cout << bit.getSum(i + 1, j + 1, i + 1, j + 1) << " ";
    //     }
    //     cout << "\n";
    // }
    while(q--){
        int bx, by, ex, ey; cin >> bx >> by >> ex>> ey;
        cout << bit.getSum(bx, by, ex, ey) << "\n";
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