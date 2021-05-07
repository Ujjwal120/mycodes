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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int ans = 0;
    vi ind;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'W') ind.pb(i);
    }
    
    if(k == 0) {
        ans = ind.size();
        for(int i = 1; i < ind.size(); i++) {
            if(ind[i]-1 == ind[i-1]) ans++;
        }
        cout << ans << "\n";
    }
    else if(ind.size() == 0) {
        cout << (k-1)*2+1 << "\n";
    }
    else if(ind.size()==1) {
        k = min(n-1, k); k++;
        cout << (k-1)*2+1 << "\n";
    }
    else {
        vi diff;
        for(int i = 0; i < ind.size()-1; i++) {
            diff.pb(ind[i+1]-ind[i]-1);
        }
        
        ans = ind.size();
        sort(diff.begin(), diff.end());
        
        for(int i = 0; i < diff.size(); i++) {
            if(k >= diff[i]) {
                ans += diff[i]*2 + 1;
                k -= diff[i];
            }
            else {
                ans += min(diff[i], k)*2; k = 0;
                break;
            }
        }

        if(k != 0) {
            if(ind[0] != 0) {
                ans += min(k, ind[0])*2;
                k -= min(k, ind[0]);
            } 
        }

        if(k != 0) {
            if(ind[ind.size()-1] != n-1) {
                ans += min(k, n-1-ind[ind.size()-1])*2;
            }
        }
        
        cout << ans << "\n";
    }
}

int main() {
    fast
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}