#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int maxn = 2e5+10;
int n, q;
vector<int> adj[maxn];

int dfs_order[maxn], lvl[maxn], dp[18][maxn];

int tame = 0;

void dfs(int node, int par) {
    for(int i = 1; i < 18; i++) {
        dp[i][node] = dp[i-1][dp[i-1][node]];
    }

    for(int x : adj[node]) {
        if(x != par) {
            dfs_order[x] = ++tame;
            lvl[x] = lvl[node]+1;
            dp[0][x] = node;
            dfs(x, node);
        }
    }
}

vector<int> L;

void leaf(int node, int par) {
    // cout << node << " ";
    if(adj[node].size() == 1 && (node != 1)) L.push_back(node); 
    if(node == 1 && n == 1) L.push_back(1);

    for(int x : adj[node]) {
        if(x != par) leaf(x, node);
    }
}


inline int LCA(int u, int v) {
    if(lvl[u] > lvl[v]) swap(u, v);
    for(int i = 17; i >= 0; i--)
        if(lvl[v]-(1<<i) >= lvl[u]) v = dp[i][v];

    if(u == v) return u;

    for(int i = 17; i >= 0; i--) {
        if(dp[i][u] != dp[i][v]) {
            u = dp[i][u];
            v = dp[i][v];
        }
    }
    return dp[0][u];
}

vector<pair<int, int>> tree_min, tree_max;


pair<int, int> query_min(int l, int r) {
    l += L.size(); r += L.size();
    int ans = 1e9+7, node;
    for(; l < r; l >>= 1, r >>= 1) {
        if(l&1) {
            if(ans > tree_min[l].first) {
                ans = tree_min[l].first;
                node = tree_min[l].second;
                l++;
            }
        }
        if(r&1) {
            if(ans > tree_min[--r].first) {
                ans = tree_min[r].first;
                node = tree_min[r].second;
            }
        }
    }

    return {ans, node};
}

pair<int, int> query_max(int l, int r) {
    l += L.size(); r += L.size();
    int ans = -1, node;
    for(; l < r; l >>= 1, r >>= 1) {
        if(l&1) {
            if(ans < tree_max[l].first) {
                ans = tree_max[l].first;
                node = tree_max[l].second;
            }
            l++;
        }
        if(r&1) {
            --r;
            if(ans < tree_max[r].first) {
                ans = tree_max[r].first;
                node = tree_max[r].second;
            }
        }
    }

    return {ans, node};
}

void solve() {
    cin >> n >> q;
    for(int i = 1; i < n; i++) {
        int x;
        cin >> x;
        adj[i+1].push_back(x); adj[x].push_back(i+1);
    }

    dfs(1, -1);
    leaf(1, -1);

    sort(L.begin(), L.end());

    tree_min.resize(2*L.size());
    tree_max.resize(2*L.size());

    //segtree build 
    for(int i = 0; i < L.size(); i++) {
        tree_min[L.size()+i] = {dfs_order[L[i]], L[i]};
        tree_max[L.size()+i] = {dfs_order[L[i]], L[i]};
    }

    for(int i = L.size()-1; i > 0; i--) {
        int child1 = i<<1, child2 = child1|1;
        if(tree_min[child1].first < tree_min[child2].first) {
            tree_min[i] = tree_min[child1];
        }
        else tree_min[i] = tree_min[child2];

        if(tree_max[child1].first > tree_max[child2].first) {
            tree_max[i] = tree_max[child1];
        }
        else tree_max[i] = tree_max[child2];
    }

    for(int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        int i1 = lower_bound(L.begin(), L.end(), l) - L.begin();
        int i2 = lower_bound(L.begin(), L.end(), r) - L.begin();

        if(i1 == L.size()) {
            cout << -1 << " ";
            continue;
        }
        
        if(i1 == i2 && L[i1] != r) {
            cout << -1 << " ";
            continue;
        }

        if(i2 != n) i2++;

        auto min_order = query_min(i1, i2);
        auto max_order = query_max(i1, i2);

        cout << LCA(min_order.second, max_order.second) << " ";
    }

    for(int i = 1; i <= n; i++) adj[i].clear();
}

signed main() {
    fast int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}