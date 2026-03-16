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
bool vis[2 * N];

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
    int n = SZ(s);
    sa_init();
    for (char c: s) sa_extend(c);
    auto cmp = [&](auto && dfs, int u) -> void {
        if (vis[u]) return;
        vis[u] = 1;
        dp[u] = 1;
        for (auto [c, v]: st[u].next) {
            dfs(dfs, v);
            dp[u] += dp[v];
        }
    };
    cmp(cmp, 0);
    cout << (dp[0] - 1) << "\n";
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