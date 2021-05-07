#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long 

using namespace std;
const int maxn = 1e5+1;
const int p = 1e9+7;
const int p_ = 998244353;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    bool bad = false;
    char cur = s[0];
    for(int i = 0; i < n; i++) {
        if(cur != s[i]) {
            bad = true;
        }
        else {
            if(bad) {
                ans++;
                bad = false;
            }
        }

        if(i == n-1 && bad) ans++; 
        if(cur == '0') cur = '1';
        else cur = '0';
    }    
    cout << ans << "\n";
}

signed main() {
    fast int t;
    cin >> t; 
    while(t--) solve();
    return 0;
}
