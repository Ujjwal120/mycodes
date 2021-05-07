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
    int n; cin >> n;
    int setbit = __builtin_popcount(n);
    vector<bool> vis(n);
    
    if(n==1 || n==2) {
        cout << "0\n";
        return;
    }
    
    int ans = 0;
    vpi pr;
    if(setbit == 1) {
        for(int gap = 1; gap <= n/4; gap*=2) {
            for(int i = 0; i < n; i++) vis[i] = 0;
            for(int i = 0; i < n; i++) {
                if(!vis[i]) {
                    vis[i] = 1; vis[i+gap] = 1;
                    pr.pb({i+1, i+gap+1});
                    ans++;
                }
            }
        }
    }
    else {
        int bit = 0;
        int temp = n;
        while(temp) {
            temp >>= 1;
            bit++;
        }
        bit--;
        int N = 1<<bit;

        for(int gap = 1; gap <= N/2; gap*=2) {
            for(int i = 0; i < N; i++) vis[i] = 0;
            for(int i = 0; i < N; i++) {
                if(!vis[i]) {
                    vis[i] = 1; vis[i+gap] = 1;
                    pr.pb({i+1, i+gap+1});
                    ans++;
                }
            }
        }
        
        temp = n-N;
        setbit = __builtin_popcount(temp);        
        if(setbit == 1) {
            for(int gap = 1; gap <= temp/2; gap*=2) {
                for(int i = N; i < n; i++) vis[i] = 0;
                for(int i = N; i < n; i++) {
                    if(!vis[i]) {
                        vis[i] = 1; vis[i+gap] = 1;
                        pr.pb({i+1, i+gap+1});
                        ans++;
                    }
                }
            }
        }
        else {
            bit = 0;
            while(temp) {
                temp >>= 1;
                bit++;
            }
            N = 1<<bit;
            for(int gap = 1; gap <= N/2; gap*=2) {
                for(int i = n-N; i < n; i++) vis[i] = 0;
                for(int i = n-N; i < n; i++) {
                    if(!vis[i]) {
                        vis[i] = 1; vis[i+gap] = 1;
                        pr.pb({i+1, i+gap+1});
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans << "\n";
    for(pii x : pr) cout << x.ff << " " << x.ss <<"\n";
}

int main() {
    fast
    int t = 1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}