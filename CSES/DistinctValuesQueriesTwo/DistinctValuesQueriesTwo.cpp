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

    const int oo = 1e9;
    struct ST {
        vec<int> st; int k, n;
        ST(int n_): k(1), n(n_) {
            while(k<n) k<<=1;
            st.assign(2 * k, 0);
        }
        void upd(int i, int x) {
            if (i < 0 || i >= n) return; // Invalid points
            x += i; // Add offset inside
            st[i += k] = x; while (i >>= 1) st[i] = min(st[i * 2], st[i * 2 + 1]);
        }
        int query(int l, int r){
            int mn = oo;
            for (l += k, r += k; l < r; l >>= 1, r >>= 1) {
                if (l & 1) mn = min(mn, st[l ++]);
                if (r & 1) mn = min(mn, st[-- r]);
            }
            return mn;
        }
        void print() {
            L(i,0,n) cout << st[i + k] << " ";
            cout << "\n";
        }
    };

    void solve()
    {
        int n, q; cin >> n >> q;
        vec<int> x(n);
        map<int, set<int>> m;
        ST st(n);
        auto add = [&](int w, int p) -> void {
            auto &s = m[w];
            if (SZ(s) == 0) {
                s.insert(-1);
                s.insert(10 * n);
            }
            auto nxt = s.lower_bound(p);
            auto pre = prev(nxt);
            st.upd(*pre, p - *pre);
            st.upd(p, *nxt - p);
            s.insert(p);
        };
        auto remove = [&](int w, int p) -> void {
            auto &s = m[w];
            assert(SZ(s) > 0);
            s.erase(p);
            auto nxt = s.lower_bound(p);
            auto pre = prev(nxt);
            st.upd(*pre, *nxt - *pre);
        };
        L(i,0,n) {
            cin >> x[i];
        }
        for (int i = n - 1; i >= 0; i --){
            add(x[i], i);
        }
        // st.print();
        L(qi,0,q)
        {
            int op, a, b; cin >> op >> a >> b;
            if (op == 2) {
                int mn = st.query(a - 1, b) - (a - 1);
                int len = b - a + 1;
                // cout << mn << " - " << len << "\n";
                cout << (mn < len ? "NO" : "YES") << "\n";
            } else {
                int rem = x[a - 1];
                remove(rem, a - 1);
                add(b, a - 1);
                x[a - 1] = b;
            }
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