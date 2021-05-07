// ordered mmovement in weighted graph shorest path DIJKSTRA

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
 
const int p=1e9+7;
const int maxn=1e5+2;

int D[maxn], n , m, x , y;                 // Keeps minimum distance to each node
vpi E[maxn];                               // Adjacency list

void dijkstra(int src, int no, int nono)
{
    for(int i = 1; i <= n; i++) D[i] = p;
    D[src] = 0;
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0, src});

    while(! q.empty()) {
        pair<int,int> p = q.top();
        q.pop();

        int u = p.second, dist = p.first;
        if(dist > D[u]) continue;

        for(pair<int,int> pr : E[u]) {
            int v = pr.first;
            int next_dist = dist + pr.second;
            if(v == no || v == nono) continue;
            if(next_dist < D[v]) {
                D[v] = next_dist;
                q.push({next_dist, v});
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) E[i].clear();

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        E[u].pb({v, w}); E[v].pb({u, w});
    }
    cin >> x >> y;
    dijkstra(1,y,n);
    int ans = D[x];
    dijkstra(x,0,n);
    ans += D[y];
    dijkstra(y,0,0);
    ans += D[n];
    cout << ans << "\n";
}

int main() {
    fast 
    // input output
    int t = 1; 
    // cin>>t; 
    while(t--) solve();
    return 0;
}