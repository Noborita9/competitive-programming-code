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

void solve()
{
    int X; cin >> X;
    int q; cin >> q;
    indexed_set<pair<int,int>> ixs;
    map<int,int> C;
    ixs.insert({X,C[X]++});
    while(q--)
    {
        ll a, b; cin >> a >> b;
        ixs.insert({a,C[a]++});
        ixs.insert({b,C[b]++});
        auto it = ixs.find_by_order(SZ(ixs) / 2);
        cout << it->first << "\n";
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