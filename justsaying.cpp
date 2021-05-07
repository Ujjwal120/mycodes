#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;


signed main() {
    fast 
    int a[51] = {0};
    int c = 0;
    string s[211];

    while(1) {
        int x;
        cin >> x >> x >> x;
        a[x]++;
        c++;
        if(c == 212) break;
    }
    int cum = 0;
    for(int i = 1; i < 51; i++) {
        cout << a[i] << " ";
    }

    for(int i = 1; i < 26; i++) {
        cum += a[i];
    }
    cout << "\n" << cum << "\n";

    return 0;
}