// used for minimum leaf - leaf distance
// cant be used for max leaf - leaf distance

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

const int p = 1e9 + 7;
const int maxn = 1e5 + 1;

vi parent;
vii adj;

void dfs(int node, int par) {
    parent[node] = par;
    for(int x : adj[node]) {
        if(x != par) dfs(x, node);
    }
}
void solve() {
    int N; cin >> N;
    adj.clear();
    adj.resize(N+1);
    for(int i = 1; i < N; i++) {
        int u, v; cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }

    parent.clear(); parent.resize(N+1);
    dfs(1, -1);

    queue<pii> q;
    vi dist(N+1, p);
    for(int i = 1; i <= N; i++) {
        if(adj[i].size() == 1) {
            dist[i] = 1;
            q.push({i, dist[i]});
        }
    }

    int ans = p;
    while(! q.empty()) {
        int node = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(parent[node] != -1) {
            if(dist[parent[node]] == p) {
                dist[parent[node]] = cnt + 1;
                q.push({parent[node], dist[parent[node]]});
            }
            else {
                ans = min(ans, dist[parent[node]] + cnt);
            }
        }
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while(t--) solve();
    return 0;
}