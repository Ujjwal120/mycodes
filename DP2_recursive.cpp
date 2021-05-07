// if Ans is to like maximize or minimize after a particular day without having to 
// take any consecutive same element O(N)

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
using namespace std;
 
const int p=1e9+7;
const int maxn=1e5+2;
int DP[maxn][3];
int cost[maxn][3];

void solve(int cur, int N) {
    if(cur == N) {
        cout << max({DP[N][0], DP[N][1], DP[N][2]}) << "\n";
        return; 
    }
    ++cur;
    DP[cur][0] = max(DP[cur-1][1] + cost[cur][0], DP[cur-1][2] + cost[cur][0]);
    DP[cur][1] = max(DP[cur-1][0] + cost[cur][1], DP[cur-1][2] + cost[cur][1]);
    DP[cur][2] = max(DP[cur-1][0] + cost[cur][2], DP[cur-1][1] + cost[cur][2]);
    solve(cur, N);
}

int main() {
    fast 
    // input output
    int t=1; 
    // cin>>t;  
    int N; cin >> N;
    DP[0][0] = DP[0][1] = DP[0][2] = 0;
    for(int i = 1; i <= N; i++) {
        DP[i][0] = DP[i][1] = DP[i][2] = 0;
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }
    while(t--) solve(0, N);
    return 0;
}