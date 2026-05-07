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

void solve()
{
    int n, k; cin >> n >> k;
    int mln = 0;
    string s; cin >> s;
    int ln = 1;
    char c = s[0];
    L(i,1,n) {
        if (s[i] == c) {
            ln ++;
        } else {
            if (c == '1') mln = max(mln, ln);
            ln = 1;
            c = s[i];
        }
    }
    if (c == '1') mln = max(mln, ln);
    if (mln >= k) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    deque<int> q;
    L(i,0,n) q.pb(i);
    L(i,0,n) {
        if (s[i] == '1') {
            cout << q.front()+1<<" ";
            q.pop_front();
        } else {
            cout << q.back()+1<<" ";
            q.pop_back();
        }
    }
    cout << "\n";
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
    }
}