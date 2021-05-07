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

const int maxn = 1e5+1;

vector<int> adj[maxn];
bool vis[maxn];
int path[maxn];

void dfs(int node) {
    vis[node] = 1;
    for(int x : adj[node]) {
        if(! vis[x]) dfs(x);
        path[node] = max(path[node], path[x] + 1);
    }
}

void solve() {
    int N, M, x, y; cin>>N>>M;
    for(int i=0;i<M;i++) {
        cin>>x>>y;
        adj[x].push_back(y);
    }
    for(int i = 1; i <= N; i++) {
        if(! vis[i]) dfs(i);
    }
    int ans = 0;
    for(int i = 1; i<= N; i++) {
        ans = max(ans, path[i]);
    }
    cout << ans << "\n";
}
int main() {
    solve();
    return 0;
}