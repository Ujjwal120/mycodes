#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int maxn = 1e5 + 10;
int n;

void solve() {
    cin >> n;
    int x = 0;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        x ^= a;
    }
    if(n&1) {
        cout << "YES\n";
        cout << n-2 << "\n";
        for(int i = 0; i < n-2; i += 2) {
            cout << i+1 << " " << i+2 << " " << i+3 << "\n"; 
        }
        for(int i = 0; i < n-3; i += 2) {
            cout << i+1 << " " << i+2 << " " << n << "\n";
        } 
    }
    else {
        // calculate total xor
        if(x != 0) {
            cout << "NO\n";
            return;
        }

        cout << "YES\n";
        cout << n-3 << "\n"; 
        for(int i = 0; i < n-3; i += 2) {
            cout << i+1 << " " << i+2 << " " << i+3 << "\n";
        }
        for(int i = 0; i < n-4; i += 2) {
            cout << i+1 << " " << i+2 << " " << n-1 << "\n"; 
        }
    }
}

signed main() {
    fast int t = 1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}