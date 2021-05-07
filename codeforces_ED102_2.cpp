#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int maxn = 1e5+10;

int n, m;
string s;
vector<pair<int, int>> l, r;
vector<int> a;

void pre() {
    l.resize(n); r.resize(n); a.resize(n+1);
    a[0] = 0;
    r[n-1] = {0, 0};

    for(int i = 1; i <= n; i++) {
        if(s[i-1] == '+') a[i] = a[i-1]+1;
        else a[i] = a[i-1]-1;
    }
    
    if(n != 1) {
        if(s[n-1] == '+') r[n-2] = {0, 1};
        else r[n-2] = {-1, 0};
    }

    for(int i = s.length()-3; i >= 0; i--) {
        if(s[i+1] == '+') {
            if(r[i+1].first != 0) {
                r[i] = {r[i+1].first+1, r[i+1].second+1};
            }
            else r[i] = {0, r[i+1].second+1};
        }
        else {
            if(r[i+1].second != 0) {
                r[i] = {r[i+1].first-1, r[i+1].second-1};
            }
            else r[i] = {r[i+1].first-1, 0};
        }
    }

    int mmin = 1e9+7, mmax = -mmin;
    for(int i = 0; i < n; i++) {
        mmin = min(mmin, a[i]);
        mmax = max(mmax, a[i]);
        l[i] = {mmin, mmax};
    }
}

void solve() {
    cin >> n >> m >> s;
    pre();
    for(int i = 0; i < m; i++) {
        int x, y;; cin >> x >> y;
        x--; y--; 
        int lower = (r[y].first + a[x] > l[x].first) ? l[x].first : r[y].first+a[x];
        int higher = (r[y].second + a[x] > l[x].second) ? r[y].second+a[x] : l[x].second;
        cout << higher-lower+1 << "\n";
    }
}

signed main() {
    fast int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}