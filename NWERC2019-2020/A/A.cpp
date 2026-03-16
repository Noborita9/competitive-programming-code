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

struct ST {
    vec<ll> st; ll k; ll mx; int n;
    ST(int n): k(1), mx(0), n(n) {
        while(k<=n)k<<=1;
        st.assign(k*2,0);
    }
    void upd(int i, ll x){
        i += k; st[i] += x;
        mx = max(mx, (ll)i);
        while(i>>=1)st[i]=st[2*i]+st[2*i+1];
    }
    ll query(int l, int r){
        ll ans = 0;
        for (l += k, r += k; l < r; l>>=1, r>>=1){
            if (l & 1) ans += st[l++];
            if (r & 1) ans += st[--r];
        }
        return ans;
    }
    ll query(int l){
        return query(l, n);
    }
};

struct G {
    ll ini;
    ll acc;
    ll cur;
};

struct P {
    ll xp;
    int gi; // group index
    ll acc; // group accumulated
};

void solve()
{
    int n, w; cin >> n >> w;
    ST st(w + 10);
    // cout << st.query(0) << "\n";
    st.upd(0, n);
    vec<G> groups(w + 10);
    vec<P> player(n);
    groups[0].cur = 1;
    ll t = 0;
    // cout << st.query(0) << "\n";
    vec<vec<int>> ppg(w + 10);
    auto AlterPoints = [&](vec<int> &ixs) {
        int k = SZ(ixs);
        set<int> upds;
        L(j,0,k){
            int x = ixs[j];
            st.upd(player[x].gi, -1);
            st.upd(player[x].gi + 1, 1);
            upds.insert(player[x].gi);
            upds.insert(player[x].gi + 1);
            ppg[player[x].gi].pb(x);
            // Update Players in rank
        }
        // Update groups
        // Cuanto a generado el grupo hasta ahora
        // Con cuanto entro el Player a ese grupo

        for (int v: upds) {
            groups[v].acc += (t - groups[v].ini) * groups[v].cur;
            // Cuanto tiempo ha estado en ese grupo
            groups[v].ini = t;
            groups[v].cur = st.query(v + 1) + 1; // Cuantos players son mayores
            // cout << "Query: " << v + 1 << " " << + 1 << " -> " << st.query(v + 1) + 1 << "\n";
        }
        // cout << "Time: " << t << "\n";
        for (int v: upds) {
            for (int j: ppg[v]) { // all the players affected
                // cout << "Group: " << v << " -> " << groups[v].cur << " -> " << j << " => ";
                player[j].xp += groups[v].acc - player[j].acc;
                // cout << "Added: " << groups[v].acc - player[j].acc<< "\n";
                player[j].acc = groups[v + 1].acc;
                player[j].gi = v + 1;
            }
            ppg[v].clear();
        }
        // Calculare rank diffs
        t ++;
    };
    
    L(i,0,w)
    {
        int k; cin >> k;
        vec<int> ixs(k);
        L(j,0,k) {
            cin >> ixs[j];
            ixs[j] --;
        }
        AlterPoints(ixs);
    }
    vec<int> allP(n);
    iota(ALL(allP),0);
    AlterPoints(allP);
    t --;
    cout << fixed;
    cout.precision(10);
    for(const P p: player) {
        cout << (ld)p.xp/t << "\n";
        // cout<< p.xp << " -> " << (ld)p.xp/t << "\n";
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