#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

using namespace std;
const int maxn = 1e5+1;

int X[maxn], Y[maxn], startX[maxn];

int cnt = 1;

void solve() {
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> X[i] >> Y[i];
    sort(Y, Y + n);
    sort(X, X + n);
    int medianY = Y[n/2];
    int ans = 0;
    for(int i = 0; i < n; i++) ans += abs(Y[i]-medianY);
    for(int i = 0; i < n; i++) {
        startX[i] = X[i]-i;
    }
    sort(startX, startX + n);
    int shuru = startX[n/2];
    for(int i = 0; i < n; i++) {
        ans += abs(shuru - X[i]);
        shuru++;
    }
    cout << "Case #" << cnt << ": " << ans << "\n";
    cnt++;
}

signed main() {
    fast int t; cin >> t;
    while(t--) solve();
    return 0;
}