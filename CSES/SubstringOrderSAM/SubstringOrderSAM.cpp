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

struct state {int len,link;map<char,int> next;}; //clear next!!
const int N = 1e5 + 10;
state st[2 * N]; // Important 2 * n
ll dp[2 * N];
int sz,last;
void sa_init(){
	last=st[0].len=0;sz=1;
	st[0].link=-1;
}
void sa_extend(char c){
	int k=sz++,p;
	st[k].len=st[last].len+1;
	for(p=last;p!=-1&&!st[p].next.count(c);p=st[p].link)st[p].next[c]=k;
	if(p==-1)st[k].link=0;
	else {
		int q=st[p].next[c];
		if(st[p].len+1==st[q].len)st[k].link=q;
		else {
			int w=sz++; // Is clone should not be counted!!!
			st[w].len=st[p].len+1;
			st[w].next=st[q].next;st[w].link=st[q].link;
			for(;p!=-1&&st[p].next[c]==q;p=st[p].link)st[p].next[c]=w;
			st[q].link=st[k].link=w;
		}
	}
	last=k;
}

void solve()
{
    string s; cin >> s;
    ll k; cin >> k;
    int n = SZ(s);
    sa_init();
    for (char c: s) sa_extend(c);
    // int it = last;
    // while (it != 0) {
    //     dp[it] = 1;
    //     it = st[it].link;
    // }
    vec<int> ord(sz);
    iota(ALL(ord), 0);
    sort(ALL(ord), [&](int a, int b){return st[a].len > st[b].len;});
    for (int u: ord){
        dp[u] = u == 0 ? 0 : 1;
        for (auto [cr, v]: st[u].next) {
            dp[u] += dp[v];
        }
    }
    // for (int v: ord) cout << dp[v] << " ";
    // cout << "\n";
    vec<char> out;
    out.reserve(n);

    auto findK = [&](auto && dfs, int u, vec<char> &c) -> void {
        if (u != 0) {
            k --;
            if (k <= 0) return;
        }
        for (auto [cr, v]: st[u].next) {
            if (dp[v] >= k) {
                c.pb(cr);
                dfs(dfs, v, c);
                return;
            } else k -= dp[v];
        }
    };
    // cout << "st a: " << dp[st[0].next['a']]  << "\n";
    findK(findK, 0, out);
    for (char c: out) cout << c;
    cout << "\n";
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