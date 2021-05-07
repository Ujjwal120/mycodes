#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int maxn = 1e5+10;

int a[maxn], pos[maxn], nxt[maxn];

void solve() {
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 0; i <= n; i++) pos[i] = n+1;

    for(int i = n; i >= 0; i--) {
        nxt[i] = pos[a[i]];
        pos[a[i]] = i;
    }

    int x = 0, y = 0;
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        if(a[x] == a[i]) {
            sum += a[y] != a[i];
            y = i;
        }
        else if(a[y] == a[i]) {
            sum += a[x] != a[i];
            x = i;
        }
        else if(nxt[x] < nxt[y]) {
            sum++; x = i;
        }
        else {
            sum++; y = i;
        }
    }

    cout << sum << "\n";
}

signed main() {
    fast int t = 1;
    while(t--) solve();
    return 0;
}