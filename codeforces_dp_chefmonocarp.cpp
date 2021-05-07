#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

const int maxn = 100000;

void solve() {
    int n; cin >> n;
    vector<vector<int>> dp(n+1, vector<int> (2*n+1, maxn));
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a, a+n);
    dp[0][0] = 0;
    
    for(int i = 0; i < n+1; i++) {
        for(int j = 0; j < 2*n; j++) {
            if(dp[i][j] < maxn) {
                if(i < n) dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + abs(a[i] - j - 1));
		        dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
            }
        }
    }

    cout << dp[n][2*n] << "\n";
}

signed main() {
    fast int t;
    cin >> t; 
    while(t--) solve();
    return 0;
}

