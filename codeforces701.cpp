#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    if(a < b) cout << "1\n";
    else if(a == b) cout << "2\n";
    else{
        int cnt = 1e9+7;
        int acc = 0;
        while(1) {
            int temp = 0;
            if(b != 1) {
                int A = a;
                while(A) {
                    A /= b;
                    temp++;
                }
                if(temp+acc > cnt) break;
                cnt = temp+acc;
            }
            acc++; b++;
        }
        cout << cnt << "\n";
    }
}

signed main() {
    fast int t;
    cin >> t;
    while(t--) solve();
    return 0;
}