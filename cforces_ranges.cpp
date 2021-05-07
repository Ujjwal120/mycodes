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
const int maxn = 1e5 + 1;

void solve() {
    int n; cin >> n;
    ll a[n], diff[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    ll K = 0;
    ll zero = 0;
    for(int i = 1; i < n; i++) {
        diff[i] = a[i] - a[i-1];
        K += max(diff[i], zero);
    }
    
    ll ans = ceil(double(a[0]+K)/2);
    cout << ans << "\n";
    
    int q, l, r, x; cin >> q;
    
    for(int i = 0; i < q; i++) {
        cin >> l >> r >> x;
        if(l == 1) { a[0] += x; }
        else {
            ll pre = diff[l-1];
            ll now = diff[l-1] + x;
            if(pre <= 0 && now >= 0) K += now;
            else if(pre >= 0 && now <= 0) K -= pre;
            else if(pre >= 0 && now >= 0) K += now - pre; 
            
            diff[l-1] = now;
        }
        if(r != n) {
            ll pre = diff[r];
            ll now = diff[r] - x;
            if(pre <= 0 && now >= 0) K += now;
            else if(pre >= 0 && now <= 0) K -= pre;
            else if(pre >= 0 && now >= 0) K += now - pre;
            
            diff[r] = now;
        }

        ans = ceil(double(a[0]+K)/2); 
        cout << ans << "\n";
    }
}

int main() {
    fast
    int t = 1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}