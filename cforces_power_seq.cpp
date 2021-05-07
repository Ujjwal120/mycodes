
// power sequence brute force
// number theory
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

ll taakat(int x, int y) {
    ll r = 1;
    while(y) {
        if(y&1) r *= x;
        y >>= 1; x *= x;
    }
    return r;
}

void solve() {
    int n; cin >> n;
    int a[n];
    ll ans = 0; 
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        ans += a[i] - 1;
    }
    int c = 2;
    sort(a, a+n);
    while(1) {
        bool b = false;
        ll pro = 1;
        ll cur = 0;
        for(int i = 0; i < n; i++) {
            cur += abs(taakat(c, i) - a[i]);
            if(cur > ans) { b = true; break; }
        }
        if(b) break;
        ans = min(ans, cur);
        c++;
    }    
    cout << ans << "\n";
}

int main() {
    fast
    int t = 1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}