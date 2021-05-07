#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

const int maxn = 3e5+10;
int c[maxn], k[maxn];

void solve() {
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> k[i];
        k[i]--;
    }
    for(int i = 0; i < m; i++) cin >> c[i];
    sort(k, k+n);
    int present_taken = 0;
    int min_cost = 0;
    for(int i = n-1; i >= 0; i--) {
        if(present_taken >= k[i]) {
            min_cost += c[k[i]];
        }
        else {
            if(c[present_taken] < c[k[i]]) {
                min_cost += c[present_taken];
                present_taken++;
            }
            else min_cost += c[k[i]];
        }
    }

    cout << min_cost << "\n";
}

signed main() {
    fast int t;
    cin >> t;
    while(t--) solve();
    return 0;
}