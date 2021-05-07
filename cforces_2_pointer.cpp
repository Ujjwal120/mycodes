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

vi cntleft, cntright, a;

void solve() {
    int n; cin >> n;
    cntleft.clear();
    cntright.clear();
    a.clear();
    a.resize(n);
    cntleft.resize(n+1, 0);
    cntright.resize(n+1, 0);
    for(int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0;
    for(int j = 1; j < n-2; j++) {
        cntleft[a[j-1]]++;
        for(int k = n-2; k > j; k--) {
            cntright[a[k+1]]++;
            ans += 1LL * cntleft[a[k]] * cntright[a[j]];
        }
        cntright.clear(); cntright.resize(n+1, 0);
    } 
    cout << ans << "\n";
}

int main() {
    fast
    // input output
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
