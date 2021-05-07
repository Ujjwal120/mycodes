#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

const int maxn = 1e5+1;

int presum[23], mag[23];

int cnt = 1;

int deal(int x) {
    vector<int> dig;
    while(x) {
        dig.push_back(x%10);
        x /= 10;
    }

    reverse(dig.begin(), dig.end());

    int ans = (dig.size() > 0) ? presum[dig.size()-1] : 0; 
    int ptr = dig.size()-1;
    bool odd = true;
    for(int i = 0; i < dig.size(); i++) {
        if(dig[i]%2 == 0 && odd) {
            ans += (dig[i]/2)*mag[ptr];
            break;
        }
        if(dig[i]%2 != 0 && !odd) {
            ans += (dig[i]/2+1)*mag[ptr];
            break;
        }

        ans += (dig[i]/2)*mag[ptr];
        if(i == dig.size()-1) {
            ans += 1;
        }

        odd ^= 1;
        ptr--;
    }

    return ans;
}

void solve() {
    int l, r; cin >> l >> r;
    cout << "Case #" << cnt << ": " << deal(r) - deal(l-1) << "\n";
    cnt++;
}

signed main() {
    fast int t;
    cin >> t;
    mag[0] = 1;
    for(int i = 1; i <= 19; i++) {
        mag[i] = mag[i-1]*5;
        presum[i] = presum[i-1] + mag[i]; 
    }
    while(t--) solve();
    return 0;
}