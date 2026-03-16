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

const int N = 2e5 + 10;
struct state {int len,link;map  <char,int> next;}; //clear next!!
state st[N * 2];
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
			int w=sz++;
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
    sa_init();
    for (const char c: s) sa_extend(c);
    int q; cin >> q;
    while(q--)
    {
        string p;cin>> p;
        int op = 0;
        int j = 0;
        while (j < SZ(p)) {
            op ++;
            int v = 0;
            while(j < SZ(p)){
                if (!st[v].next.count(p[j])) break; // could not find transition
                v = st[v].next[p[j]];
                j ++;
            }
            if (v == 0) break;
        }
        if (j < SZ(p)){
            cout << "-1\n";
        } else {
            cout << op << "\n";
        }
    }
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