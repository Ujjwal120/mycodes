#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long 
using namespace std;

const int maxn = 1e5+1;

void solve() {
    int n, m; cin >> n >> m;
    int a[n][m];
    int ans = 0, neg = 0, smallest = 1e9;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            if(a[i][j] < 0) neg++;
            a[i][j] = abs(a[i][j]);
            ans += a[i][j];
            smallest = min(smallest, a[i][j]);
        }
    }
    // cout << neg << "\n";
    if(neg&1) {
        // cout << ans << " " << smallest << "\n";
        cout << ans - 2*smallest << "\n";
    }
    else cout << ans << "\n";
}

signed main() {
    fast int t; cin >> t;
    while(t--) solve();
    return 0;
}
