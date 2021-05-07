// if Ans is to like maximize or minimize after a particular day without having to 
// take any consecutive same element O(N * choices^2)

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
    int N; cin >> N;
    vi DP(3);   // Three possible choices at each day 
    for(int d = 0; d < N; d++) {
        vi N_DP(3);
        vi c(3);
        for(int i = 0; i < 3; i++) cin >> c[i];
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(i != j) {
                    N_DP[j] = max(N_DP[j], DP[i] + c[j]);
                }
            }
        }
        DP = N_DP;
    }
    cout << max ({DP[0], DP[1], DP[2]}) << "\n";
}

int main() {
    fast 
    // input output
    int t=1; 
    // cin>>t; 
    while(t--) solve();
    return 0;
}