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
    ll l, r, k; cin >> l >> r >> k;
    // ll ans = 0;
    bool poss = false;
    ll m = 1e18;
    for(ll power = 1; power <= r; ) {
        if(power >= l && power <= r) {
            cout << power << " "; poss = true;
        }
        if(power <= m/k) power *= k;
    }
    if(! poss) cout << -1;
}

int main() {
    fast
    int t = 1;
    //  cin >> t;
    while(t--) solve();
    return 0;
}