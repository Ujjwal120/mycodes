#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int a_l[26], b_l[26];

void solve() {
    int n, k; cin >> n >> k;
    string a, b; cin >> a >> b; 
    for(int i = 0; i < 26; i++) {
        a_l[i] = 0; b_l[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        a_l[a[i]-'a']++; 
        b_l[b[i]-'a']++;
    }  

    string new_a = "", new_b = "";
    for(int i = 0; i < 26; i++) {
        int temp1 = a_l[i], temp2 = b_l[i];
        a_l[i] -= min(temp1, temp2);
        b_l[i] -= min(temp1, temp2);
        for(int j = 0; j < a_l[i]; j++) {
            new_a += 'a' + i;
        }
        for(int j = 0; j < b_l[i]; j++) {
            new_b += 'a' + i;
        }
    }  

    int x = 0, y = 0;
    bool poss = true;
    for(int i = 0; i < 26; i++) {
        x += a_l[i]; y += b_l[i];
        if(x%k != 0 || y%k != 0) poss = false;
    }

    if(poss) {
        for(int i = 0; i < new_a.length(); i++) {
            if(new_a[i] > new_b[i]) poss = false;
        }
    }

    if(poss) cout << "Yes\n";
    else cout << "No\n";
}

signed main() {
    fast int t; cin >> t;
    while(t--) solve();
    return 0;
}