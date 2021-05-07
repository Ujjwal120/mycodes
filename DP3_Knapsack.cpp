// low on constraints of W ~ 1e5 but high on v ~ 1e9

// here DP[i][j] = max_value

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

void solve() {
    int N, W, w[N+1], v[N+1]; cin>>N>>W; 
    for(int i=1;i<=N;i++) {
        cin>>w[i]>>v[i];
    }
    
    ll DP[N+1][W+1]; 
    for(int i=0; i<=N; i++) DP[i][0] = 0;
    for(int i=0; i<=W; i++) DP[0][i] = 0;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=W; j++) {
            if(w[i] <= j) DP[i][j] = max(v[i] + DP[i-1][j-w[i]], DP[i-1][j]);
            else DP[i][j] = DP[i-1][j];
        }
    }
    cout<<DP[N][W]<<"\n";
}

int main() {
    fast 
    // input output
    int t=1; 
    // cin>>t; 
    while(t--) solve();
    return 0;
}