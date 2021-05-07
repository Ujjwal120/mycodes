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
const int maxn = 1e5 + 5;

int dp[maxn], maxans[maxn];
vpi cord(maxn);
vi t(maxn, 0);

void solve() {
    int r, n;
    cin >> r >> n;
    for(int i = 1; i <= n; i++) {
        cin >> t[i] >> cord[i].ff >> cord[i].ss;
    }

    cord[0].ff = 1; cord[0].ss = 1;

    for(int i = 1; i <= n; i++) {
        dp[i] = -p;
        for(int j = max(i-2*r, 0); j < i; j++) {
            if(abs(cord[i].ff - cord[j].ff) + abs(cord[i].ss - cord[j].ss) <= t[i] - t[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        if(i > 2*r) dp[i] = max(dp[i], maxans[i-2*r] + 1);
        maxans[i] = max(dp[i], maxans[i-1]);
    }

    cout << maxans[n]; 
}

int main() {
    fast
    int t = 1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}