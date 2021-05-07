#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    int a[n], b[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    bool poss = true;
    int cnt = 0;
    for(int i = 1; i < n; i++) {
        if(a[i] < a[i-1]) {
            if(i > 1) {
                if(a[i-2] > a[i] ) {
                    // cout << "idhar 1\n";
                    poss = false;
                    break; 
                }
                else {
                    if(x >= a[i-1]) {
                        // cout << "idhar 2\n";
                        poss = false;
                        break;
                    }
                    else {
                        int s = x;
                        swap(x, a[i-1]);
                        sort(a, a+i);
                        int ind = upper_bound(a, a+i, s) - a;
                        for(int j = ind-1; j < i; j++) {
                            if(a[j] != b[j]) cnt++;
                        }
                        i--;
                    }
                }
            }
            else {
                if(x >= a[i-1]) {
                    // cout << "idhar 3\n";
                    poss = false;
                    break;
                }
                else {
                    int s = x;
                    swap(x, a[i-1]);
                    sort(a, a+i);
                    int ind = upper_bound(a, a+i, s) - a;
                    for(int j = ind-1; j < i; j++) {
                        if(a[j] != b[j]) cnt++;
                    }
                    i--;
                }
            }
        }
    }

    if(poss) cout << cnt << "\n";
    else cout << "-1\n";
}

signed main() {
    fast int t;
    cin >> t;
    while(t--) solve();
    return 0;
}