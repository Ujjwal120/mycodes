#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 

using namespace std;

int cs = 0;

void solve() {
    int n, k;
    cin >> n >> k;
    string s; cin >> s;
    int non_equal = 0;
    for(int i = 0 ; i < n/2; i++) {
        if(s[i] != s[n-i-1]) non_equal++;
    }
    cout << "Case #" << ++cs << ": " << abs(k - non_equal) << "\n"; 
}

signed main() {
    fast int t;
    cin >> t;
    while(t--) solve();
    return 0;
}