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
const int maxn = 1e6;
int n;
map<int, int> cnt;

void solve() {
    cin >> n;
    int a[n];
    cnt.clear();
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    if(cnt[0] == 0) cout << "0\n";
    else if(cnt[0] == 1) {
        for(int i = 1; i <= 100; i++) {
            if(cnt[i] == 0) {
                cout << i << "\n";
                break;
            }
        }
    }
    else {
        int ans = 0;
        bool pos = false;
        for(int i = 0; i <= 100; i++) {
            if(cnt[i] == 0 && !pos) {
                cout << 2 * i << "\n";
                break;
            }
            else if(cnt[i] == 1 && !pos) {
                pos = true;
                ans += i;
            }
            else if(cnt[i] == 0) { ans += i; break; }
        }
        if(pos) cout << ans << "\n";
    }
    
}

int main() {
    fast
    int t; cin >> t;
    while(t--) solve();
    return 0;
}