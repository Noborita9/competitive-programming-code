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

const int N = 2e6 + 5;
struct state {int len,link;int next[26]; state(){memset(next,-1,sizeof(next));}}; //clear next!!
state st[2 * N]; // Important 2 * n
int sz,last;
void sa_init(){
	last=st[0].len=0;sz=1;
	st[0].link=-1;
}
void sa_extend(char c){
	int k=sz++,p;
	st[k].len=st[last].len+1;
	for(p=last;p!=-1&&-1==st[p].next[c-'a'];p=st[p].link)st[p].next[c-'a']=k;
	if(p==-1)st[k].link=0;
	else {
		int q=st[p].next[c-'a'];
		if(st[p].len+1==st[q].len)st[k].link=q;
		else {
			int w=sz++; // Is clone should not be counted!!!
			st[w].len=st[p].len+1;
            L(ni,0,26)st[w].next[ni]=st[q].next[ni];
			st[w].link=st[q].link;
			for(;p!=-1&&st[p].next[c-'a']==q;p=st[p].link)st[p].next[c-'a']=w;
			st[q].link=st[k].link=w;
		}
	}
	last=k;
}


void solve()
{
    string s; cin >> s;
    sa_init();
    for (const char c: s) sa_extend(c);
    for (const char c: s) sa_extend(c);
    int v = 0;
    int n = SZ(s);
    L(i,0,n){
        L(j,0,26) if (st[v].next[j] != -1){
            cout << (char)('a'+j);
            v = st[v].next[j];
            break;
        }
    }
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