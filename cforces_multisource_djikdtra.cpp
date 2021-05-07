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
#define pli pair<ll, int>
#define vpli vector<pli>
#define ss second 
#define ff first

using namespace std;

const int p = 1e9 + 7;
const int maxn = 2e5 + 1;

vector<vector<pair<int, ll>>> adj;
ll mincost[maxn], a[maxn];
int n, m;

void djikstra() {
    set<pli> pq;
    for(int i = 1; i <= n; i++) {
        mincost[i] = a[i];
        pq.insert({mincost[i], i});
    }

    while(!pq.empty()) {
        int v = pq.begin()->ss;   
        ll w = pq.begin()->ff;
        pq.erase(pq.begin());
        
        if(mincost[v] < w) continue;

        for(auto x : adj[v]) {
            int u = x.ff;
            ll dist = x.ss;
            if(mincost[u] > mincost[v]+dist) {
                mincost[u] = mincost[v]+dist;
                pq.insert({mincost[u], u});
            }
        }     
    }
}

void solve() {
    int u, v; cin >> n >> m;
    ll w;
    adj.resize(n+1);
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        w *= 2;
        adj[u].pb({v, w}); adj[v].pb({u, w});
    }

    for(int i = 1; i <= n; i++) cin >> a[i];
    
    djikstra();

    for(int i = 1; i <= n; i++) cout << mincost[i] << " ";
    cout << "\n";
}

int main() {
    fast
    int t = 1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}