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
const int maxn = 2e5 + 1;

int dp[maxn][2][2];
int a[maxn];
int n;

int rec(int pos, int turn, int cnt) {
    if(pos == n) return 0;

    if(dp[pos][turn][cnt] != -1) return dp[pos][turn][cnt];

    int ans = 0; 

    if(cnt == 0) {
        if(turn == 0) {   
            ans = min(rec(pos+1, turn, 1) + a[pos], rec(pos+1, turn^1, 0) + a[pos]);
        }
        else {
            ans = min(rec(pos+1, turn, 1), rec(pos+1, turn^1, 0));
        }
    }
    else{
        if(turn == 0) {
            ans = min(rec(pos+1, turn^1, 0) + a[pos], rec(pos, turn^1, 0)); 
        }
        else {
            ans = min(rec(pos+1, turn^1, 0), rec(pos, turn^1, 0));
        }
    }

    return dp[pos][turn][cnt] = ans;
}

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 2; j++) dp[i][j][0] = dp[i][j][1] = -1;
    }
    cout << rec(0, 0, 0) << "\n";
}

int main() {
    fast
    int t; cin >> t;
    while(t--) solve();
    return 0;
}