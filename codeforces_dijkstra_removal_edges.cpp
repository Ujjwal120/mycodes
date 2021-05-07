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

vpi adj[1002];
vpi district(1002);
vi cost;
vii costall;
vpi edges;
int n, m, k;
priority_queue<pii, vpi, greater<pii>> pq;

void multi_dijkstra (int src) {
    pq = priority_queue<pii, vpi, greater<pii>>();
    cost = vi(n, p);
    cost[src] = 0;
    pq.push({0, src});
    while(!pq.empty()) {
        int node = pq.top().ss;
        int dist = pq.top().ff;
        pq.pop();

        if(cost[node] < dist) continue;

        for(auto x : adj[node]) {
            int n = x.ff;
            int w = x.ss;
            if(cost[node]+ w < cost[n]) {
                cost[n] = cost[node] + w;
                pq.push({cost[n], n});
            }
        } 
    }

    costall.pb(cost);
}


void solve() {
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].pb({v, w}); adj[v].pb({u, w}); 
        edges.pb({u, v});
    }

    for(int i = 0; i < k; i++) {
        cin >> district[i].ff >> district[i].ss; 
        district[i].ff--; district[i].ss--;
    }

    for(int i = 0; i < n; i++) {
        multi_dijkstra(i);
    }
    
    int ans = p;
    for(int i = 0; i < m; i++) {
        int x = edges[i].ff, y = edges[i].ss;
        int infer = 0;
        for(int j = 0; j < k; j++) {
            int src = district[j].ff;
            int dest = district[j].ss;
            infer += min({costall[src][dest], costall[src][x] + costall[y][dest], costall[src][y] + costall[x][dest]});
        }
        ans = min(ans, infer);
    }
    cout << ans << "\n";
}

int main() {
    fast
    int t = 1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}