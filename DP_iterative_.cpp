#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define input freopen("1.txt","r",stdin);
#define output freopen("output.txt","w",stdout);
#define ll long long int
#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define vi vector<int>
#define vii vector<vi>
#define vl vector<ll>
#define vll vector<vl>
#define pii pair<int, int>
#define pll pair<ll,ll>
#define mp make_pair
#define vpi vector<pii>
#define vpl vector<pll> 
#define ss second 
#define ff first
 
using namespace std;
 
const int p = 1e9+7;
const int maxn = 1e5 + 1;

void solve() {
    int n, k; cin >> n >> k;
    string s, t; cin >> s >> t;
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n+1, vector<int>(n+1, -p)));
    dp[0][0][0] = 0;

    for(int i = 0; i < n; i++) {
        for(int ck = 0; ck <= k; ck++) {
            for(int cnt0 = 0; cnt0 <= n; cnt0++) {
                if(dp[i][ck][cnt0] == -p) continue;
                int e0 = s[i] == t[0];
                int e1 = s[i] == t[1];
                int e01 = t[0] == t[1];

                // don't change
                dp[i + 1][ck][cnt0 + e0] = max(dp[i + 1][ck][cnt0 + e0], dp[i][ck][cnt0] + (e1 ? cnt0 : 0));
                if(ck < k) {
                    // change to t0 forcefully
                    dp[i + 1][ck + 1][cnt0 + 1] = max(dp[i + 1][ck + 1][cnt0 + 1], dp[i][ck][cnt0] + (e01 ? cnt0 : 0));
                    // change to t1 forcefully
                    dp[i + 1][ck + 1][cnt0 + e01] = max(dp[i + 1][ck + 1][cnt0 + e01], dp[i][ck][cnt0] + cnt0);
                }
            }
        }
    }  

    int ans = 0;
    for(int cnt0 = 0; cnt0 <= n; cnt0++) {
        ans = max(ans, dp[n][k][cnt0]);
    } 

    cout << ans;
}
 
int main() {
    fast
    int t = 1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}