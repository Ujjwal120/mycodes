#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 

using namespace std;

int cs = 0;
int mat[1001][1001][4];
int ac_mmat[1001][1001];

void solve() {
    int r, c;
    cin >> r >> c;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) cin >> ac_mmat[i][j];
    }

    
    for(int k = 0; k < 4; k++) {
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) mat[i][j][k] = 0;
        }
    }


    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(ac_mmat[i][j] == 0) mat[i][j][0] = 0;
            else mat[i][j][0] = (j > 0) ? mat[i][j-1][0] + 1 : 1;
        }
    }

    for(int i = 0; i < r; i++) {
        for(int j = c-1; j >= 0; j--) {
            if(ac_mmat[i][j] == 0) mat[i][j][2] = 0;
            else mat[i][j][2] = (j < c-1) ? mat[i][j+1][2] + 1 : 1;
        }
    }

    for(int j = 0; j < c; j++) {
        for(int i = 0; i < r; i++) {
            if(ac_mmat[i][j] == 0) mat[i][j][1] = 0;
            else mat[i][j][1] = (i > 0) ? mat[i-1][j][1] + 1 : 1;
        }
    }

    for(int j = 0; j < c; j++) {
        for(int i = r-1; i >= 0; i--) {
            if(ac_mmat[i][j] == 0) mat[i][j][3] = 0;
            else mat[i][j][3] = (i < r-1) ? mat[i+1][j][3] + 1 : 1;
        }
    }

    ll ans = 0;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            int l = mat[i][j][0], r = mat[i][j][2], u = mat[i][j][1], d = mat[i][j][3];
            if(u > 1 && l > 1) {
                ans += min(l, u/2) - 1;
                ans += min(u, l/2) - 1;
            }
            if(u > 1 && r > 1) {
                ans += min(r, u/2) - 1;
                ans += min(u, r/2) - 1;
            }
            if(d > 1 && l > 1) {
                ans += min(l, d/2) - 1;
                ans += min(d, l/2) - 1;
            }
            if(d > 1 && r > 1) {
                ans += min(r, d/2) - 1;
                ans += min(d, r/2) - 1;
            }
        }
    }

    cout << "Case #" << ++cs << ": " << ans << "\n"; 
}

signed main() {
    fast int t;
    cin >> t;
    while(t--) solve();
    return 0;
}