#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int maxn = 1e5+10;

void solve() {
    int n, k; cin >> n >> k;
    int diff = n-k;
    for(int i = 1; i < k-diff; i++) cout << i << " ";
    for(int i = k; i >= k-diff; i--) cout << i << " "; 
    cout << "\n";
}

signed main() {
    fast int t; cin >> t;
    while(t--) solve();
    return 0;
}