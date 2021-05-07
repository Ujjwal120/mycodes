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
const ll m = 1e18;

vl presum;

void solve() {
    ll n; cin >> n;
    int ind = lower_bound(presum.begin(), presum.end(), n) - presum.begin();
    if(ind == presum.size()) cout << presum.size() << "\n";
    else {
        if(presum[ind] != n) {
            cout << ind << "\n";
        }
        else cout << ind + 1 << "\n";    
    }
}

int main() {
    fast
    presum.pb(1);
    for(ll i = 3; ; i = 2*i+1) {
        ll temp = presum.back();
        ll sum = i*(i+1)/2;
        if(temp >= m - sum) break;
        presum.pb(temp + sum) ;
    }
    int t; cin >> t;
    while(t--) solve();
    return 0;
}