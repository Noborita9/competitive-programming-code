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

struct card {
    int r, s;
    bool operator==(const card &rhs) const {
        return r == rhs.r && s == rhs.s;
    }
    bool operator<(const card &rhs) const {
        if (r != rhs.r) return r < rhs.r;
        return s < rhs.s;
    }
};

int P, M, N; 
void solve()
{
    vec<multiset<card>> hand(P);
    int nxt = 1;
    int curP = 0;
    int toDraw = 0;
    bool skip = 0;
    auto rotate = [&]() {
        nxt *= -1;
    };
    auto nxtP = [&](int i) {
        return (i + P + nxt) % P;
    };
    auto pass = [&]() {
        curP = nxtP(curP);
    };
    auto suitMatch = [](char c) {
        if (c == 'C') return 0;
        if (c == 'D') return 1;
        if (c == 'H') return 2;
        return 3;
    };
    auto getCard = [&]() -> card {
        if (N == 0) {
            cout << "No more cards\n";
            exit(0);
        }
        int r; char s; cin >> r >> s; r --;
        N --;
        return card{r, suitMatch(s)};
    };
    L(p,0,P) {
        L(m,0,M) {
            hand[p].insert(getCard());
        }
    }
    card top = getCard();
    auto applyStatus = [&](card c) {
        if (c.r == 0) {
            // draw 1 and skip 
            // cout << "Ace\n";
            toDraw = 1;
            skip = 1;
        } else if (c.r == 6) {
            // draw 2 and skip
            // cout << "Seven\n";
            toDraw = 2;
            skip = 1;
        } else if (c.r == 10) {
            // skip turn
            // cout << "Jack\n";
            skip = 1;
        } else if (c.r == 11) {
            // reverse
            // cout << "Queen\n";
            rotate();
        } else {
            // ... nothing...
        }
    };
    applyStatus(top);
    while (1){
        // play
        // cout << "\n";
        // cout << "Playing: " << curP << "\n";
        // cout << "On Top: " << top.r << " " << top.s << "\n";
        while(N > 0 && toDraw > 0) {
            card c = getCard();
            hand[curP].insert(c);
            // cout << "Took card: " << c.r << " " << c.s << "\n";
            toDraw --;
        }
        if (!skip) {
            // play
            card play = {-1,-1};
            for (card c: hand[curP]) {
                if (c.r == top.r || c.s == top.s) {
                    // cout << "Match: " << c.r << " " << top.r << " or " << c.s << " " << top.s << "\n";
                    play = {c.r, c.s};
                }
            }

            if (play.r == -1) {
                card c = getCard();
                if (c.r == top.r || c.s == top.s) {
                    top = c;
                    applyStatus(top);
                } else {
                    hand[curP].insert(c);
                }
            } else {
                top = play;
                // cout << "Play Card: " << top.r << " " << top.s << "\n";
                applyStatus(top);
                hand[curP].erase(hand[curP].find(top));
                if (SZ(hand[curP]) == 0) {
                    while(N>0) getCard();
                    cout << curP + 1 << "\n";
                    return;
                }
            }
        } else {
            skip = 0;
        }
        pass();
    }
    cout << "No winner\n";
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    //cin >> TT;
    while (1)
    {
        cin >> P >> M >> N;
        if (P == 0 && M == 0 && N == 0) break;
        solve();
    }
}