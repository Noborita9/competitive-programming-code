#include <stdio.h>
#include <iostream>
#include <vector>
#include <iomanip>
#include <set>
#include <cmath>
#include <cstring>
using namespace std;

#define L(i, j, n) for (int i = (j); i < (int)n; i ++)
#define SZ(x) int((x).size())
#define ALL(x) begin(x),end(x)
#define vec vector
#define pb push_back
#define eb emplace_back
#define ll long long
#define ld double
const ld EPS = 1e-6;
const ld oo = 1e9;

int n;
struct iii {
    int u, v;
    ld w;
};
int get_hash(const char x0, const char x1) {
    return (x0-'a') * 26 + (x1-'a');
}
bool check(const ld p, const vec<int> &ins, const vec<iii> &E, const int ln, const int N){
    vec<ld> dist(N, oo);
    L(i,0,SZ(ins)) if (ins[i]) dist[i] = 0;
    L(k_,0,N - 1) {
        bool done = true;
        L(i,0,ln) {
            int u = E[i].u;
            int v = E[i].v;
            ld w = E[i].w;
            if (dist[u] == oo) continue;
            if (dist[v] > dist[u] + (p - w)) {
                dist[v] = dist[u] + (p - w);
                done = false;
            }
        }
        if (done) break;
    }
    
    L(i,0,ln) {
        int u = E[i].u;
        int v = E[i].v;
        ld w = E[i].w;
        if (dist[u] == oo) continue;
        if (dist[v] > dist[u] + (p - w)) {
            return true;
        }
    }
    return false;
};
const int SN =1010;
char s[SN];

void solve()
{
    vec<iii> E;
    ld lo = 0;
    ld hi = 0;
    int N = 26 * 26;
    vec<int> ins(N);
    L(i,0,n){
        scanf("%s", s);
        int ln = strlen(s);
        if (ln < 2) continue;
        const ld sz = (ld)ln;
        hi = max(hi, sz);
        E.push_back({get_hash(s[0], s[1]), get_hash(s[ln - 2], s[ln - 1]), sz});
        ins[get_hash(s[0], s[1])] = 1;
    }
    int ln = SZ(E);
    ld ans = -1;
    const ld MEPS = 1e-2;
    while (abs(lo - hi) > MEPS){
        ld m = (lo + hi) / 2.0;
        if (check(m, ins, E, ln, N)) {
            ans = m;
            lo = m;
        } else {
            hi = m;
        }
    }
    if (abs(ans + 1) < EPS) return void(printf("No solution.\n"));
    else printf("%.2f\n", ans);
}


int main()
{
    // ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    //cin >> TT;
    while (1)
    {
        scanf("%d", &n); if (n==0)break;
        solve();
    }
}