#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #define int long long 

using namespace std;

const int maxn = 1e5 + 10;
const int p = 1e9 + 7;

int n, m, mat[101][101];

void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cin >> mat[i][j];
    }

    // cout << "\n";
    bool even = 0;

    for(int i = 0; i < n; i++) {
        bool start = even;
        for(int j = 0; j < m; j++) {
            if(start == 0 && mat[i][j]%2 != 1) mat[i][j] += 1;
            else if(start == 1 && mat[i][j]%2 != 0) mat[i][j] += 1;
            cout << mat[i][j] << " ";
            start ^= 1;
        }
        cout << "\n";
        even ^= 1;
    }
}

signed main() {
    fast int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}