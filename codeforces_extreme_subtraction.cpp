#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cint.tie(0); cout.tie(0);
#define int long long 

using namespace std;

const int maxn = 1e5+1;

int a[maxn];

void solve() {
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    bool poss = true;
    int ind = -1;
    for(int i = 1; i < n; i++) {
        if(a[i] > a[i-1]) {
            ind = i;
            break;
        }
    }

    if(ind == -1) cout << "YES\n";
    else {
        int maxsub = a[ind-1];
        for(int i = ind+1; i < n; i++) {
            maxsub = min(a[i]-a[i-1]+maxsub, maxsub);
            if(maxsub < 0) {
                poss = false;
                break;
            }
        }

        if(poss) cout << "YES\n";
        else cout << "NO\n";
    }
}

signed main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}