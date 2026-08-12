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

void solve()
{
    int n; cin >> n;
    vec<int> b(n), p(n);
    int root = 0;
    vec<vec<int>> g(n);
    L(i,0,n) {
        cin >> b[i];
        b[i] --;
        if (b[i] == i) root = i;
        else {
            g[b[i]].eb(i);
        }
    }
    L(i,0,n){
        cin >> p[i];
        p[i] --;
    }
    const int oo = 1e9 + 30;
    vec<int> dist(n, oo), w(n);
    dist[root] = 0;
    int mxdist = 0;
    set<int> ch;
    for (int c: g[root]) ch.insert(c);
    if (root != p[0]) {
        cout << "-1\n";
        return;
    }
    L(j,1,n)
    {
        int x = p[j];
        if (!ch.count(x)) {
            cout << "-1\n";
            return;
        }
        ch.erase(x);
        dist[x] = dist[b[x]];
        int need = mxdist - dist[x];
        dist[x] += need + 1;
        w[x] = need + 1;
        mxdist = max(dist[x], mxdist);
        for (int c: g[x]) ch.insert(c);
    }



    bool pos = 1;
    L(i,0,n) pos = pos && dist[i] != oo;
    if (!pos) {
        cout << "-1\n";
        return;
    }
    L(i,0,n) cout << w[i] << " ";
    cout << "\n";
    // L(i,0,n) cout << dist[p[i]] << " ";
    // cout << "\n";
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
    }
}