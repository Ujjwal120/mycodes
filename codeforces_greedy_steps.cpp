#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #define int long long

using namespace std;

const int maxn = 1e5+1;
const int prime = 1e9+7;

int cum[maxn];

void solve() {
    int n, p, k; cin >> n >> p >> k;
    string s; cin >> s;
    int costadd, costrem;
    cin >> costadd >> costrem;

    memset(cum, 0, n*sizeof(int));

    for(int i = n-1; i >= 0; i--) {
        if(s[i] == '0') {
            cum[i]++;
            if(i-k >= 0) cum[i-k] = cum[i];
        }
        else {
            if(i-k >= 0) cum[i-k] = cum[i];
        }
    }

    int ans = prime;

    for(int i = p-1; i < n; i++) {
        int temp = (i-p+1)*costrem + cum[i]*costadd;
        ans = min(ans, temp);
    }
    cout << ans << "\n";
}

signed main() {
    fast int t; cin >> t;
    while(t--) solve();
    return 0;
}