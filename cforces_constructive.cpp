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
    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    sort(a.rbegin(), a.rend());
    vi b(n);
    int ind = n/2 + (n&1);
    int ptr = 0, ans = 0, e = n-1;
    if(n&1) e--; 
    
    for(int i = 0; i < ind; i++) {
        b[2*i] = a[i];
    }
    
    for(int i = ind; i < n; i++) {
        if(ptr+1 < ind) {
            if(a[i] < a[ptr] && a[ptr+1] > a[i]) { 
                b[2*ptr+1] = a[i];
                ans++; 
                ptr++; 
            }
            else {
                b[e] = a[i]; e-=2;
            }
        }
        else {
            b[e] = a[i]; e-=2;
        }
    }

    cout << ans << "\n";
    for(int i = 0; i < n; i++) cout << b[i] << " ";
    cout << "\n";
}

int main() {
    fast
    int t = 1; 
    while(t--) solve();
    return 0;
}