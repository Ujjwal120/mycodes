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
 
const int p = 1e9+7;
const int maxn = 3e5 + 1;
 
void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    bool poss = true;
    for(int i = 0; i < n; i++) {
        if(i+k == n) break;
        if(s[i] == s[i+k] || s[i] == '?' || s[i+k] == '?') {
            if(s[i] != '?') s[i+k] = s[i];
            else s[i] = s[i+k];
        }
        else { poss = false; break; }
    }
 
    if(poss) {
        reverse(s.begin(), s.end());
 
        for(int i = 0; i < n; i++) {
            if(i+k == n) break;
            if(s[i] == s[i+k] || s[i] == '?' || s[i+k] == '?') {
                if(s[i] != '?') s[i+k] = s[i];
                else s[i] = s[i+k];
            }
            else { poss = false; break; }
        }
    }
 
    int z = 0;
    int q = 0;
    // check balance
    if(poss) {
        for(int i = 0; i < k; i++) {
            if(s[i] == '0') z++;
            else if(s[i] == '?') q++;
        }
    }
 
    if(poss) {
        if(z == k-z-q) cout << "YES\n";
        else if(z > k/2 || k-z-q > k/2) cout << "NO\n";
        else cout << "YES\n";
    }
    else cout << "NO\n";
}
 
int main() {
    fast
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}