#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #define int long long 

using namespace std;

int dp[5002][5002];
string s, t;

int rec(int i, int j) {
    if(i == s.length() || j == t.length()) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int best = 0;
    best = max(best, rec(i+1, j)-1);
    best = max(best, rec(i, j+1)-1);
    if(s[i] == t[j]) best = max(best, 2+rec(i+1, j+1));
    return dp[i][j] = best;
}

void solve() {
    int n, m; cin >> n >> m;
    cin >> s >> t;

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) dp[i][j] = -1;
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) ans = max(ans, rec(i,j));
    }

    cout << ans;
}

signed main() {
    fast int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}