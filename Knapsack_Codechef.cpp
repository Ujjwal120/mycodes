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
using namespace std;
 
const int p=1e9+7;
const int maxn=1e5+2;

ll DP[3001][3001], colour[3001];
int w[3001], index_colour[3001];

void solve() {
    int N, C, K; cin >> N >> C >> K;
    int a[N], b[N], c; 
    
    for(int i = 1; i <= C; i++) colour[i] = 0;
    for(int i = 0; i < N; i++) {
        cin >> a[i] >> b[i] >> c;
        colour[c]++;                    
    }
    
    for(int i = 1; i <= C; i++) cin >> w[i];     
    
    int DP_SIZE = 0; ll triangles = 0;     
    
    vl val; val.pb(0);

    for(int i = 1; i <= C; i++) {
        if(colour[i] >= 3) {
            for(int j = 1; j <= colour[i] - 2; j++) {
                DP_SIZE++;  index_colour[DP_SIZE] = i;
            }
            triangles += colour[i] * (colour[i]-1) * (colour[i]-2) / 6;
        }
    }
    
    for(int i = 1; i <= DP_SIZE; i++) {
        int ind = index_colour[i]; 
        val.pb((colour[ind]-1)*(colour[ind]-2)/2);
        colour[ind]--;
    }
    
    
    for(int i = 0; i <= DP_SIZE; i++) {
        for(int j = 0; j <= K; j++) {
            DP[i][j] = 0;
        }
    }
    
    for(int i = 1; i <= DP_SIZE; i++) {
        int ind = index_colour[i];
        for(int j = 1; j <= K; j++) {
            // not picking 
            DP[i][j] = DP[i-1][j];
            // picking 
            if(j >= w[ind]) DP[i][j] = max(DP[i][j], DP[i-1][j - w[ind]] + val[i]);
        }
    }
    
    cout << triangles - DP[DP_SIZE][K] << "\n";
}

int main() {
    fast 
    // input output
    int t; cin>>t; 
    while(t--) solve();
    return 0;
}