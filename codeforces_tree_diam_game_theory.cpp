#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back

using namespace std;

const int maxn = 1e5+1;
vector<int> adj[maxn];

int ab, n, a , b, da, db;

void dfs(int node, int par, int cum) {
    if(node == b-1) {
        ab = cum;
        return;
    }

    for(int x : adj[node]) {
        if(x != par) dfs(x, node, cum+1);
    }  
}

int diam;

int dfs1(int node, int p) {
    int len = 0;
    for(int y : adj[node]) {
        if(y != p) {
            int cur = 1 + dfs1(y, node);
            diam = max(diam, cur + len);
            len = max(len, cur);
        }
    }
    return len;
}

void solve() {  
    cin >> n >> a >> b >> da >> db;

    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v); 
        adj[v].pb(u);
    }

    dfs(a-1, -1, 0);

    diam = 0;

    dfs1(a-1, -1);

    cout << (2 * da >= min(diam, db) || ab <= da ? "Alice" : "Bob") << '\n';

    for(int i = 0; i < n; i++) adj[i].clear(); 
}

int main() {
    fast
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
