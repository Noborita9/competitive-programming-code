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


void solve()
{
    int n; cin >> n;
    vec<ll> a(n); L(i,0,n) cin >> a[i];
    ll ans = 0;
    htable<ll, ll> r3, r7;
    L(i,0,n){
        // mx 
        ans += r3[a[i] * 3] * r7[a[i] * 7];
        r3[a[i] * 5]++;
        r7[a[i] * 5]++;
    }
    r3.clear();
    r7.clear();
    for (int i = n - 1; i >= 0; i --){
        // mn
        ans += r3[a[i] * 3] * r7[a[i] * 7];
        r3[a[i] * 5]++;
        r7[a[i] * 5]++;
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