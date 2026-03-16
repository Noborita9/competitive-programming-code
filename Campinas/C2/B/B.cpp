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

vec<vec<string>> R = {
    {"M","MM", "MMM"},
    {"C","CC", "CCC", "CD","D","DC","DCC", "DCCC", "CM"},
    {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
    {"I","II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}
};

const int I = 7;
string RL = "IVXLCDM";

struct ACvertex {
	map<char,int> next,go;
	int p,link;
	char pch;
    int dep;
	vec<int> leaf;
	ACvertex(int p_=-1, char pch_=-1):p(p_),link(-1),pch(pch_), dep(0){}
};
vec<ACvertex> t;
void aho_init(){ //do not forget!!
	t.clear();t.pb(ACvertex());
}
void add_string(string &s, int id){
	int v=0;
	for(char c:s){
		if(!t[v].next.count(c)){
			t[v].next[c]=t.size();
			t.pb(ACvertex(v,c));
		}
		v=t[v].next[c];
	}
	t[v].leaf.pb(id);
}
int go(int v, char c);
int get_link(int v){ // Failure link
	if(t[v].link<0)
		if(!v||!t[v].p)t[v].link=0;
		else t[v].link=go(get_link(t[v].p),t[v].pch);
	return t[v].link;
}
int go(int v, char c){ // state = go(state, ch) this state is ACvertex id
	if(!t[v].go.count(c))
		if(t[v].next.count(c))t[v].go[c]=t[v].next[c];
		else t[v].go[c]=v==0?0:go(get_link(v),c);
	return t[v].go[c];
}
void mark(int u, int d) {
    t[u].dep = d;
    for (const auto &[k, v]: t[u].next) {
        mark(v, d + 1);
    }
}

const ll MOD = 998244353ll;

ll binPow(ll a, ll b){
    ll res = 1;
    while (b > 0){
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

ll divi(ll a, ll b){
    return (a * binPow(b, MOD -2)) % MOD;
}

const int N = 4000;
const int K = 16;
ll dp[2][N][K];

void load(int i, string g) {
    if (i == 4) {
        add_string(g, -1);
        // cout << g << "\n";
        return;
    }
    load(i + 1, g);
    for (const string &s: R[i]) {
        load(i + 1, g + s);
    }
}


void solve()
{
    int n; cin >> n;
    aho_init();
    load(0, "");
    mark(0, 0);
    // Ahora lo que quiero armar es computar los largos 
    // dp[cur/next][stado][largo]
    // L(i,0,N){
    //     dp[0][i][0] = 1;
    // }
    dp[0][0][0] = 1;
    L(i, 0, n) {
        int cur = i % 2;
        int next = 1 - cur;
        L(j,0,N)L(k,0,K) dp[next][j][k] = 0;
        L(j, 0, N) L(k,0,K) if (dp[cur][j][k]) {
            L(l,0,I) {
                int v = go(j, RL[l]);
                if (t[v].leaf.empty()){
                    dp[next][v][k] += dp[cur][j][k];
                    dp[next][v][k] %= MOD;
                } else {
                    dp[next][v][max(k, t[v].dep)] += dp[cur][j][k];
                    dp[next][v][max(k, t[v].dep)] %= MOD;
                }
            }
        }
    }

    ll ans = 0;
    int cur = n % 2;
    L(i,0,N) {
        ll temp = 0;
        L(j,0,K){
            temp += (dp[cur][i][j] * j) % MOD;
            temp %= MOD;

        }
        // cout << temp << "\n";
        ans += temp;
        ans %= MOD;
    }
    ll dv = divi(1, binPow(7, n));
    // cout << "Dv: " << dv << "\n";
    ans = (ans * dv)% MOD;
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