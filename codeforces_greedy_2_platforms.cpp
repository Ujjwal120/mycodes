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
 
const int p = 1e9+7;
const int maxn = 2e5 + 2; 

int x[maxn], n, k;
vi dist, cnt, ksum;

void solve() {
    cin >> n >> k;
    int y;
    for(int i = 0; i < n; i++) cin >> x[i]; 
    for(int i = 0; i < n; i++) cin >> y;
    
    sort(x, x+n);
    dist.clear(); cnt.clear(); ksum.clear();
    cnt.pb(1); 
    dist.pb(x[0]);
   
    for(int i = 1; i < n; i++) {
        if(x[i] == dist.back()) {
            cnt[cnt.size()-1]++;
        }    
        else {
            dist.pb(x[i]);
            cnt.pb(1);
        }
    }

    vi presum;
    for(int i = 0; i < dist.size(); i++) {
        if(presum.size() == 0) presum.pb(cnt[i]);
        else presum.pb(presum.back()+cnt[i]);
    }
    
    if(x[n-1] - x[0] < 2*k) cout << n << "\n";
    else {
        vi ind;
        int sz = dist.size();
        for(int i = 0; i < sz; i++) {
            int x = upper_bound(dist.begin(), dist.end(), dist[i]+k) - dist.begin();
            ind.pb(x);
            ksum.pb(presum[x-1]);
            if(i != 0) ksum[ksum.size()-1] -= presum[i-1];
        }
        
        int ans = -p;
        vi maxans(sz);
        maxans[sz-1] = ksum[sz-1];
        for(int i = sz-2; i >= 0; i--) {
            maxans[i] = max(maxans[i+1], ksum[i]);
        }

        for(int i = 0; i < sz; i++) {
            if(ind[i] < sz) ans = max(ans, ksum[i] + maxans[ind[i]]);
            else ans = max(ans, ksum[i]);
        }

        cout << ans << "\n";
    }
}
 
int main() {
    fast
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}