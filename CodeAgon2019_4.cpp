#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define ll long long 
#define vi vector<int> 
#define vl vector<ll>

const int maxn = 1e5;

void solve() {
    int n, k; cin >> n >> k;
    vl a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int cnt = 0;
    if(a[n-1]-a[0] == 0) cout << "0\n";
    else {
        ll ans = a[n-1] - a[0];
        for(int i = 0; i < n; i++) {
            if(a[0]%k != 0) {
                int ind = lower_bound(a.begin(), a.end(), a[0]*k) - a.begin();
                if(ind == 1) {
                    a[0] *= k;
                    ans = min(ans, a[n-1]-a[0]);
                    break;
                }
                else {
                    if(ind == n) { 
                        a.pb(a[0]*k); 
                        a.erase(a.begin()); 
                        ans = min(ans, a[n-1]-a[0]); 
                    }
                    else { 
                        a.insert(a.begin()+ind, a[0]*k); 
                        a.erase(a.begin()); 
                        ans = min(ans, a[n-1]-a[0]); 
                    }
                }
            }
            else break;
            if(ans == 0) break;
        }

        if(ans == 0) cout << "0\n";
        else {
            while(a[n-1]%k == 0) {
                for(int i = n-1; i >= 0; i--) {
                    if(a[n-1]%k == 0) {
                        int ind = lower_bound(a.begin(), a.end(), a[n-1]/k) - a.begin();
                        if(ind == n-1) { 
                            a[n-1] /= k; 
                            ans = min(ans ,a[n-1]- a[0]); 
                        }
                        else {
                            a.erase(prev(a.end()));
                            a.insert(a.begin()+ind, a[n-1]/k);
                            ans = min(ans, a[n-1]-a[0]);
                        }
                    } 
                    else break;
                    if(ans == 0) break;
                }
                if(ans == 0) break; 
            }
            cout << ans << "\n";
        }
    }
}

int main() {
    fast;
    solve();
    return 0;
}