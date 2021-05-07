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
const int maxn = 1e5 + 1;
 
void solve() {
    int a[6];
    for(int i = 0; i < 6; i++) cin >> a[i];    
    int n; cin >> n;
    int b[n];
    vpi diff;
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 6; j++) diff.pb({b[i] - a[j], i});
    }
    sort(diff.begin(), diff.end());

    int ind[n];
    memset(ind, -1, sizeof(ind));
    multiset<int> J;
    int tot = 0;
    int ans = p;
    for(int i = 0; i < diff.size(); i++) {
        if(ind[diff[i].ss] == -1) {
            tot++;
            ind[diff[i].ss] = diff[i].ff;
            J.insert(diff[i].ff);
        }
        else {
            J.erase(J.find(ind[diff[i].ss]));
            J.insert(diff[i].ff);
            ind[diff[i].ss] = diff[i].ff;
        }
        if(tot == n) {
            ans = min(ans, *J.rbegin() - *J.begin());
        }
    }
    cout << ans;
}
 
int main() {
    fast
    int t = 1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}