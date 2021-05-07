#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;
    int last = int(sqrt(x))+1;
    long long sum = 0;
    for(int i = 1; i <= last; i++) {
        int start = i*(i+2);
        if(x < start) break;
        int add = (x-start)/i + 1;
        int allowed = y - (i+1) + 1;
        if(allowed <= 0) break;
        sum += min(add, allowed);
    }
    cout << sum << "\n";
}

signed main() {
    fast int t;
    cin >> t;
    while(t--) solve();
    return 0;
}