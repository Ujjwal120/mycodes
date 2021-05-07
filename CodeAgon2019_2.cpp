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
    string s; cin >> s;
    int a[10] = {0};
    for(int i = 0; i < n; i++) a[s[i]-'0']++;
    
    int total = 0;
    for(int i = 0; i < 10; i++) {
        if(a[i]&1) {
            total++; 
            continue;
        }
        else { a[i] = -1; } 
    }
    
    if(total == n || total == 0) cout << "-1\n";
    else {
        int lastind[10];
        memset(lastind, -1, sizeof(lastind));
        int cnt = 0;
        int ans = p;
        for(int i = 0; i < n; i++) {
            if(a[s[i]-'0'] != -1) {
                if(lastind[s[i] - '0'] == -1) {
                    if(cnt != total) cnt++;
                }
                lastind[s[i] - '0'] = i;
    
                if(cnt == total) {
                    int mindex = p;
                    for(int j = 0; j < 10; j++) {
                        if(lastind[j] != -1) mindex = min(mindex, lastind[j]);
                    }
                    ans = min(ans, i - mindex);
                }
            }
        }
    
        cout << ans << "\n";
    }
}

int main() {
    fast
    int t; cin >> t;
    while(t--) solve();
    return 0;
}