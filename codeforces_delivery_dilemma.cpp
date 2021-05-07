#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cint.tie(0); cout.tie(0);
#define int long long 

using namespace std;

const int maxn = 1e5+1;
vector<pair<int, int>> j; 

void solve() {
    int n; cin >> n;

    j.resize(n);
    for(int i = 0; i < n; i++) cin >> j[i].first;
    for(int i = 0; i < n; i++) cin >> j[i].second;
    sort(j.rbegin(), j.rend());

    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(j[i].first <= ans) break;
        if(j[i].second + ans >= j[i].first) {
            ans = j[i].first; break;
        }
        ans += j[i].second;
    }
    cout << ans << "\n";
}

signed main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}