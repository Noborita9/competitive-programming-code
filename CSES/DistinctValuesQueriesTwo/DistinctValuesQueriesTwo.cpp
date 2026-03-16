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

struct Vertex {
    int sm;
    Vertex *l, *r;
    Vertex(int x): sm(x), l(0), r(0) {}
    Vertex(Vertex *l_, Vertex *r_): sm(0), l(l_), r(r_) {
        if (l) sm += l->sm;
        if (r) sm += r->sm;
    }
};

Vertex * build(int L, int R) {
    assert(R - L != 0);
    if (R - L == 1) return new Vertex(0);
    else {
        int m = (L + R) / 2;
        return Vertex(build(L, m), build(m, R));
    }
}

Vertex * version(Vertex * v, int L, int R, int x, int w) {
    if (!v) return 0;
    if (R - L == 1){
        // leaf
        Vertex * u = new Vertex(v->sm + w);
        return u;
    } else {
        int m = (L + R) / 2;
        if (x < m) return new Vertex(version(v->l, L, m, x, w), v->r);
        return new Vertex(v->l, version(v->r, m, R, x, w));
    }
}

void update(Vertex * v, int L, int R, int x, int w) {
    if (!v) return;
    if (R - L == 1) {
        v->sm += w;
    } else {
        int m = (L + R);
        if (x < m) update(v->l, L, m, x, w);
        else update(v->r, m, R, x, w);
    }
}

void solve()
{
    int n, q; cin >> n >> q;
    vec<int> a(n);
    L(i,0,n) cin >> a[i];
    vec<Vertex*> root;
    root.reserve(n + 1);
    root.pb(build(0, n));
    map<int,int> last; L(i,0,n) last[a[i]] = -1;
    L(i,0,n){
        Vertex * v = version(root.back(), 0, n, i);
        if ()
        v= version(v, 0, n, last[i]); // Tengo que cambiar este tmb, si no voy a afectar a los pasados
        root.pb(v)
    }
    
    L(qi,0,q){
        int op, a, b; cin >> op >> a >> b;
            
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