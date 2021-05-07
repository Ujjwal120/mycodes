#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

using namespace std;
const int maxn = 5e4+4;

int cnt = 1;

vector<string> all;

void solve() {
    int n, q; cin >> n >> q;
    all.clear();

    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        all.push_back(s);
    }

    cout << "Case #" << cnt << ": " << ans << "\n";
    cnt++;
}

signed main() {
    fast int t; cin >> t;
    while(t--) solve();
    return 0;
}