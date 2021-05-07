#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #define input freopen("test_output.txt","r",stdin);
// #define output freopen("pro_output.txt","w",stdout);
using namespace std;

const int maxn = 1e5+10;

int ans;
int cs = 1;
int p = 1e9+7;
int a[maxn], diff[maxn];
vector<pair<int, int>> diff_suffix(maxn), diff_prefix(maxn);

//       --------   COMMENT FREOPEN   ----------
void solve() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    if(n == 2) {
        cout << "Case #" << cs++ << ": " << 2 << "\n";
        return;
    }

    if(n == 3) {
        cout << "Case #" << cs++ << ": " << 3 << "\n";
        return;
    }

    for(int i = 1; i < n; i++) {
        diff[i] = a[i] - a[i-1];
    }

    diff_suffix[n-1] = {diff[n-1], 1};
    for(int i = n-2; i >= 1; i--) {
        if(diff[i] == diff[i+1]) {
            diff_suffix[i] = {diff_suffix[i+1].first, diff_suffix[i+1].second+1};
        }
        else {
            diff_suffix[i] = {diff[i], 1};
        }
    }

    diff_prefix[1] = {diff[1], 1};
    for(int i = 2; i <= n-1; i++) {
        if(diff[i] == diff[i-1]) {
            diff_prefix[i] = {diff_prefix[i-1].first, diff_prefix[i-1].second+1};
        }
        else {
            diff_prefix[i] = {diff[i], 1};
        }
    }


    ans = max(diff_suffix[2].second+2, diff_prefix[n-2].second+2);

    for(int i = 1; i < n-1; i++) {
        // ith value is changed

        // suffix result 
        int temp1, change1 = -p, temp2, change2 = -p;
        if(i+2 < n) {
            temp1 = diff_suffix[i+2].second+1;
            change1 = diff[i+1] - diff[i+2];
            ans = max(ans, temp1 + ((diff[i] + change1) == diff[i+2]) + 1);
        }

        // prefix result
        if(i-1 >= 1) {
            temp2 = diff_prefix[i-1].second+1;
            change2 = diff[i-1] - diff[i];
            ans = max(ans, temp2 + ((diff[i+1] - change2) == diff[i-1]) + 1);
        }
        
        if(change1 == change2 && change1 != -p && a[i-1]+2*(change1+a[i] - a[i-1]) == a[i+1]) {
            ans = max(ans, temp1 + temp2 + 1);
        }
    }

    cout << "Case #" << cs++ << ": " << ans << "\n";

}

signed main() {
    fast int t;
    // output
    cin >> t;
    while(t--) solve();
    return 0;
}