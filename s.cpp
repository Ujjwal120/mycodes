#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

// 3
// acbcdaaaaa    // acbcdaaa --> aaaabccd  aaaa bbb ff
// aa
// a
// 2
// 3 3 1
// 1 3 5




int totalcount[100][26];



void solve(int N, string s[], int Q, int query[][3]) {
    // write
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 26; j++) 
            totalcount[i+1][j] = totalcount[i][j];

        for(int j = 0; j < s[i].length(); j++) 
            totalcount[i+1][ s[i][j] % 97]++;
    }

    for(int i = 0; i < Q; i++) {
        
    }
}

signed main() {
    fast; 
    int t = 1, N = 5, Q = 4, query[Q][3];
    string s[5]; 
    while(t--) solve(N, s, Q, query);
    return 0;
}