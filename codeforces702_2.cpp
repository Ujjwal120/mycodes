#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

const int maxn = 2e5+10;

map<int, pair<int, bool>> val;
int a[maxn];
vector<int> prefix, inde;

void solve() {
    int n; cin >> n;
    val.clear();
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        val[a[i]].first++;
    }

    prefix.resize(val.size(), 0);

    int ind = 0;
    for(auto i : val) prefix[ind++] = i.first*i.second.first;

    for(int i = 1; i < prefix.size(); i++) prefix[i] += prefix[i-1];

    prev(val.end())->second.second = 1;

    auto it = prev(val.end());
    
    for(int i = prefix.size()-2; i >= 0; i--) {
        if(it->first > prefix[i]) { break; }
        it = prev(it);
        it->second.second = 1;
    }

    inde.clear();

    for(int i = 0; i < n; i++) {
        if(val[a[i]].second) inde.push_back(i+1);
    }
    
    cout << inde.size() << "\n";
    for(int x : inde) cout << x << " ";
    cout << "\n";
}

signed main() {
    fast int t;
    cin >> t;
    while(t--) solve();
    return 0;
}