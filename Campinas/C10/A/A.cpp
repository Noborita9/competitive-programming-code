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

using ii = pair<int, int>;
using iii = tuple<int,int,int>;
using iiii = tuple<int,int,int,int>;

const int oo = (int)1e9;

struct node {
    int mn, mx, c;
    set<ii, greater<ii>> s;
};

const node noNode = {oo,-oo, 0,{}};

node merge(node a, node b){
    if (a.mn == oo) return b;
    if (b.mn == oo) return a;
    return {min(a.mn, b.mn), max(a.mx, b.mx), a.c + b.c, {}};
}

struct ST {
    vec<node> st;
    int n;
    ST(int n_): st(4 * n_ + 5, noNode), n(n_) {}
    node query(int v, int L, int R, int ql, int qr){
        if (qr < L || ql > R) return noNode;
        if (L == ql && qr == R) return st[v];
        int m = (L + R) / 2;
        return merge(query(v * 2, L, m, ql, min(qr, m)), query(v * 2 + 1, m + 1, R, max(m + 1, ql), qr));
    }
    node query(int l, int r){
        return query(1, 0, n - 1, l, r);
    }
    int erase(int v, int L, int R, int ql, int qr, int z) {
        if (qr < L || ql > R) return 0;
        if (st[v].mx < z || st[v].mn == oo) return 0;
        if (L == R) {
            int cnt = 0;
            while (SZ(st[v].s)) {
                if (st[v].s.begin()->first < z) break;
                cnt += st[v].s.begin()->second;
                st[v].s.erase(st[v].s.begin());
            }
            st[v].c -= cnt;
            if (SZ(st[v].s)){
                st[v].mx =st[v].s.begin()->first;
            } else {
                st[v] = noNode;
            }
            return cnt;
        }
        int m = (L + R) /2 ;
        int tot = erase(v * 2, L, m, ql, min(m,qr), z);
        tot += erase(v * 2 + 1, m + 1, R, max(m + 1, ql), qr, z);
        st[v] = merge(st[v * 2], st[v * 2 + 1]);
        return tot;
    };
    int erase(int l, int r, int z){
        return erase(1,0, n - 1, l, r, z);
    }
    void insert(int v, int L, int R, int y, int z, int c) {
        if (L == R){
            st[v].mn = min(st[v].mn, z);
            st[v].mx = min(st[v].mx, z);
            st[v].c += c;
            st[v].s.insert({z, c});
            return;
        }
        int m = (L + R) / 2;
        if (y <= m) {
            insert(2 * v, L, m, y, z, c);
        } else insert(2 * v + 1, m + 1, R, y, z, c);
        st[v] = merge(st[2 * v], st[2 * v + 1]);
    }
    void insert(int y, int z, int c) {
        insert(1, 0, n - 1, y, z, c);
    }
};

struct pt {
    int x, y, z, c;
};
struct Index {
    vec<int> d;
    int sz;
    Index(const vec<int> &a): d(ALL(a)) {
        sort(ALL(d));
        d.erase(unique(ALL(d)),end(d));
        sz = SZ(d);
    }
    inline int of(int e) {return lower_bound(ALL(d), e) - begin(d);}
};
void solve()
{
    int n, m; cin >> n >> m;
    vec<vec<ii>> g(n + 10);
    L(i,0,m){
        int u, v, w; cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    const int X = 0;
    const int Y = 1;
    const int Z = 2;
    auto dijkstra = [&](int s) -> vec<int> {
        vec<int> dist(n, oo);
        dist[s] = 0;
        priority_queue<ii, vec<ii>, greater<ii>> pq;
        pq.push({0, s});
        while(SZ(pq)){
            auto [d, u] = pq.top();pq.pop();
            if (d != dist[u]) continue;
            for (auto &[v, w]: g[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    };
    vec<int> dX = dijkstra(X);
    vec<int> dY = dijkstra(Y);
    vec<int> dZ = dijkstra(Z);
    vec<iii> pts;
    pts.reserve(n);
    vec<int> raw; raw.reserve(n);
    L(i,0,n) {
        pts.eb(dX[i], dY[i], dZ[i]);
        raw.pb(dY[i]);
    }
    sort(ALL(pts));
    Index ix(raw);
    auto &[fx, fy, fz] = pts.front();
    vec<pt> ps;
    ps.pb({fx,ix.of(fy),fz,1});
    for (int i = 1; i < SZ(pts); i ++){
        auto &[cx, cy, cz] = pts[i];
        // cx=ix.of(cx);
        cy=ix.of(cy);
        // cz=ix.of(cz);
        if (cx == ps.back().x && cy == ps.back().y && cz == ps.back().z){
            ps.back().c++;
        } else {
            ps.pb({cx,cy,cz, 1});
        }
    }
    int st_sz = ix.sz + 10;
    ST st(st_sz);
    int ans = 0;
    for (const auto &[x, y, z, c]: ps) {
        int mn = st.query(0, y).mn;
        if (mn <= z) {
            continue;
        }
        ans -= st.erase(y + 1, st_sz - 1, z);
        ans -= st.erase(y, y, z + 1);
        st.insert(y, z, c);
        ans += c;
    }
    cout << ans << "\n";
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