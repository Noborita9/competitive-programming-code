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

struct ST {
    vec<ll> st; int k;
    ST(int n): k(1){
        while(k<n)k<<=1;
        st.assign(2*k,0);
    }
    void clear() {
        L(i,0,SZ(st))st[i]=0;
    }
    void upd(int i, ll w){
        st[i+=k]+=w;
        while(i>>=1)st[i] = st[2*i]+st[2*i+1];
    }
    ll query(int l, int r){
        ll ans = 0;
        for(l+=k,r+=k;l<r;l>>=1,r>>=1){
            if(l&1)ans+=st[l++];
            if(r&1)ans+=st[--r];
        }
        return ans;
    }
};

void solve()
{
    int n, b; ll r, w; cin >> n >> b >> r >> w;
    vec<ll> dist(b);
    L(i,0,b){
        cin >> dist[i];
        if (i > 0) dist[i] += dist[i - 1];
    }
    vec<int> s(n);
    L(i,0,n){
        cin >> s[i];s[i] --;
    }
    ST st(b);
    ST ct(b);
    auto check = [&](ll t) -> bool {
        ll buses = 1;
        ll curTime = 0;
        ll curDist = 0;
        ll mx = -1;
        unordered_map<int,int> P;
        st.clear();
        ct.clear();
        L(i,0,n){
            if (s[i] > mx) {
                mx = s[i];
                curTime += dist[s[i]] - curDist;
                curDist = dist[s[i]];
            }
            if (!P[s[i]]) {
                curTime += ct.query(s[i], b) * w * 2LL; // every person that keeps going has to in/out here
                st.upd(s[i],1); // add this stop
            }
            curTime += (st.query(0, s[i]) + 1) * w * 2LL; // on every stop in/out
            ct.upd(s[i], 1); // add this person
            P[s[i]] ++;
            if (curTime > t) {
                mx = s[i];
                curDist = dist[s[i]];
                curTime = curDist + 2 * w + buses*r;
                buses ++;
                if (curTime > t) return false;
                for (const auto &[k, x]: P) {
                    st.upd(k, -1);
                    ct.upd(k, -x);
                }
                P.clear();
                st.upd(s[i], 1);
                ct.upd(s[i], 1);
                P[s[i]] ++;
            }
        }
        return true;
    };
    const ll oo = 1e16;
    ll lo = 0;
    ll hi = oo;
    ll ans = oo;
    while(lo <= hi) {
        ll md = lo + ((hi - lo) / 2);
        if (check(md)){
            ans = md;
            hi = md - 1;
        } else lo = md + 1;
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