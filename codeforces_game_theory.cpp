#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

void solve() {
    int d, k; cin >> d >> k;
    int xcord = 0, ycord = 0;
    d *= d;
    bool turn = 0;
    for(int i = 0; ; i++) {
        if(turn == 0) xcord += k;
        else ycord += k;
        if(xcord*xcord + ycord*ycord > d) break;
        turn ^= 1;
    }

    if(turn == 0) cout << "Utkarsh\n";
    else cout << "Ashish\n";
}

signed main() {
    fast int t; cin >> t;
    while(t--) solve();
    return 0;
}