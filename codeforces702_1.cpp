#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long 
using namespace std;

const int maxn = 1e4+10;

int a[maxn];

void solve() {
    int x; cin >> x;

    bool found = false;

    for(int i = 1; (a[i] < x)&&(i < maxn); i++) {

        int b = i, e = maxn; 
        while(b < e) {
            int mid = b + (e-b)/2;
            if(a[mid] + a[i] == x) {
                found = true; break;
            }
            else if(a[mid] + a[i] < x) {
                b = mid+1;
            }
            else if(a[mid] + a[i] > x) {
                e = mid;
            }
        }

        if(found) break;
    }

    if(found) cout << "YES\n";
    else cout << "NO\n";
}

signed main() {
    fast int t;
    cin >> t;
    for(int i = 1; i < maxn; i++) {
        a[i] = i*i*i;
    }

    while(t--) solve();
    return 0;
}