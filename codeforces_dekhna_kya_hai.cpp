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
const int maxn = 1e5 + 5;

vii v;

void solve() {
    int n, m; cin >> n >> m;
    vi f(n+1);
    for(int i = 0; i < n; i++) {
        vi vec(m);
        for(int j = 0; j < m; j++) cin >> vec[j];
        f[vec[0]] = i;
        v.pb(vec);
    }

    bool done = false;
    vi ans(n);
    for(int i = 0; i < m; i++) {
        ans.resize(n);
        for(int j = 0; j < n; j++) {
            cin >> ans[j];
            if(ans[j] == v[f[1]][0]) done = true;
        }
        if(done) break;
    }

    for(int i = 0; i < n; i++) {
        for(int x : v[f[ans[i]]]) cout << x << " ";
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    fast
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}