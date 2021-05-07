#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int maxn = 1e5 + 10;
const int p = 1e9+7;

int n, a[maxn], bit[maxn];

int cal(int x) {
    int b = 0;
    while(x) {
        b++;
        x >>= 1;
    }
    return b;
}

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) bit[i] = cal(a[i]);

    if(n == 2) {
        cout << -1 << "\n";
        return;
    }

    bool same = false;
    for(int i = 1; i < n-1; i++) {
        if(bit[i] == bit[i-1] && bit[i] == bit[i+1]) {
            same = true; break;
        }
    }

    if(same) cout << "1\n";
    else {

        int ans = p;
        
        int xorl[100], xorr[100];
        xorl[n-1] = a[n-1]; xorr[0] = a[0];
        for(int i = 1; i < n; i++) {
            xorr[i] = xorr[i-1]^a[i];
        }

        for(int i = n-2; i >= 0; i--) {
            xorl[i] = xorl[i+1]^a[i];
        }

        for(int l = 0; l < n-1; l++) {
            for(int r = l+1; r < n; r++) {
                int xorpart = xorr[n-1] ^ ((r < n-1) ? xorl[r+1] : 0);
                for(int m = l; m < r; m++) {
                    int sec = xorpart ^ xorr[m];
                    int one = xorpart ^ ((l > 0) ? xorr[l-1] : 0) ^ sec;
                    if(one > sec) ans = min(ans, r-l-1);
                }
            }
        }

        if(ans == p) cout << "-1\n";
        else cout << ans << "\n";
    }
}

signed main() {
    fast int t = 1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}