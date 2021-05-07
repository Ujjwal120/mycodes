#include<bits/stdc++.h>
using namespace std; 

#define ll long long 
#define pb push_back
#define ppb pop_back
#define vi vector<int> 
#define vii vector<vi>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ss second 
#define ff first

const int p = 1e9 + 7;
const int maxn = 1e5 + 1;

int a[5002], n;
int dp[5002][5002];

int rec(int ind, int depthind) {
    if(ind == n) return 0;

    if(dp[ind][depthind] != -1) return dp[ind][depthind];

    int ans = 0;
    if(a[ind] > a[depthind]) {
        ans = 1 + rec(ind+1, depthind);
        ans = min(ans, a[ind] - a[depthind] + rec(ind+1, ind));
    }
    else ans = rec(ind+1, depthind);
    return dp[ind][depthind] = ans;
}

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) dp[i][j] = -1;
    }
    cout << rec(0, n);
}

int main() {
    fast 
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
