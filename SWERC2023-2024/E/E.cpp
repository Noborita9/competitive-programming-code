#include <bits/stdc++.h>
#include <cassert>
using namespace std;

// #define LOCAL
#define L(i, j, n) for(int i = (j); i < int(n); i ++)
#define R(i, j, n) for (int i = (j); i >= (int)n; i --)
#define ll long long
#define ld long double
#define ii pair<ll, int>
const int mod = 1e9 + 7;

void solve()
{
   int n; cin >> n;
   vector<ll> x(n + 2);
   L(i, 0, n){
    cin >> x[i + 1];
   }
   stack<ii> st;
   long double bd = 0.0; 
   ll X = 0, D = 0;
   ll lst = 0;
   string res = "0";
   auto sim = [&]() -> void {
        st = stack<ii>();
        L(i, 1, n + 1)
        {
            ll dist = x[i] - x[i-1]; 
            while(!st.empty()){
                if (x[i] < x[i-1]) break;
                auto &[nm, id] = st.top();
                ll ev = min(nm, x[i]);
                ll hi = ev - x[i]; // Altura
                assert(dist > 0);
                ld curh = hi / (ld)dist;
                ld lon = (i) + curh; // Largo
                ld xpos = (ld)(i) + curh; // 
                if (xpos - (ld)id > bd){
                    bd = xpos - (ld)id;
                    D = dist;
                    X = hi;
                    ll gc = gcd(D, X);
                    D /= gc;
                    X /= gc;
                    X += D * (i - id);
                    // cout << "From: " << (id) << " " << ()  
                }
                // cout << i << ": " << x[i] << " " << x[i-1] << ' ' <<bd << " " << xpos << " " << curh << '\n';
                if ((ld)st.top().first > xpos) break;
                else st.pop();
            } 
            st.push({x[i], i});
        }
   };
   cout << "Pre Run" << endl;
   sim();
   cout << "Post Run" << endl;
   reverse(begin(x), end(x));
//    cout << "Pre Re Run" << endl;
//    sim();
//    cout << "Post Re Run" << endl;

   if (X == 0) {
    cout << "0\n";
    return;
   }
   cout << X << "/" << D << '\n';
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    // cin >> TT;
    while (TT--)
    {
        solve();
    }
}
