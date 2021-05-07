
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

void solve() {
    int n; cin >> n;
    int a[n]; 
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << 1 << " " << 1 << "\n";
    cout << -a[0] << "\n";
    a[0] = 0;
    cout << 1 << " " << n << "\n"; 
    for(int i = 0; i < n; i++) cout << 1LL * (n-1) * a[i] << " ";
    cout << "\n";
    cout << 1 << " " << n << "\n";
    for(int i = 0; i < n; i++) cout << -1LL * (n) * a[i] << " ";
    cout << "\n";
}

int main() {
    fast
    int t = 1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}