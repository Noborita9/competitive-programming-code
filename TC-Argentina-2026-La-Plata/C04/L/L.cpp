#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <random>

using namespace std;

struct Point {
    double x, y;
};

double dist(Point a, Point b) {
    return hypot(a.x - b.x, a.y - b.y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    clock_t start_time = clock();

    int n;
    double r;
    if (!(cin >> n >> r)) return 0;

    vector<Point> pts(n);
    for (int i = 0; i < n; ++i) {
        cin >> pts[i].x >> pts[i].y;
    }

    if (n == 1) {
        cout << 1 << "\n";
        return 0;
    }
    if (n == 2) {
        if (dist(pts[0], pts[1]) <= 2.0 * r + 1e-9) {
            cout << 2 << "\n";
        } else {
            cout << 1 << "\n";
        }
        return 0;
    }

    mt19937 rng(1337);
    int max_ans = 1;
    
    // Check pairs just in case the optimal circle only has 2 points on the boundary
    for(int i=0; i<n; ++i) {
        for(int j=i+1; j<n; ++j) {
            if (dist(pts[i], pts[j]) <= 2.0 * r + 1e-9) {
                max_ans = max(max_ans, 2);
            }
        }
    }

    while ((double)(clock() - start_time) / CLOCKS_PER_SEC < 3.4) {
        int i = rng() % n;
        int j = rng() % n;
        int k = rng() % n;
        
        if (i == j || i == k || j == k) continue;

        double x1 = pts[i].x, y1 = pts[i].y;
        double x2 = pts[j].x, y2 = pts[j].y;
        double x3 = pts[k].x, y3 = pts[k].y;

        double D = 2 * (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
        
        if (abs(D) < 1e-9) continue;

        double ux = ((x1 * x1 + y1 * y1) * (y2 - y3) + (x2 * x2 + y2 * y2) * (y3 - y1) + (x3 * x3 + y3 * y3) * (y1 - y2)) / D;
        double uy = ((x1 * x1 + y1 * y1) * (x3 - x2) + (x2 * x2 + y2 * y2) * (x1 - x3) + (x3 * x3 + y3 * y3) * (x2 - x1)) / D;

        Point center = {ux, uy};
        double circum_r = dist(center, pts[i]);

        if (circum_r <= r + 1e-9) {
            int current_count = 0;
            for (int idx = 0; idx < n; ++idx) {
                if (dist(center, pts[idx]) <= r + 1e-9) {
                    current_count++;
                }
            }
            if (current_count > max_ans) {
                max_ans = current_count;
            }
        }
    }

    cout << max_ans << "\n";
    return 0;
}