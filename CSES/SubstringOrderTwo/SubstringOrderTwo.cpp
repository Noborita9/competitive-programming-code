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

const int N =1e5 +10;
struct state {int len,link;map<char,int> next;}; //clear next!!
state st[2 * N]; // Important 2 * n
ll cnt[2 * N], dp[2 * N];
bool is_clone[2 * N];
int sz,last;
void sa_init(){
	last=st[0].len=0;sz=1;
	st[0].link=-1;
	cnt[0] = 0;
}
void sa_extend(char c){
	int k=sz++,p;
	st[k].len=st[last].len+1;
	cnt[k] = 1;
	is_clone[k] = 0;
	for(p=last;p!=-1&&!st[p].next.count(c);p=st[p].link)st[p].next[c]=k;
	if(p==-1)st[k].link=0;
	else {
		int q=st[p].next[c];
		if(st[p].len+1==st[q].len)st[k].link=q;
		else {
			int w=sz++;
			st[w].len=st[p].len+1;
			st[w].next=st[q].next;st[w].link=st[q].link;
			is_clone[w] = 1;
			cnt[w] = 0;
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
	for (const char c: s) sa_extend(c);
	vec<int> ord(sz);iota(ALL(ord),0);
	sort(ALL(ord), [&](int a, int b){
		return st[a].len > st[b].len;
	});
	for (int u: ord) if (st[u].link != -1){
		cnt[st[u].link] += cnt[u];
	}
	auto cdp = [&](auto && dfs, int u) -> void {
		if (dp[u]) return;
		dp[u] = u > 0 ? cnt[u] : 0;
		for (auto [c, v]: st[u].next) {
			dfs(dfs, v);
			dp[u] += dp[v];
		}
	};
	cdp(cdp, 0);
	auto findK = [&](auto && dfs, int u, ll kth, string & out) -> void {
		if (u != 0) {
			if (cnt[u] >= kth) {
				cout << out << "\n";
				exit(0);
			}
			kth -= cnt[u];
		}
		for (auto [c, v]: st[u].next){
			if (dp[v] >= kth) {
				out += c;
				dfs(dfs, v, kth, out);
				return;
			} else kth -= dp[v];
		}
	};
	string out = "";
	findK(findK, 0, k, out);
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