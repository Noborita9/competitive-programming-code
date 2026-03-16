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

using my_clock = chrono::steady_clock;
struct Random {
	mt19937_64 engine;
	Random(): engine(my_clock::now().time_since_epoch().count()) {}
	template<class Int>Int integer(Int n) {return integer<Int>(0, n);} // `[0,n)`
	template<class Int>Int integer(Int l, Int r)
		{return uniform_int_distribution{l, r-1}(engine);} // `[l,r)`
	double real() {return uniform_real_distribution{}(engine);} // `[0,1)`
} rng;

void solve()
{
    int n, k; cin >> n >> k;
    if (k > n){
        L(i,0,k) cout << i + 1<< " ";
        cout << "\n";
        return;
    }
    vec<int> a(n); 
    L(i,0,n) {
        cin >> a[i];
        a[i]--;
    }
    int times = (int)1e6;
    L(i,0,times) {
        vec<int> used(k);
        vec<int> perm(k);
        L(j,0,k){
            int x = rng.integer(k);
            while(used[x]) x = rng.integer(k);
            used[x] = 1;
            perm[j] = x;
        }
        int j = 0;
        L(w,0,n) {
            if (j == k) break; // found
            if (a[w] == perm[j]) j ++;
        }
        if (j != k) {
            L(w,0,k) cout << perm[w]+1 << " ";
            cout << "\n";
            exit(0);
        }
    }    
    cout << "*\n";
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