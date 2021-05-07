#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<int> a;
int cs = 0;

void solve() {
    int n; cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    for(int i = 0; i < n-1; i++) {
        int m = a[i], ind = i;
        for(int j = i+1; j < n; j++) {
            if(a[j] < m) {
                m = a[j]; ind = j;
            }
        }
        ans += ind-i+1;
        reverse(a.begin()+i, a.begin()+ind+1);
    }
    cout << "Case #" << ++cs << ": " << ans << "\n";
}

signed main() {
    fast int t;
    cin >> t;
    while(t--) solve();
}