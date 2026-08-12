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

const int N = 1e5 + 200;
const ll mmod = (1LL<<61) - 1;
const ll B = 131;
const ll mod = (ll)(1e9) + 7LL;

vec<pair<int,int>> g[N];
ll p_b[N];
ll p2[N];

inline ll modmul(ll a, ll b) {
    return (ll)(__int128(a)*b%mmod);
}
inline ll modsum(ll a, ll b) {
    a += b;
    if (a >= mmod) a -= mmod;
    return a;
}


struct Vertex {
    ll h; // this optimizes traversals
    ll val_mod;
    ll sz;
    bool all_ones;
    static Vertex pool[15000000];
    static int pCnt;
    void* operator new(size_t) {
        return &pool[pCnt++];
    }
    Vertex *l, *r;
    Vertex(): h(0), val_mod(0), sz(1), all_ones(0), l(0), r(0) {}
    Vertex(ll i): h(i==1), val_mod(i==1), sz(1), all_ones(i==1), l(0), r(0) {}
    Vertex(Vertex *l_, Vertex *r_): h(0), sz(0), all_ones(0), l(l_), r(r_) {
        if (l) {
            h = l->h;
            val_mod = l->val_mod;
            sz += l->sz;
            all_ones = l->all_ones;
        }
        if (r) {
            h = modsum(h, modmul(r->h, p_b[l->sz]));
            val_mod = (val_mod + (r->val_mod * p2[l->sz] % mod)) % mod; 
            all_ones &= r->all_ones;
            sz += r->sz;
        }
    }
};  
Vertex Vertex::pool[15000000];
int Vertex::pCnt = 0;
Vertex * build(int L, int R) {
    if (R - L == 1) return new Vertex();
    else {
        int m = (L + R) / 2;
        return new Vertex(build(L, m), build(m, R));
    }
}

Vertex * update(Vertex * v, int L, int R, int pot) {
    if (R - L == 1) {
        return new Vertex(1);
    } else {
        int m = (L + R) / 2;
        if (pot < m) return new Vertex(update(v->l, L, m, pot), v->r);
        return new Vertex(v->l, update(v->r, m, R, pot));
    }
}

using ii = pair<Vertex*, int>;

bool compare_minus(const Vertex * l, const Vertex * r) {
    if (l->h == r->h) return false;
    if (l->sz == 1) return l->h < r->h;
    if (r->r->h != l->r->h) return compare_minus(l->r, r->r);
    return compare_minus(l->l, r->l);
}

int find_first_0(Vertex * v, int p, int L, int R){
    if (v->all_ones) return -1;
    if (R <= p) return -1;
    if (R - L == 1) return L;
    int m = (L + R) / 2;
    int ql = find_first_0(v->l, p, L, m);
    if (ql != -1) return ql;
    return find_first_0(v->r, p, m, R);
}

Vertex * set_0(Vertex * v, Vertex * z, int L, int R, int ql, int qr) {
    if (ql >= R || qr <= L) return v; // do not update more
    if (ql <= L && R <= qr) {
        return z;
    }
    int m = (L + R) / 2;
    return new Vertex(set_0(v->l, z->l, L, m, ql, qr), set_0(v->r, z->r, m, R, ql, qr));
};

Vertex * sum_pow(Vertex * l, Vertex * r, int p) {
    int x_pos = find_first_0(l, p, 0, N);
    Vertex * res = update(l, 0, N, x_pos);
    if (x_pos > p) {
        res = set_0(res, r, 0, N, p, x_pos);
    }
    return res;
}

struct CMP {
    bool operator()(const ii lhs, const ii rhs) const {
        return compare_minus(rhs.first, lhs.first);
    };
};

void solve()
{
    int n, m; cin >> n >> m;
    L(i,0,m){
        int u, v, p; cin >> u >> v >> p;
        u --; v --;
        g[u].eb(p, v);
        g[v].eb(p, u);
    }
    int s, t; cin >> s >>t; s --; t--;
    if (s == t) {
        cout << "0\n1\n" << s+1 << "\n";
        return;
    }
    vec<Vertex*> roots; 
    roots.pb(build(0, N));
    // L(i,1,N - 1) {
    //     roots.pb(update(roots[0], 0, N, i));
    // }
    vec<int> prev(n, - 1);
    vec<Vertex*> dist(n, NULL); // non possible values N + log(N)
    priority_queue<ii, vec<ii>, CMP> pq;
    pq.push({roots[0], s});
    dist[s] = roots[0];
    while(SZ(pq)){
        auto [uroot, u] = pq.top(); pq.pop();
        if (uroot != dist[u]) continue;
        if (u == t) {
            break; // found best path
        }
        for (const auto &[p, v]: g[u]) {
            Vertex * nroot = sum_pow(uroot, roots[0], p);
            if (dist[v] == NULL || compare_minus(nroot, dist[v])) { // nroot < dist[v]
                dist[v] = nroot;
                prev[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    if (prev[t] == -1){
        cout << "-1\n";
        return;
    }
    vec<int> path;
    ll ans = dist[t]->val_mod; // I can calculate this using distance
    cout << ans << "\n";
    for (int x = t; x != -1; x = prev[x]) path.pb(x);
    reverse(ALL(path));
    cout << SZ(path) << "\n";
    for (int p: path) cout << p + 1 << " ";
    cout << "\n";
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    //cin >> TT;
    p2[0] = 1;
    p_b[0] = 1;
    L(i,1,N) {
        p2[i] = (p2[i-1]<<1) % mod;
        p_b[i] = modmul(p_b[i - 1], B);
    }
    while (TT--)
    {
        solve();
    }
}