#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define input freopen("1.txt","r",stdin);
#define output freopen("output.txt","w",stdout);
#define ll long long int
#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define vi vector<int>
#define vii vector<vi>
#define vl vector<ll>
#define vll vector<vl>
#define pii pair<int, int>
#define pll pair<ll,ll>
#define mp make_pair
#define vpi vector<pii>
#define vpl vector<pll> 
#define ss second 
#define ff first

using namespace std;

const int p = 1e9 + 7;
const int maxn = 1e5 + 1;

int dp[75][75][38][75];   // 4-D x , y, cnt, rem
int a[75][75];
int n, m, k;

void solve() {
    cin >> n >> m >> k; 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cin >> a[i][j];
    }

    for(int i = 0; i < n+1; i++) {
        for(int j = 0; j < m; j++) {
            for(int y = 0; y < m/2+1; y++) {
                for(int l = 0; l < k; l++) {
                    dp[i][j][y][l] = -p;
                }
            }
        }
    }

    dp[0][0][0][0] = 0;
    
    for(int x = 0; x < n; x++) {
        for(int y = 0; y < m; y++) {
            for(int cnt = 0; cnt < m/2+1; cnt++) {
                for(int rem = 0; rem < k; rem++) {
                    int nx = (y == m-1) ? x+1 : x;
                    int ny = (y == m-1) ? 0 : y+1;
                    // don't pick
                    if(nx != x) {
                        dp[nx][ny][0][rem] = max(dp[nx][ny][0][rem], dp[x][y][cnt][rem]);
                    } 
                    else {
                        dp[nx][ny][cnt][rem] = max(dp[nx][ny][cnt][rem], dp[x][y][cnt][rem]);
                    }

                    // pick it
                    if(cnt != m/2) {
                        int nrem = (rem+a[x][y])%k;
                        if(nx != x) {
                            dp[nx][ny][0][nrem] = max(dp[nx][ny][0][nrem], dp[x][y][cnt][rem] + a[x][y]);
                        }
                        else {
                            dp[nx][ny][cnt+1][nrem] = max(dp[nx][ny][cnt+1][nrem], dp[x][y][cnt][rem] + a[x][y]);
                        }
                    }
                }
            }
        } 
    }
    cout << max(0, dp[n][0][0][0]);
}

int main() {
    fast
    int t = 1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}