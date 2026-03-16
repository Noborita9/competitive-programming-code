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


struct pitem {
    ll val;
    int pos;
    int pre;
    int cur;
    bool operator<(const pitem &rhs) const {
        if (val != rhs.val) return val < rhs.val;
        if (pos != rhs.pos) return pos < rhs.pos;
        if (pre != rhs.pre) return pre < rhs.pre;
        return cur < rhs.cur;
    };
    bool operator>(const pitem &rhs) const {
        if (val != rhs.val) return val > rhs.val;
        if (pos != rhs.pos) return pos > rhs.pos;
        if (pre != rhs.pre) return pre > rhs.pre;
        return cur > rhs.cur;
    };
};

void solve()
{
    int n;ll k, x; cin >> n >> k >> x;
    vec<ll> a(n); L(i,0,n) cin >> a[i]; sort(ALL(a),greater<ll>());
    priority_queue<pitem> pq;
    pq.push(pitem{a[0] * k, 0, 0, k});
    while(x--){
        pitem p = pq.top();pq.pop();
        cout << p.val << "\n";
        if (p.pre){
            pq.push(pitem{p.val - a[p.pos-1] + a[p.pos], p.pos, p.pre - 1, p.cur + 1});
        }
        if (p.pos != n - 1){
            pq.push(pitem{p.val - a[p.pos] + a[p.pos+1], p.pos + 1, p.cur - 1, 1});
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