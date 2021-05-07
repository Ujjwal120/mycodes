#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

const int maxn = 2e5+10;

void solve(string str) {
    int count[26] = {0}, count1[26] = {0}, count2[26];
    int ans = 0;
    
    for(int i = 0; i < str.length(); i++) {
        if(str[i] >= 'a' && str[i] <= 'z') count[str[i]%97]++;
        else if(str[i] >= 'A' && str[i] <= 'Z') count1[str[i]%65]++;
        else count2[str[i]%48]++;
    }

    for(int i = 0; i < 26; i++) ans += count[i]/2 + count1[i]/2;

    for(int i = 0; i < 10; i++) ans += count2[i]/2;
    cout << ans << "\n";
}

signed main() {
    fast int t;
    cin >> t;
    while(t--) solve();
    return 0;
}