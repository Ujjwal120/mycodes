//   atleast k distinct elements in the subarray print min length 

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

const int p = 1e9+7;
const int maxn = 1e5 + 1;

map<int, bool> exist;
map<int, int> latest;
set<int> l;

void solve() {
    int n, m , k; cin >> n >> m >> k;
    int a[n], b[m]; 
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < m; i++) cin>>b[i];
    int ans = p;
    exist.clear();
    latest.clear();
    l.clear();
    if(m < k) cout << -1 << "\n";
    else {
        for(int i = 0; i < m; i++) exist[b[i]] = true;

        for(int i = 0; i < n; i++) {
            if(exist[a[i]]) {
                if(latest.count(a[i]) == 1) {
                    l.erase(latest[a[i]]);
                }
    
                l.insert(i);
                latest[a[i]] = i;
    
                if((int)l.size() >= k) {
                    if((int)l.size() > k) {
                        auto it = l.begin();
                        latest.erase( *it );
                        l.erase(l.begin());
                    }
                    
                    auto it1 = l.begin();
                    auto it2 = l.rbegin();
                    ans = min(ans, *it2 - *it1 + 1);
                }
            }
        }
    
        if(ans == p) cout << -1 << "\n";
        else cout << ans << "\n";
    }
}

int main() {
    fast
    int t = 1; 
    // cin>>t;
    while(t--) solve();
    return 0;
}