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

ll mul(ll a, ll b) {
    ll r = a*b;
    if(r >= p) return r%p;
    return r;
}

ll add(ll a, ll b) {
    return (a+b >= p) ? (a+b-p) : (a+b);
}

void solve() {
    string s;
    cin >> s;
    ll sz = s.length();
    ll l = 0, acc = 0, ans = 0, ten = 1, prevten = -1;
    for(ll i = sz-1; i >= 0; i--, l++, ten = mul(ten, 10)) {
        ans = add(ans, mul(s[i]- '0', mul(i*(i+1)/2, ten)));
        acc = add(acc, mul(l, prevten));
        ans = add(ans, mul(acc, s[i] - '0'));
        prevten = ten;
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
