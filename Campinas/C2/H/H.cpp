#include <bits/stdc++.h>
using namespace std;

#define L(i,j,n) for (int i = (j); i < (int)n; i ++)
#define pb push_back
#define vec vector
#define SZ(x) int(x.size())
#define ALL(x) begin(x),end(x)

using ll = long long;
using ld = long double;

const int A_CLOCK = 1;
const int A_COUNTER = 2;
const int V_CLOCK = 3;
const int V_COUNTER = 4;
const int NOTHING = 0;

void solve()
{
    ll n; cin >> n;
    ll a, b; cin >> a >> b;
    a --; b--;
    vec<ll> t(7);
    const ll oo = (ll)1e18;
    L(i,0,6) cin >> t[i + 1];
    auto greed = [&](ll A, ll B) -> ll {
        ll dist1 = max(A,B)-min(A,B);
        ll dist2 = n - dist1;
        ll ans = oo;
        // cout << dist1 << " - " << dist2 << "\n";
        if (B > A) {
            // ClockWise dist1 ClockWise
            ans = min(ans, dist1 * t[1]);
            ans = min(ans, dist2 * t[2]);
            ans = min(ans, dist2 * t[3]);
            ans = min(ans, dist1 * t[4]);
        } else {
            // CounterClockWise
            ans = min(ans, dist2 * t[1]);
            ans = min(ans, dist1 * t[2]);
            ans = min(ans, dist1 * t[3]);
            ans = min(ans, dist2 * t[4]);
        }
        return ans;
    }; 

    auto tog = [&](ll A, ll B) -> ll {
        ll dist1 = (max(A,B)-min(A,B));
        ll dist2 = (n - dist1);
        dist1 = (dist1 + 1) / 2;
        dist2 = (dist2 + 1) / 2;
        ll ans = oo;
        // cout << dist1 << " - " << dist2 << "\n";
        if (B > A) {
            // ClockWise dist1 ClockWise
            ans = min(ans, dist1 * t[5] + greed((A + dist1) % n, (B - dist1 + n) % n));
            ans = min(ans, dist2 * t[6] + greed((A - dist2 + n) % n, (B + dist2) % n));
        } else {
            // CounterClockWise
            ans = min(ans, dist2 * t[5] + greed((A + dist2) % n, (B - dist2 + n) % n));
            ans = min(ans, dist1 * t[6] + greed((A - dist1 + n) % n, (B + dist1) % n));
        }
        return ans;
    };

    ll out = greed(a, b);

    out = min(out, tog(a, b));

    for (auto a_mv: {NOTHING, A_CLOCK, A_COUNTER}) {
        for (auto v_mv: {NOTHING, V_CLOCK, V_COUNTER}) {
            ll pos = 0;
            ll na = a;
            ll nb = b;
            if (a_mv == NOTHING){}
            else if (a_mv == A_CLOCK){pos += t[a_mv]; na = (a + 1)%n;}
            else if (a_mv == A_COUNTER){pos += t[a_mv]; na = (a + n - 1)%n;}
            
            if (v_mv == NOTHING){}
            else if (v_mv == V_CLOCK){pos += t[v_mv]; nb = (b + 1)%n;}
            else if (v_mv == V_COUNTER){pos += t[v_mv]; nb = (b + n - 1)%n;}

            out = min(out, pos + tog(na, nb));
        }
    }
    
    cout << out << "\n";
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    cin >> TT;
    while(TT--)
    {
        solve();
    }
}