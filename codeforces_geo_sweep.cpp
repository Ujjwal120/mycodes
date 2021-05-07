#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long 
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pii pair<int, int>
#define ss second
#define ff first

const int maxn = 1e6+1;
const int p = 1e9+7;

void solve() {
    int n, m; cin >> n >> m;
    vector<pii> thief(n), spot(m); 
    for(int i = 0; i < n; i++) cin >> thief[i].ff >> thief[i].ss;
    for(int i = 0; i < m; i++) cin >> spot[i].ff >> spot[i].ss;

    int sweeph[maxn];
    memset(sweeph, -1, sizeof(sweeph));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int x = spot[j].ff - thief[i].ff;
            int y = spot[j].ss - thief[i].ss;
            if(thief[i].ff <= spot[j].ff && thief[i].ss <= spot[j].ss) {
                sweeph[x] = max(sweeph[x], y);
            }
        }
    }

    // sweep

    int curh = -p;
    int ans = p;

    for(int i = maxn-1; i >= 0; i--) {
        if(sweeph[i] == -1 || sweeph[i] <= curh) {
            if(curh == -p) continue;
        }
        else {
            if(curh == -p) ans = i+1;
            curh = sweeph[i]; 
        }
        
        ans = min(ans, i+curh+1);
    }

    if(curh == -p) cout << "0\n";
    else cout << ans << "\n";
}

int main() {
    fast 
    int t = 1; 
    while(t--) solve();    
    return 0;
}