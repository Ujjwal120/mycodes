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
const int maxn=2e5+2;

ll sum[maxn];
int a[maxn], b[maxn];
bool vis[maxn] = {0};
vi nodes;
vi unselected;
vii adjList; 

void dfs(int node, int par) {
    vis[node] = 1;
    sum[node] += a[node];
    for(int x : adjList[node]) {
        if(! vis[x]) dfs(x, node);
    }
    
    if(par != -1 && sum[node] >= 0)  {
        sum[par] += sum[node];
        nodes.pb(node);
    }
    else unselected.pb(node);
}

void solve() {
    int N; cin >> N;
    for(int i = 1; i <= N; i++) cin >> a[i];
    for(int i = 1; i <= N; i++) cin >> b[i];
    adjList.resize(N+1);
    for(int i = 1; i <= N; i++) {
        if(b[i] != -1) adjList[b[i]].pb(i);
    }
    for(int i = 1; i <= N; i++) {
        if(! vis[i]) dfs(i, b[i]);
    }
    ll ans = 0;
    for(int i = 1; i <=N; i++) ans += sum[i];
    cout<<ans<<"\n";
    for(int i = 0; i < nodes.size(); i++) cout << nodes[i] << " ";
    for(int i = unselected.size()-1; i >= 0; i--) cout << unselected[i] << " ";
    cout<<"\n";
}

int main() {
    fast 
    // input output
    int t = 1; 
    // cin>>t; 
    while(t--) solve();
    return 0;
}