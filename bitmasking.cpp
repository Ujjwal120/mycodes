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
int n;

double dp[1<<19], chance[18][18];

double rec(int mask) {
    int zinda = __builtin_popcount(mask);
    if(zinda == n) return 1;

    if(dp[mask] > -0.5) return dp[mask];

    double a = 0.0;

    for(int f = 0; f < n; f++) {
        if(!(mask&(1<<f))) {
            int pmask = mask^(1<<f);
            double prev = rec(pmask);
            int k = __builtin_popcount(pmask);
            int den = k * (k-1) / 2;
            double num = 0;
            for(int i = 0; i < n; i++) {
                if(pmask & (1<<i)) {
                    num += chance[i][f];
                }
            }
            num /= den;
            a += prev*num;
        }
    }

    return dp[mask] = a;
}

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cin >> chance[i][j];    
    }

    for(int i = 0; i < (1<<19); i++) dp[i] = -1;

    for(int i = 0; i < n; i++) {
        cout << fixed << setprecision(10) << rec(1 << i) << " ";
    }
}

int main() {
    fast 
    // input output
    int t = 1; 
    // cin>>t; 
    while(t--) solve();
    return 0;
}