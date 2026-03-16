#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds;
template<typename Key, typename Val=null_type>
using indexed_set = tree<Key, Val, less<Key>, rb_tree_tag,
                         tree_order_statistics_node_update>;
// indexed_set<char> s;
// char val = *s.find_by_order(0); // acceso por indice
// int idx = s.order_of_key('a'); // busca indice del valor
template<class Key,class Val=null_type>using htable=gp_hash_table<Key,Val>;
// como unordered_map (o unordered_set si Val es vacio), pero sin metodo count

#define L(i, j, n) for (int i = (j); i < (int)n; i ++)
#define SZ(x) int((x).size())
#define ALL(x) begin(x),end(x)
#define vec vector
#define pb push_back
#define eb emplace_back

using ll = long long;
using ld = long double;
vec<ll> ms = {1'000'000'007, 1'000'000'403};
const ll b = 500'000'000;
const int N = (int)1e5+10;
ll bs[2][N];
struct StrHash {
    vec<ll> hs[2];
    StrHash(const string &s) {
        int n = SZ(s);
        L(k,0,2) {
            hs[k]=vec<ll>(n+1);
            L(i,0,n) hs[k][i + 1]=(hs[k][i]*b+s[i])%ms[k];
        }
    }
    ll get(int ix, int len) const { // [ix, ix+len)
        ll h[2];
        L(k,0,2) {
            h[k]=hs[k][ix+len] - hs[k][ix]*bs[k][len] % ms[k];
            if (h[k]<0)h[k]+=ms[k];
        }
        return (h[0]<<32)|h[1];
    }
};

const ll MOD = (ll)1e9+7ll;

void solve()
{
    string s; cin >> s;
    int n = SZ(s);
    int m; cin >> m;
    htable<ll> H; // Needed to avoid TLE
    L(i,0,m){
        string p; cin >> p;
        ll h = StrHash(p).get(0, SZ(p));
        H.insert(h);
    }
    StrHash h(s);
    vec<ll>dp(n + 1);
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i --){
        L(j,i,n) {
            int len = j - i + 1;
            ll hs = h.get(i, len);
            if (H.find(hs)!=H.end()){
                dp[i]+=dp[j + 1];
                if (dp[i] >= MOD) dp[i]%=MOD;
            }
        }
    }
    cout << dp[0] << "\n";
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    //cin >> TT;
    L(k,0,2){
        bs[k][0]=1;
        L(i,1,N)bs[k][i]=(bs[k][i-1]*b)%ms[k];
    }
    while (TT--)
    {
        solve();
    }
}