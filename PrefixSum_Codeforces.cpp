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
 
const int p = 1e9+7;
const int maxn = 1e5 + 1; 
vl big, small;
 
void solve() {
    int n, d, m; cin >> n >> d >> m;
    big.clear(); small.clear();
    big.pb(0); small.pb(0);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if(x > m) big.pb(x);
        else small.pb(x);
    }
    
    int b = (int)big.size() - 1;
    int s = (int)small.size() - 1;
    
    if(b == 0) {
        ll ans = 0;
        for(int i = 0; i <= s; i++) ans += small[i];
        cout << ans << "\n";
    }
    else {
        sort(big.begin()+1, big.end());
        reverse(big.begin()+1, big.end());
        sort(small.begin()+1, small.end());
        reverse(small.begin()+1, small.end());
        
        for(int i = 1; i <= b; i++) big[i] += big[i-1];
        for(int i = 1; i <= s; i++) small[i] += small[i-1];

        small.resize(n+1, small[s]);
        
        ll ans = 0;
        
        for(int i = (b+d)/(d+1); i <= b; i++) {
            if( 1LL*(i-1)*(d+1) + 1 <= n) {
                ans = max(ans, big[i] + small[n - 1LL*(i-1)*(d+1) - 1]);
            }
        }
        
        cout << ans << "\n";
    }
}
 
int main() {
    fast
    int t = 1; 
    // cin>>t;
    while(t--) solve();
    return 0;
}