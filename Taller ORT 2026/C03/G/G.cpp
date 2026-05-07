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
    vec<ll> dp(10, -1);
    dp[0] = 0;
    L(i,0,n)
    {
        int k; cin >> k;
        vec<int> o, t, e;
        L(j,0,k)
        {
            int c; ll d; cin >> c >> d;
            if (c == 1) o.pb(d);
            else if (c == 2) t.pb(d);
            else e.pb(d);
        }
        sort(ALL(o), greater<ll>());
        sort(ALL(t), greater<ll>());
        sort(ALL(e), greater<ll>());
        vec<pair<ll, int>> cards;
        L(j,0,min(3, SZ(o))) cards.pb({o[j], 1});
        if (SZ(e) >= 1) cards.pb({e[0], 3});
        if (SZ(t) >= 1) cards.pb({t[0], 2});
        vec<ll> ndp(ALL(dp));
        auto sim = [&](vec<pair<ll,int>> &deck, int from) -> void {
            // play my cards from this stance
            sort(ALL(deck));
            do {
                int cur = from;
                ll acc = 0;
                int cost = 0;
                for (auto [c, coi]: deck) 
                {
                    if (cost + coi > 3) break;
                    cost += coi;
                    cur ++;
                    ll dmg = c;
                    if (cur == 10)
                    {
                        cur = 0;
                        dmg *= 2;
                    }
                    ndp[cur] = max(ndp[cur], dp[from] + dmg + acc);
                    acc += dmg;
                }
            } while (next_permutation(ALL(deck)));
        };
        L(j,0,10) if (dp[j] != -1) 
        {
            sim(cards, j);
        }
        dp.swap(ndp);
    }
    cout << *max_element(ALL(dp)) << "\n";
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