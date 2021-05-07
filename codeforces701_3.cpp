#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int a[501][501];

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cin >> a[i][j];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if((i+j)&1) cout << "720720 ";
            else cout << 720720 + a[i][j]*a[i][j]*a[i][j]*a[i][j] << " "; 
        }
        cout << "\n";
    }
}

signed main() {
    fast int t = 1; 
    // cin >> t;
    while(t--) solve();
}