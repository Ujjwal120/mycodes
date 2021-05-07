// Bit opertion related Ques Codeforces
// Brute force

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

const int p = 1e9+7;
const int maxn = 1e5 + 1;

void solve() {
    int n, m; cin>>n>>m;
    int a[n], b[m];
    for(int i = 0; i<n; i++) cin>>a[i];
    for(int i = 0; i<m; i++) cin>>b[i];
    
    int pass = 0;
    for(int k = 0; k < (1<<9); k++) {
        for(int i = 0; i<n; i++) {
            bool poss = false;
            for(int j = 0; j<m; j++) {
                if(((a[i] & b[j])|k)== k) {
                    poss = true; break;
                }
            }
            if(poss) pass++;
            else break;
        }
        
        if(pass == n) {
            cout << k << "\n";
            break;
        }
        else pass = 0;
    }
}

int main() {
    fast
    int t = 1; 
    // cin>>t;
    while(t--) solve();
    return 0;
}