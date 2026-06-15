#include <bits/stdc++.h>
using namespace std;

const int N = 5e3;

int F[N], V[N];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n ; cin >> n;
    for (int i = 0;i < n; i ++){
        cin >> F[i];
        F[i]--;
    }
    for (int i = 0; i < n; i ++){
        if (i == F[F[F[i]]]) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}
