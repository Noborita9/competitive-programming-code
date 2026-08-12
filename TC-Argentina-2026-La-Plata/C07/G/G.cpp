#include <bits/stdc++.h>
using namespace std;
#define L(i,j,n) for(int i=j;i<int(n);i++)
#define ALL(x) begin(x),end(x)
#define SZ(x) int(x.size())
#define pb push_back
#define eb emplace_back
#define vec vector

using ll=long long;
using ld=long double;

const int N = 203;
bool dp[N][N][N][3];
bool vi[N][N][N][3];

void solve(){
    int n;cin>>n;
    string s;cin>>s;
    uint8_t G=0, R=0, B=0;
    L(i,0,n){
        if(s[i]=='R')R++;
        else if(s[i]=='G')G++;
        else B++;
    }
    vi[1][0][0][0] = 1;
    vi[0][1][0][1] = 1;
    vi[0][0][1][2] = 1;

    dp[1][0][0][0] = 1;
    dp[0][1][0][1] = 1;
    dp[0][0][1][2] = 1;
    auto go = [&](auto && rec, uint8_t r, uint8_t g, uint8_t b, uint8_t c) -> bool {
        if (vi[r][g][b][c]) return dp[r][g][b][c];
        vi[r][g][b][c] = 1;
        // cout << r << " " << g << " " << b << "\n";
        bool ans = false;
        ans = ans || (r >= 2 && rec(rec, r - 1, g, b, c));
        ans = ans || (g >= 2 && rec(rec, r, g - 1, b, c));
        ans = ans || (b >= 2 && rec(rec, r, g, b - 1, c));

        ans = ans || (r && g && rec(rec, r - 1, g - 1, b + 1, c));
        ans = ans || (g && b && rec(rec, r + 1, g - 1, b - 1, c));
        ans = ans || (r && b && rec(rec, r - 1, g + 1, b - 1, c));
        return dp[r][g][b][c] = ans;
    };
    if (go(go, R,G,B, 2)) {
        cout << "B";
    }
    
    if (go(go, R,G,B,1)) {
        cout << "G";
    }
    
    if (go(go, R,G,B,0)) {
        cout << "R";
    }
    cout << "\n";
    // if(!R && !B) cout<<"G"<<'\n';
    // else if(!B && !G) cout<<"R"<<'\n';
    // else if(!R && !G) cout <<"B"<<'\n';
    // else if(R>=1 && B>=1 && G>=1) cout<<"BGR"<<'\n';
    // else if(R>=2 && B) cout<<"BG"<<'\n';
    // else if(R>=2 && G) cout<<"BG"<<'\n';
    // else if(G>=2 && R) cout<<"BR"<<'\n';
    // else if(G>=2 && B)cout<<"BR"<<'\n';
    // else if(B>=2 && R)cout<<"GR"<<'\n';
    // else if(B>=2 && G)cout<<"GR"<<'\n';
    // else if(B&&R)cout<<"G"<<'\n';
    // else if(B&&G)cout<<"R"<<'\n';
    // else cout<<"B"<<'\n';
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int TT=1;
    // cin>>TT;
    while(TT--) solve();
}
