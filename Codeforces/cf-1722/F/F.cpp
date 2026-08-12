#include <bits/stdc++.h>
using namespace std;

#define L(i, j, n) for (int i = (j); i < (int)n; i ++)
#define SZ(x) int((x).size())
#define ALL(x) begin(x),end(x)
#define vec vector
#define pb push_back
#define eb emplace_back
#define mset(x,v) memset(x, v, sizeof(x));

using ll = long long;
using ld = long double;

char g[60][60];

vec<pair<int,int>> Lshape[] = {
    {
        {0,0}, {0, -1}, {-1, -1}
    },
    {
        {0,0}, {0, -1}, {1, -1}
    },
    {
        {0,0}, {1, 0}, {1, -1}
    },
    {
        {0,0}, {1, 0}, {1, 1}
    },
    {
        {0,0}, {-1, 0}, {-1, 1}
    },
    {
        {0,0}, {-1, 0}, {-1, -1}
    },
    {
        {0,0}, {0, 1}, {-1, 1}
    },
    {
        {0,0}, {0, 1}, {1, 1}
    },
    {
        {0,0}, {0, 1}, {1, 0}
    },
};

void solve()
{
    int n, m; cin >> n >> m;
    mset(g, '.');
    L(i,1,n+1){
        L(j,1,m+1){
            cin >> g[i][j];
        }
    }
    auto allP = [&](int i, int j) -> bool {
        L(x,-1,2){
            L(y,-1,2){
                if (g[i + x][j + y] != '.') return false;
            }
        }
        return true;
    };
    auto print = [&]() -> void {
        L(i,1,n+1) {
            L(j,1,m+1) {
                cout << g[i][j];
            }
            cout << "\n";
        }
    };
    L(i,1,n+1)
    {
        L(j,1,m+1)
        {
            if (g[i][j] == '.') continue;
            bool fixed = 0;
            for (const auto &shpe: Lshape)
            {
                bool ff = 1;
                for (const auto &[dx, dy]: shpe)
                {
                    ff = ff && g[i + dx][j + dy] == '*';
                } 
                if (ff) {
                    for (const auto &[dx, dy]: shpe)
                    {
                        g[i + dx][j + dy] = '.';
                    }
                    bool cf = 1;
                    for (const auto &[dx, dy]: shpe)
                    {
                        cf = cf && allP(i + dx, j + dy);
                    }                     
                    if (cf) {fixed = 1; break;}
                }
            }
            if (!fixed) {
                cout << "NO\n";
                return;
            } 
        }
    }
    cout << "YES\n";
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