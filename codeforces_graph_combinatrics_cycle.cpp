#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int maxn = 2e5+10;

// darkness is my friend

vector<int> adj[maxn], pre(maxn);
vector<bool> cycle(maxn), vis(maxn);

int cnt = 0, a, b; 

void dfs(int node, int par) {
    vis[node] = 1;
    for(int x : adj[node]) {
        if(x != par) {
            if(vis[x]) {
                if(node != a) { a = x; pre[a] = node; }
                return;
            }
            else pre[x] = node; 
            dfs(x, node);
        }
    }
}

int just_visit(int node, int par) {
    int q = 1;
    for(int x : adj[node]) {
        if(x != par && !cycle[x]) q += just_visit(x, node);
    }
    return q;
}

void solve() {
    int n; cin >> n;
    cnt = 0;
    for(int i = 0; i < n; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v); adj[v].push_back(u);
    }

    for(int i = 0; i < n; i++) {
        cycle[i] = 0; vis[i] = 0;
    } 

    a = -1; b = -1;

    dfs(0, -1);

    cycle[a] = 1;

    int par = pre[a];
    for(int i = 0; ; i++) {
        if(par == a) break;
        cycle[par] = 1;
        par = pre[par];
    }

    long long ans = 0, d_cnt = 1ll*n*(n-1)/2;
    
    for(int i = 0; i < n; i++) {
        if(cycle[i]) {
            int x = just_visit(i, -1);
            long long temp = 1ll*x*(x-1)/2;
            ans += temp;
            d_cnt -= temp;
        }
    }

    ans += d_cnt*2;

    cout << ans << "\n";

    for(int i = 0; i < n; i++) adj[i].clear();
}

signed main() {
    fast int t; cin >> t;
    while(t--) solve();
    return 0;
}