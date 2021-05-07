#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int maxn = 1e5+1;

vector<int> a[maxn<<1];

void solve() {
    int n, x; cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x;
        a[x].push_back(i);
    }

    int ans = maxn*10;

    for(int i = 1; i <= n; i++) {
        if(a[i].empty()) continue;
        
        int temp;
        if(a[i][0] != 0) temp = 1;
        else temp = 0;
        
        int sz = a[i].size();
        for(int j = 0; j < sz-1; j++) {
            temp += (a[i][j] + 1 == a[i][j+1]) ? 0 : 1;
        }

        if((a[i][sz-1] != n-1) && n != 1) temp++;

        ans = min(ans, temp);
    }
    
    cout << ans << "\n";
    for(int i = 1; i <= n; i++) a[i].clear();
}

signed main() {
    fast int t; cin >> t;
    while(t--) solve();
    return 0;
}