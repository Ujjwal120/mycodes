#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int maxn = 1e5+10;

int n;
map<int, int> a;

void solve() {
    cin >> n;
    a.clear();
    int sum = 0;
    // a.resize(n);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x] += x;
        sum += x;
    }

    int m = -1;
    for(auto x : a) {
        m = max(x.second, m);
    }

    cout << sum - m << "\n";
}

signed main() {
    fast int t;
    cin >> t;
    while(t--) solve();
    return 0;
}