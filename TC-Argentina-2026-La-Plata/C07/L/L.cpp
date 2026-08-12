#include <bits/stdc++.h>
using namespace std;
#define L(i,j,n) for(int i=j;i<int(n);i++)
#define ALL(x) begin(x),end(x)
#define SZ(x) int(x.size())
#define pb push_back
#define eb emplace_back
#define vec vector

using ll=long long;
using ld=long double;

using clk = chrono::steady_clock;


void solve(){
    int n; cin >> n;
    vec<int> a(n), b(n);
    vec<vec<int>> bid(n);
    L(i,0,n){
        cin >> a[i] >> b[i];
        a[i] --;
        bid[a[i]].pb(i);
    }
    vec<int> ok; ok.reserve(n);
    vec<int> kix(n, -1);
    vec<int> okix(n);
    set<int> killed;
    for (int i = n - 1; i >= 0; i --) {
        if (!killed.count(a[i])) {
            killed.insert(a[i]);
            kix[a[i]] = i;
            okix[a[i]] = SZ(ok);
            ok.pb(a[i]);
        }
    }
    vec<int> wk(n);
    // for (int o: ok) cout << o << " "; cout << "\n";
    // for (int o: kix) cout << o << " "; cout << "\n";
    int q; cin >> q;
    L(qi,0,q)
    {
        int k; cin >> k;
        vec<int> qs(k);
        L(i,0,k){
            cin >> qs[i]; qs[i] --;
        }
        sort(ALL(qs), [&](const int &lhs, const int &rhs) {
            return kix[lhs] > kix[rhs];
        });
        L(j,0,k) if (kix[qs[j]] != -1) wk[okix[qs[j]]] = 1;

        int g = -1;
        int t = -1;
        L(i,0,SZ(ok)){ // jesus O(k)
            if (!wk[i]) {
                if (g == -1) {
                    g = i;
                } else if (t == -1){
                    t = i;
                } else break;
            }
        }
        if (g == -1) {
            cout << "0 0\n";
        } else {
            if (t == -1) {
                cout << ok[g] + 1 << " " << b[*begin(bid[ok[g]])] << "\n";
            } else {
                cout << ok[g] + 1 << " " << b[*lower_bound(ALL(bid[ok[g]]), kix[ok[t]])] << "\n";
            }
        }
        // cout << g << " " << t << endl;
        
        L(j,0,k) wk[okix[qs[j]]] = 0;
        // L(j,0,k) wk[qs[j]] = 0;
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int TT=1;
    // cin>>TT;
    while(TT--) solve();
}