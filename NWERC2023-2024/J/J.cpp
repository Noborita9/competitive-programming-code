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

const ld PI = acos(-1.0);

struct Point {
    ld x, y;
};

void solve()
{
    int n;
    if (!(cin >> n)) return;

    vec<Point> pts(n);
    L(i, 0, n) {
        cin >> pts[i].x >> pts[i].y;
    }

    vec<ld> angles;
    
    // Extract all critical angles
    L(i, 0, n) {
        L(j, 0, n) {
            if (i == j) continue;
            
            ld dy = pts[j].y - pts[i].y;
            ld dx = pts[j].x - pts[i].x;
            ld theta = atan2(dy, dx);
            
            // Normalize the angle to [0, PI/2) to avoid testing redundant rotations
            while (theta < 0) theta += PI / 2.0;
            while (theta >= PI / 2.0) theta -= PI / 2.0;
            
            angles.pb(theta);
        }
    }

    ld min_tour_length = 1e18; // Infinity placeholder

    // Test each optimal grid orientation
    for (ld theta : angles) {
        ld c = cos(theta);
        ld s = sin(theta);

        // Precompute the distance matrix for this specific rotation
        vec<vec<ld>> dist(n, vec<ld>(n, 0.0));
        
        L(i, 0, n) {
            L(j, 0, n) {
                if (i == j) continue;
                
                ld dx = pts[i].x - pts[j].x;
                ld dy = pts[i].y - pts[j].y;
                
                ld new_dx = dx * c + dy * s;
                ld new_dy = -dx * s + dy * c;
                
                dist[i][j] = abs(new_dx) + abs(new_dy);
            }
        }

        ld current_angle_best_tour = 1e18;

        
        const ld oo = 1e18;
        vec<vec<ld>> dp(1 << n, vec<ld>(n, oo));
        L(i,0,n) dp[1<<i][i] = 0.0;
        int masks = 1<< n;
        L(mask, 0, masks) {
            L (i, 0, n) if (mask & (1 << i)) {
                L(j,0, n) if(i != j && (mask & (1<<j))==0) {
                    int nmask = mask | (1 << j);
                    dp[nmask][j] = min(dp[nmask][j], dp[mask][i] + dist[i][j]);
                }
            }
        }
        L(i,0,n) current_angle_best_tour = min(current_angle_best_tour, dp[masks - 1][i]);


        min_tour_length = min(min_tour_length, current_angle_best_tour);
    }

    // Output with required precision
    cout << fixed << setprecision(12) << min_tour_length << "\n";
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