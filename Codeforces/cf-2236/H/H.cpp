#include <bits/stdc++.h>
using namespace std;
#define L(i,j,n) for(int i=j;i<int(n);i++)
#define ALL(x) begin(x),end(x)
#define SZ(x) int(x.size())
#define pb push_back
#define vec vector
#define eb emplace_back
using ll=long long;
using ld=long double;

const int EQ = 0;
const int SUM = 1;

const int SYNC = 0;
const int ASYNC = 1;


struct Op {
    int t, v, k;
    Op(int t_, int v_, int k_): t(t_), v(v_), k(k_) {}
};

const int N = 2005;
const int MAXV = 501;
bitset<N * MAXV> dp, ans, cc; 

void solve(){
    int n; cin >> n;
    vec<Op> ops; ops.reserve(n+1);
    ops.eb(EQ, 0, SYNC);
    L(i,0,n){
        char t; cin >> t;
        int v; cin >> v;
        string k; cin >> k;
        ops.eb(t == '=' ? EQ : SUM, v, k[0]=='a'? ASYNC : SYNC);
        // cout << ops.back().v << " " << ops.back().k << " \n";
    }
    ops.eb(SUM, 0, SYNC);
    int leq = SZ(ops) - 1;
    while(ops[leq].t != EQ) leq --;
    if (leq == 0) { // everything is sync
        cout << "1\n";
        return;
    }
    vec<Op> asum;
    int aeq = 0;
    if (ops[leq].k == ASYNC) dp[ops[leq].v] = 1, ans[ops[leq].v] = 1;
    L(i,0,leq) {
        if (ops[i].t == SUM && ops[i].k == ASYNC) asum.pb(ops[i]);
        if (ops[i].t == EQ && ops[i].k == ASYNC) {
            dp[ops[i].v] = 1;
        }
    }
    cc[0] = 1;
    for (const Op &op: asum) {
        dp |= (dp << op.v);
        cc |= (cc << op.v);
    }
    // cout << cc.count() << "\n";
    // L(i,0,35) cout << cc[i] << ""; cout << "\n";

    int sm = 0;
    for (int i = SZ(ops) - 1; i > leq; i --) {
        sm += ops[i].v;
    }
    
    // if (ops[leq].k == SYNC) {
    ans |= (cc << (ops[leq].v + sm));
    ans |= (dp << sm);
    // }
    // cout << ans.count() << "\n";
    for (int i = leq + 1; i < SZ(ops); i ++) {
        // cout << i <<": " << " w " << sm << "\n";
        if (ops[i].k == ASYNC) {
            dp |= (dp << ops[i].v);
            // cout << "ops: " << ops[i].v << " \n";
        }
        sm -= ops[i].v;
        ans |= (dp << sm);
        // L(j,0,35) cout << dp[j] << ""; cout << "\n";
        // L(j,0,35) cout << ans[j] << ""; cout << "\n";
    }
        
    // cout << "\n\n";
    // L(i,0,35) cout << ans[i] << ""; cout << "\n";
    
    

    cout << ans.count() << "\n";
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int TT=1;
    // cin>>TT;
    while(TT--){
        solve();
    }
}
