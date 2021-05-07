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
// map<int, int> cnt;

bool cmp(ll a, ll b) {
    return abs(a) > abs(b);
}
void solve() {
    cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n, &cmp);
    ll pro = 1;
    ll minpos = -p;
    ll minneg = -p;
    int cntneg = 0;
    for(int i = 0; i < 5; i++) {
        if(a[i] < 0) {
            minneg = a[i];
            cntneg++;
        }
        if(a[i] > 0) minpos = a[i];
        pro *= a[i];
    }
    if((cntneg&1) == 0) cout << pro << "\n";
    else {
        ll o1 = p, o2 = p; 
        if(minneg != -p) {
            for(int i = 5; i < n; i++) {
                if(a[i] >= 0) { o1 = pro / minneg * a[i]; break; }
            }
        }
        if(minpos != -p) {
            for(int i = 5; i < n; i++) {
                if(a[i] <= 0) { o2 = pro / minpos * a[i]; break; }
            }
        }
        if(o1 != p && o2 != p) cout << max(o2, o1) << "\n";
        else if(o1 != p) cout << o1 << "\n";
        else if(o2 != p) cout << o2 << "\n";
        else {
            pro = 1;
            for(int i = n-1 ; i > n-6; i--) { pro *= a[i]; }
            cout << pro << "\n";
        }
    }
}

int main() {
    fast
    int t; cin >> t;
    while(t--) solve();
    return 0;
}