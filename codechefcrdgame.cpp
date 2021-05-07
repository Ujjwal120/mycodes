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

inline int mul(int a, int b) {
    ll r = a * 1ll * b;
    if(r >= p) return r%p;
    return r; 
}

inline int sub(int a, int b) { return (a-b < 0 ? a-b+p : a-b); }

int taakat (int x, int y) {
    ll r = 1;
    while(y) {
        if(y & 1) r = mul(x, r);
        y >>= 1; x = mul(x, x);
    }
    return r;
}

void solve() {
    int n; cin >> n;
    int a[n]; 
    for(int i = 0; i < n; i++) cin >> a[i];
    int ans = taakat(2, n);
    sort(a, a+n);
    int ind = lower_bound(a, a+n, a[n-1]) - a;
    int bigcount = n - ind;
    if(bigcount & 1) cout << ans << "\n";
    else {
        int bad = taakat(2, n-bigcount);
        int fact = 1;
        for(int i = 1; i <= bigcount; i++) {
            fact = mul(fact, i);
            if(i == bigcount/2) { 
                int inv = taakat(fact, p-2);
                inv = mul(inv, inv);
                bad = mul(bad, inv);
            }
        }
        bad = mul(fact, bad);
        cout << sub(ans, bad) << "\n";
    }
}

int main() {
    fast
    int t; cin >> t;
    while(t--) solve();
    return 0;
}