#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long 

using namespace std;

const int maxn = 1e5+1;
const int INF = 1e9+7;

int LIS(vector<int> &a, int l, int r) {
    vector<int> magic;
    for (int x: a) {
        if(x >= l && x <= r) {
            auto it = upper_bound(magic.begin(), magic.end(), x);
            // ....... change to lower_bound for LIS
            if (it == magic.end()) magic.push_back(x);
            else *it = x;
        }
    }
    return magic.size();
}

void solve() {
    int n, k; cin >> n >> k;  
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= (i+1);
    }
    vector<int> b(k);
    for(int i = 0; i < k; i++) cin >> b[i];
    bool poss = true;
    for(int i = 1; i < k; i++) {
        if(a[b[i]-1] < a[b[i-1]-1]) {
            poss = false; break;
        }
    }

    if(poss) {  
        if(k == 0) {
            // carry out LIS on full a[]
            vector<int> x;
            for(int i = 0; i < n; i++) x.push_back(a[i]);
            cout << n - LIS(a, -INF, INF) << "\n";
            return;
        }

        int ans = 0;
        for(int i = 0; i < k; i++) {
            vector<int> x;
            if(i == 0) {
                for(int j = 0; j < b[i]-1; j++) x.push_back(a[j]);
                ans += LIS(x, -INF, a[b[i]-1]);
            }
            else {
                for(int j = b[i-1]; j < b[i]-1; j++) x.push_back(a[j]);
                ans += LIS(x, a[b[i-1]-1], a[b[i]-1]);
            }
        }

        if(b[k-1] != n) {
            vector<int> x;
            for(int i = b[k-1]; i < n; i++) x.push_back(a[i]);
            ans += LIS(x, a[b[k-1]-1], INF);
        }

        cout << n - ans - k << "\n";
    }
    else cout << "-1\n";
}

signed main() {
    fast int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}