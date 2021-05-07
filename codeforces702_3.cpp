#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #define int long long

using namespace std;

const int maxn = 2e5+10;

map<int, int> freq;
map<int, int> freq_freq;
vector<int> prefix_cnt;

void solve() {
    freq.clear();
    prefix_cnt.clear();
    freq_freq.clear();

    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        freq[x]++;
    }

    for(auto i : freq) {
        freq_freq[i.second]++;
    }
    
    for(auto i : freq_freq) {
        prefix_cnt.push_back(i.second); 
    }

    for(int i = prefix_cnt.size()-2; i >= 0; i--) {
        prefix_cnt[i] += prefix_cnt[i+1];
    }

    int ans = -1;
    int ind = 0;
    for(auto i : freq_freq) {
        ans = max(ans, prefix_cnt[ind++]*(i.first));
    }

    cout << n-ans << "\n";
}

signed main() {
    fast int t;
    cin >> t;
    while(t--) solve();
    return 0;
}






