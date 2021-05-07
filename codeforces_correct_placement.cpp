#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// #define int long long 
using namespace std;

const int maxn = 2e5 + 2;

int ans[maxn];
map<int, vector<pair<int, int>>> a;

vector<pair<int, int>> sp;

set<pair<int, int>> joda;

map<pair<int, int>, int> kahan;

void solve() {
    int n; cin >> n;
    a.clear();
    sp.clear();
    joda.clear();
    kahan.clear();

    for(int i = 1; i <= n; i++) ans[i] = -1;

    for(int i = 0; i < n; i++) {
        int h, w;
        cin >> h >> w;
        if(h > w) swap(h, w);
        a[h].push_back({w, i+1});
    }

    // cout << "PASS" << endl;

    for(auto x : a) {
        auto vec = x.second;
        int v = x.first;
        int m = 1e9+7, ind;
        for(int i = 0; i < vec.size(); i++) {
            if(vec[i].first < m) {
                m = vec[i].first;
                ind = vec[i].second;
            }
        }
        sp.push_back({m, v});
        joda.insert({m, v});
        kahan[{m, v}] = ind;
    }

    int ind = sp.size()-1;
    for(auto i = a.rbegin(); i != a.rend(); i++) {
        auto it = joda.erase({sp[ind]});
        auto vec = i->second;
        for(int j = 0; j < vec.size(); j++) {
            if(!joda.empty()) {
                if(joda.begin()->first < vec[j].first) {
                    ans[vec[j].second] = kahan[*joda.begin()];
                }
            }
        }
        // cout << "PAAASS" << endl;
        ind--;
    }

    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << "\n";
}

signed main() {
    fast int t;
    cin >> t;
    while(t--) solve();
    return 0;
}