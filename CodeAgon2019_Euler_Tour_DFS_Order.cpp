#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define inout freopen("1.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define pb push_back
#define vi vector<int> 

const int maxn = 1e5; 

vi adj[maxn+1];

int parent[maxn+1], lvl[maxn+1], n, root, tame = 1, basis[maxn+1], dp[18][maxn+1];
 
int dfs(int node) {

    if(lvl[node] != 0) return lvl[node];
    
    if(parent[node] == node) root = node;
    else adj[parent[node]].pb(node); 
    
    int level = 1;
    if(parent[node] != node) {
        level += dfs(parent[node]);
    }

    return lvl[node] = level;
}

void euler_tour(int node) {
    for (int i = 1; i <=17; i++) 
        dp[i][node] = dp[i - 1][dp[i - 1][node]];
        
    for(int x : adj[node]) {
        dp[0][x] = node;
        euler_tour(x);
    }
    basis[node] = tame; 
    tame++;
}

inline int lca(int u, int v){
	if (lvl[u] > lvl[v]) swap(u, v);
	for (int i = 17; i >= 0; i--)   
		if (lvl[v] - (1 << i) >= lvl[u]) v = dp[i][v]; 
	
    if (u == v) return u;
	for (int i = 17; i >= 0; i--){
		if (dp[i][u] != dp[i][v]){
			u = dp[i][u];
			v = dp[i][v];
		}
	}
	return dp[0][u];
}

bool cmp (int a, int b) {
    return basis[a] < basis[b];
}

void solve() {
    int q; cin >> q;
    int query[maxn], qno;
    for(int i = 0; i < q; i++) {
        cin >> qno;
        for(int j = 0; j < qno; j++) cin >> query[j];
        sort(query, query+qno, &cmp);
        int ans = 1, LCA = lvl[query[0]];
        for(int j = 1; j < qno; j++) {
            int temp = lca(query[j], query[j-1]);
            if(temp != query[j] && temp != query[j-1]) {
                if(lvl[temp] < LCA) {
                    ans += LCA + lvl[query[j]] - 2 * lvl[temp];
                    LCA = lvl[temp];
                }
                else ans += lvl[query[j]] - lvl[temp];
            }
            else {
                if(LCA > lvl[temp]) {
                    ans += LCA - lvl[temp];
                    LCA = lvl[temp];
                }
            }
        }
        cout << ans << "\n";
    }
}

int main() {
    fast 
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> parent[i];
    for(int i = 1; i <= n; i++) dfs(i);
    euler_tour(root);
    solve();
    return 0;
}