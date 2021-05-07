#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

const int maxn = 1e5+10;

int a[maxn];

void solve() {
    int n; cin >> n;
    a[0] = 1e9+7;
    a[n+1] = a[0];
    int b = 1, e = n;
    while(1) {
        int mid = b + (e-b)/2;
        if(a[mid] == 0) {
            cout << "? " << mid << endl;
            cout.flush();
            cin >> a[mid];
        }
        if(a[mid-1] == 0) {
            cout << "? " << mid-1 << endl;
            cout.flush();
            cin >> a[mid-1];
        }
        if(a[mid+1] == 0) {
            cout << "? " << mid+1 << endl;
            cout.flush();
            cin >> a[mid+1];
        }

        if(a[mid] < a[mid-1] && a[mid] < a[mid+1]) {
            cout << "! " << mid << endl;
            cout.flush();
            exit(0);
        }

        if(a[mid-1] < a[mid]) {
            e = mid; continue;
        } 
        if(a[mid+1] < a[mid]) {
            b = mid+1; continue;
        }           
    }
}

signed main() {
    fast int t = 1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}
