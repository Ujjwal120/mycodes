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
using namespace std;
 
const int p=1e9+7;
const int maxn=1e5+2;

void solve() {
    // int n; cin >> n;
    ll x1, y1, z1, x2, y2, z2;
    cin >> x1 >> y1 >> z1;
    cin >> x2 >> y2 >> z2;
    if(z2 > x1) {
        int nt = min(x1+z1, z2);
        if(nt != x1+z1) {
            ll tl = z1 - (z2 - x1);
            tl = min(tl, y2);
            cout << tl * 2 << "\n"; 
        }
        else {
            ll tl = z2 - x1 - z1;
            cout << -1 * tl * 2 << "\n";
        }
    } 
    else {
        int tl = min(z1, y2);
        cout << tl * 2 << "\n";
    }
}

int main() {
    fast  // input output
    int t; cin>>t; 
    while(t--) solve();
    return 0;
}