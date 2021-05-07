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

void solve() {
    int n, m; cin >> n >> m;
    ll mat[n][m];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cin >> mat[i][j];
    }

    ll ans = 0;
    vl seq;
    for(int j = 0; j < m/2; j++) {
        for(int i = 0; i < n/2; i++) {
            seq.clear();
            seq.pb(mat[i][j]); 
            seq.pb(mat[n-1-i][j]); 
            seq.pb(mat[i][m-1-j]); 
            seq.pb(mat[n-1-i][m-1-j]);
            sort(seq.begin(), seq.end());
            ans += abs(seq[1] - seq[0]) + abs(seq[1] - seq[2]) + abs(seq[1] - seq[3]);
        }
    } 
    
    if(n&1) {
        for(int i = 0; i < m/2; i++) {
            ans += abs(mat[n/2][i] - mat[n/2][m-1-i]); 
        }
    }
    
    if(m&1) {
        for(int i = 0; i < n/2; i++) {
            ans += abs(mat[i][m/2] - mat[n-1-i][m/2]); 
        }
    }

    cout << ans << "\n";
}

int main() {
    fast
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}
