#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #define int long long

using namespace std;

const int maxn = 5001;
const int mod = 1e9+7;

int dp[maxn][maxn], a[maxn], b[maxn];

int cnt[maxn], n, k, q;

int add(int a, int b) {
    return (a+b >= mod) ? (a+b-mod) : (a+b);
}

int sub(int a, int b) {
    return (a-b < 0) ? (a-b+mod) : (a-b);
}

int mul(int a, int b) {
    long long r = 1ll*a*b;
    return (r >= mod) ? r%mod : r;
}

void rec() {
    for(int i = 0; i < n; i++) dp[i][0] = 1;

    for(int j = 1; j <= k; j++) {
        dp[0][j] = dp[1][j-1];
        for(int i = 1; i < n-1; i++) {
            dp[i][j] = add(dp[i-1][j-1], dp[i+1][j-1]);
        }
        dp[n-1][j] = dp[n-2][j-1];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= k; j++) {
            cnt[i] = add(cnt[i], mul(dp[i][j], dp[i][k-j]));
        }
    }
}

void solve() {
    cin >> n >> k >> q;
    for(int i = 0; i < n; i++) cin >> a[i];
    rec();

    int tot = 0;

    for(int i = 0; i < n; i++) {
        b[i] = mul(a[i], cnt[i]);
        tot = add(tot, b[i]);
    }

    for(int i = 0; i < q; i++) {
        int ind, change;
        cin >> ind >> change; ind--;
        
        tot = sub(tot, mul(a[ind], cnt[ind]));
        a[ind] = change;
        b[ind] = mul(a[ind], cnt[ind]);
        tot = add(tot, b[ind]);
        cout << tot << "\n";
    }
}

signed main() {
    fast int t = 1;
    while(t--) solve();
    return 0;
}
