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

pair<bool, ll> isperfect(ll n) {
    ll underoot = (ll)sqrt(n);
    for(ll i = underoot; i*i <= n; i++) {
        if(n%i == 0) {
            if(n/i == i) return {1, i};
        }
    }
    return {0, underoot};
}

void solve() {
    ll a, b, c;
    cin >> a >> b >> c; 
    if(a > b) swap(a, b);
    if(b > c) swap(b, c);
    if(a > c) swap(a, c);
    ll square = c*c + (b-a)*(b-a);
    pair<bool, ll> e = isperfect(square); 
    if(e.ff) cout << e.ss << "\n";
    else cout << e.ss + 1 << "\n";
}

int main() {
    fast
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}