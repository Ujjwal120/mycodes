// Knapsack on W ~ 1e9 and smaller v

// DP[i][j] = min weight   herer max possible value = N * 1000 = 1e5

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
const int maxn=1e5+1;
ll DP[100][maxn];

void solve() {
    int N, W; cin>>N>>W;
    int w[N], v[N];  
    for(int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= 100000; j++) DP[i][j] = p;
    } 
    DP[0][0] = 0;
    DP[0][v[0]] = w[0]; 
    for(int i = 1; i < N; i++) {
        DP[i][0] = 0;
        for(int j = 0; j <=100000; j++) {
            // discard the weight
            
            DP[i][j] = DP[i-1][j];
            
            // pick the weight
            if(j >= v[i]) DP[i][j] = min(DP[i][j], w[i] + DP[i-1][j - v[i]]);
        }    
    }
    int ans = 0;
    for(int i = 100000; i >= 0; i--) {
        if(DP[N-1][i] <= W) {
            ans = i; break;
        }
    }
    cout << ans << "\n";
}

int main() {
    fast 
    // input output
    int t = 1; 
    // cin>>t; 
    while(t--) solve();
    return 0;
}