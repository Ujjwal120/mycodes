#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #define input freopen("test_output.txt","r",stdin);
// #define output freopen("pro_output.txt","w",stdout);
using namespace std;

const int maxn = 1e5+10;

const int p = 1e9+10;

int cs = 1;
vector<int> a;
map<int, int> mp;

void solve () {
    int n, k;
    cin >> n >> k;
    mp.clear();
    a.clear();

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        mp[x] = 1;
    }

    for(auto x : mp) {
        a.push_back(x.first);
    }

    
    int f = 0, s = 0;
    
    for(int i = 0; i < a.size(); i++) {
        if(i == 0 && a[i] == 1) continue;

        if(i == 0 && a[i] != 1) {
            int w = a[i]-1;
            f = w;
            continue;
        }

        if(a[i] - a[i-1] < 2) continue;

        int w = a[i] - a[i-1] - 1;
        int tempf;
        
        tempf = (w%2 == 0) ? w/2 : w/2 + 1;

        if(tempf < f) {
            s = max(tempf, s);
        }
        else {
            s = max({s, f, w - tempf});
            f = max(f, tempf);
        }
    }

    // cout << f << " " << s << "\n";

    if(a[a.size()-1] != k) {
        int posib = k-a[a.size()-1];
        if(posib < f) {
            s = max(posib, s);
        }
        else {
            s = max(s, f);
            f = max(f, posib);
        }
    }

    double ans = double(s+f) / double(k); 
    cout << "Case #" << cs++ << ": ";
    cout << fixed << setprecision(7) << ans << "\n";
}

signed main() {
    fast int t;
    cin >> t;
    while(t--) solve();
    return 0;
}