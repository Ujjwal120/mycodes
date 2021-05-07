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
    int N, K; cin >> N >> K;
    int h[N]; 
    for(int i = 0; i < N; i++) cin >> h[i];
    int DP[N];
    for(int i = 1; i < N; i++) DP[i] = INT_MAX;
    DP[0] = 0;
    for(int i = 1; i < N; i++) {
       for(int j = 1; j <= K; j++) {
           if(i-j >= 0) {
               DP[i] = min(DP[i], DP[i-j] + abs(h[i] - h[i-j]));
           }
           else break;
       }
    }
    cout << DP[N-1] << "\n";
}

int main() {
    fast 
    // input output
    int t=1; 
    // cin>>t; 
    while(t--) solve();
    return 0;
}