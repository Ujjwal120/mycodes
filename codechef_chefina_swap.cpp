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
const int maxn = 1e6;

ll nC2(ll n) {
    if(n >= 2) return n*(n-1)/2;
    return 0;
}

ll presum(ll n){
    return n*(n+1)/2;
}

void solve() {
    ll n; cin >> n;
    ll sum = presum(n);
    if(sum&1) cout << "0" << endl;
    else {
        ll half = sum/2;
        int beg = 1, end = n;
        int mid = beg + (end-beg)/2;

        while(beg <= end) {
            if(presum(mid) == half) break;
            if(presum(mid) > half) end = mid;
            else beg = mid;
            
            int new_mid = beg + (end-beg)/2;
            if(new_mid == mid) break;
            else mid = new_mid;
        }

        ll ans = n - mid;
        if(presum(mid) == half) ans += nC2(mid) + nC2(n-mid);
        cout << ans << endl;
    }
}

int main() {
    fast
    int t; cin >> t;
    while(t--) solve();
    return 0;
}