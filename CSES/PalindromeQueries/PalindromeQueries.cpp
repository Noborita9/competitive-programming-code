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

constexpr ll ms[2] = {1'000'000'007, 1'000'000'403};
constexpr ll B = 500'000'000;

const int N = 2e5 + 10; 
ll pot[2][N];

inline ll modsum(ll a, ll b, ll m) {
    a += b;
    if (a >= m) a %= m;
    return a;
}
inline ll modmul(ll a, ll b, ll m){
    a *= b;
    if (a >= m) a %= m;
    return a;
}

struct tint {
    ll h1, h2, h;
    bool operator==(const tint &rhs) const {
        return h == rhs.h;
    }
    tint(ll x): h1(x%ms[0]),h2(x%ms[1]) {
        h = (h1<<32)|h2;
    }
    tint(ll h1_, ll h2_, ll h_): h1(h1_), h2(h2_), h(h_) {}
    // tint operator+(tint &rhs) {
    //     ll nh1 = modsum(h1, rhs.h1, ms[0]);
    //     ll nh2 = modsum(h2, rhs.h2, ms[1]);
    //     ll nh = (nh1<<32)|nh2;
    //     return tint(nh1,nh2,nh);
    // }
    tint operator+=(tint &rhs) {
        ll nh1 = modsum(h1, rhs.h1, ms[0]);
        ll nh2 = modsum(h2, rhs.h2, ms[1]);
        ll nh = (nh1<<32)|nh2;
        return tint{nh1,nh2,nh};
    }
    tint operator+(const ll &rhs) {
        ll nh1 = modsum(h1, rhs, ms[0]);
        ll nh2 = modsum(h2, rhs, ms[1]);
        ll nh = (nh1<<32)|nh2;
        return tint{nh1,nh2,nh};
    }
    tint operator*(const ll &rhs) {
        ll nh1 = modmul(h1, pot[0][rhs], ms[0]);
        ll nh2 = modmul(h2, pot[1][rhs], ms[1]);
        ll nh = (nh1<<32)|nh2;
        return tint{nh1,nh2,nh};
    }
};
tint operator+(tint lhs, tint rhs) {
    ll nh1 = modsum(lhs.h1, rhs.h1, ms[0]);
    ll nh2 = modsum(lhs.h2, rhs.h2, ms[1]);
    ll nh = (nh1<<32)|nh2;
    return tint(nh1,nh2,nh);
}
tint operator+(tint lhs, int rhs) {
    ll nh1 = modsum(lhs.h1, rhs, ms[0]);
    ll nh2 = modsum(lhs.h2, rhs, ms[1]);
    ll nh = (nh1<<32)|nh2;
    return tint{nh1,nh2,nh};
}

struct node {
    tint hash;
    int len;

    node operator+=(const node &b) {
        if (len == 0) return b;
        if (b.len == 0) return *this;
        tint h = hash * (ll)b.len + b.hash;
        return {h, len + b.len};
    }
};

node operator+(node a, node b) {
    if (a.len == 0) return b;
    if (b.len == 0) return a;
    tint h = a.hash * (ll)b.len + b.hash;
    return {h, a.len + b.len};
}

struct STI {
    vec<node> st; int n, K;
    STI(const string &a): n(SZ(a)), K(1) {
        while(K<=n) K<<=1;
        st.assign(2*K, {0, 0}); // 0 default
        L(i,0,n) st[K+i] = {{(ll)a[i]}, 1};
        for (int i = K - 1; i > 0; i --) st[i] = st[i*2] + st[i*2+1];}
    void upd(int pos, char w) {
        pos += K; st[pos] = {{(ll)w}, 1};
        while((pos>>=1) > 0) st[pos] = st[pos * 2] + st[pos * 2 + 1];}
    node query(int l, int r) { // [l, r] 
        node resL = {{0}, 0};
        node resR = {{0}, 0};
        for (l += K, r += K + 1; l < r; l>>=1, r>>=1){
            if (l & 1) resL = resL + st[l++];
            if (r & 1) resR = st[--r] + resR;
        } 
        return resL + resR;
    }
};


void solve()
{
    int n, Q; cin >> n >> Q;
    string s; cin >> s;
    STI st(s);
    reverse(ALL(s));
    STI stRev(s);
    // Probar que [2;4] es palindromo
    auto invI = [&](int i) -> int {
        return n - 1 - i;
    }; 
    // ll h1 = st.query(2, 4).hash.h;
    // ll h2 = stRev.query(2, 5).hash.h;
    // cout << h1 << " " << h2 << "\n";
    L(q,0,Q) {
        int op; cin >> op;
        if (op == 1){
            int i; char c; cin >> i >> c;
            i --;
            st.upd(i, c);
            stRev.upd(invI(i), c);
            // Update st
        } else {
            int l,  r; cin >> l >> r; l --; r--;
            // Query left
            ll h1 = st.query(l, r).hash.h;
            // Query right
            ll h2 = stRev.query(invI(r), invI(l)).hash.h;
            if (h1 == h2) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
            // Are they Equal?
        }
    }
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    L(k,0,2){
        pot[k][0] = 1;
        L(i,1,N) pot[k][i] = modmul(pot[k][i - 1], B, ms[k]);
    }
    //cin >> TT;
    while (TT--)
    {
        solve();
    }
}