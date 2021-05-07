#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 
const int p=1e9+7;
const int maxn=1e5+2;
int DP[3000][3000], back_track[3000][3000]; 

void solve() {
    string s, t; cin >> s >> t;
    DP[0][0] = 0;
    
    if(s[0] == t[0]) {
        DP[0][0] = 1;
        back_track[0][0] = 2;
    }
    
    int n = s.length();
    int m = t.length();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i > 0) {
                DP[i][j] = DP[i-1][j];
                back_track[i][j] = 0;
            }
            if(j > 0) {
                if(DP[i][j-1] > DP[i][j]) { 
                    DP[i][j] = DP[i][j-1];
                    back_track[i][j] = 1;
                }
            }

            if(s[i] == t[j]) {
                int ans = 1;
                if(i > 0 && j > 0) {
                    ans = 1 + DP[i-1][j-1];
                }
                if(ans > DP[i][j]) {
                    DP[i][j] = ans;
                    back_track[i][j] = 2;
                }
            }
        }
    }

    int i = n-1, j = m-1;
    string ans = "";
    while(i >= 0 && j >= 0) {
        if(back_track[i][j] == 0) {
            i--;
        }
        else if(back_track[i][j] == 1) {
            j--;
        }
        else {
            ans = s[i] + ans;
            i--; j--;
        }
    }
    cout << ans << " " << DP[n-1][m-1];
}

int main() {
    fast int t = 1; 
    while(t--) solve();
    return 0;
}