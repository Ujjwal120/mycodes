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

const int p = 1e9 + 7;
const int maxn = 1e5 + 1;

void solve() {
    ll n, r1, r2, r3, d;
    cin >> n >> r1 >> r2 >> r3 >> d;
    ll a[n+1], dp[n+1]; 
    for(int i = 1; i <= n; i++) cin >> a[i];
    dp[0] = (n-1) * d;
    for(int i = 1; i <= n; i++) {
        ll pistol = a[i] * r1;
        pistol += min(r3, 2*r1 + d);
        ll laser = r2 + min({r1, r2, r3}) + d;
        dp[i] = dp[i-1] + min(laser, pistol);
        cout << dp[i] << " ";
    }
    cout << "\n";
    cout << dp[n];
}

int main() {
    fast
    int t = 1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}

100 5 5 9 3
// 3 4 2 3 4 3 8 5 2 1 1 4 1 1 10 10 7 5 2 9 4 2 10 10 8 2 4 9 6 2 6 7 7 5 7 7 1 8 10 9 9 3 10 3 10 1 1 8 3 6 4 5 5 4 9 5 9 4 8 2 10 8 9 1 5 9 7 2 1 7 9 3 2 9 1 5 4 2 3 10 6 7 8 2 10 1 6 2 1 6 10 9 1 2 2 7 2 8 4 4