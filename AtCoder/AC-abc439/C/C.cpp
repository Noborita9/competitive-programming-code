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

const int N = 1e7 + 5;
int cnt[N];

void solve()
{
    int n; cin >> n;
    vec<int> out;
    L(i,2,n+1) if (cnt[i] == 1) out.pb(i);
    cout << SZ(out) << "\n";
    for (int v: out) cout << v << " ";
    cout << "\n";
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    //cin >> TT;
    vec<int> sq;
    L(i,1,N) {
        if (i * i >= N) break;
        sq.pb(i * i); // all x^2 < N
    } 
    L(i,0,SZ(sq)){
        L(j,i+1,SZ(sq)) {
            if (sq[i]+sq[j] < N){
                cnt[sq[i]+sq[j]]++;
            }
        }
    }
    while (TT--)
    {
        solve();
    }
}