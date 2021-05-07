#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long 

using namespace std;
const int maxn = 1e5+1;
const int p = 1e9+7;
const int p_ = 998244353;

int a[2*maxn];

void solve() {
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int ans = 1, stored = 1, temp = 1, i = 2, ptr = 1;

    while(i < n) {
        if(a[i] < a[i-1]) {
            ptr++;
            if(ptr > stored) {
                ans++; stored = temp;
                temp = 0; ptr = 1;
            }
        }
        temp++; i++;
    }

    cout << ans << "\n";
}

signed main() {
    fast int t;
    cin >> t; 
    while(t--) solve();
    return 0;
}
