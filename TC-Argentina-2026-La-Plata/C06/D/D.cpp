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

int g[210][210];
void solve()
{
    int n, m; cin >> n >> m;
    L(i,0,n){
        L(j,0,m)
        {
            cin >> g[i][j];
        }
    }
    vec<int> r(n), c(m);
    auto print = [&]() -> void {
        L(i,0,n){
            L(j,0,m){
                cout << g[i][j] << " ";
            }
            cout << "\n";
        }
    };
    auto finish = [&]() -> void {
        print();
        cout << "YES\n";
        L(i,0,n) cout << r[i];
        cout << "\n";
        L(i,0,m) cout << c[i];
        cout << "\n";
        exit(0);
    };
    auto invCol = [&](int k) -> void {
        L(i,0,n) g[i][k] = 1 - g[i][k];
        c[k] = 1 - c[k];
    };
    auto invRow = [&](int k) -> void {
        L(i,0,m) g[k][i] = 1 - g[k][i];
        r[k] = 1 - r[k];
    };
    auto invs = [&]() -> bool {
        int lst = 1;
        L(i,0,n){
            L(j,0,m) {
                if (g[i][j] > lst) {
                    return false;
                }
                lst = g[i][j];
            }
        }  
        return true;
    };
    auto checkUpTo = [&](int mi, int mj) -> bool {
        int lst = 0;
        bool ans = 1;
        L(i,0,mi+1){
            L(j,0,mj+1) {
                if (g[i][j] < lst) {
                    ans = 0;
                    break;
                }
                lst = g[i][j];
            }
        }
        return ans;
    };
    auto check = [&]() -> bool {
        int lst = 0;
        bool ans = 1;
        L(i,0,n){
            L(j,0,m) {
                if (g[i][j] < lst) {
                    ans = 0;
                    break;
                }
                lst = g[i][j];
            }
        }  
        if (!ans && invs()) {
            L(i,0,n) invRow(i);
            finish();
        }
        return ans;
    };
    if (check()) {
        finish();
        return;
    }
    int lst = 0;
    L(i,0,n){
        L(j,0,m){
            check();
            if (g[i][j] < lst) {
                bool f0 = 0;
                bool f1 = 0;
                L(k,0,m) f0 = f0 || (!g[i][k]), f1 = f1 || g[i][k];
                if (f0 && !f1) invRow(i);
                else if (f0 && f1) {
                    // print();
                    L(k,j, m) if (!g[i][k]) invCol(k);
                    if (!checkUpTo(i,j)) {
                        // print();
                        cout << "NO\n";
                        return;
                    }
                }
            }
            lst = g[i][j];
        }
    }
    // print();
    finish();
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