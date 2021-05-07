// Google Kickstart B

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
const int maxn=1e4+2;
int a[maxn];

int main() {
    fast 
    // input output
    int t; cin >> t; 
    for(int T = 1; T <= t; T++) {
        int N; cin >> N;
        for(int i=0;i<N;i++) cin>>a[i];
        vi dp(4); 
        for(int i=1;i<N;i++) {
            vi new_dp(4);
            for(int j=0; j<4; j++) new_dp[j] = p;
            for(int j=0; j<4; j++) {
                for(int z=0; z<4; z++) {
                    int rule_break = 0; 
                    if(j == z && a[i] != a[i-1]) rule_break = 1;
                    if(j > z && a[i] <= a[i-1]) rule_break = 1;
                    if(j < z && a[i] >= a[i-1]) rule_break = 1;
                    new_dp[j] = min(new_dp[j], dp[z] + rule_break);
                }
            }
            dp = new_dp;
        }
        cout<<"Case #"<<T<<": "<< min({dp[0], dp[1], dp[2], dp[3]}) << "\n";       
    }
    return 0;
}