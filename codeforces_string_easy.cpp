#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve() {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    for(int i = 0; i < q; i++) {
        bool poss = false;
        int l, r; cin >> l >> r;
        l--; r--;
        for(int j = l-1; j >= 0; j--) {
            if(s[j] == s[l]) {
                poss = true; break;
            }
        }
        // cout << poss << "\n";

        if(!poss) {
            for(int j = r+1; j < n; j++) {
                if(s[j] == s[r]) {
                    poss = true;
                    break;
                }
            }
        }

        if(poss) cout << "YES\n";
        else cout << "NO\n";
    }
}

signed main() {
    fast int t; cin >> t;
    while(t--) solve();
    return 0;
}