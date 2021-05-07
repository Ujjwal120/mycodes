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
int good[maxn];
vii adjList;
int pp[maxn], h[maxn], cp[maxn], parent[maxn];
vi path;
int N, M, u, v;
bool poss = true;

void dfs1(int node, int par, vi path) {
    path.pb(node);
    parent[node] = par;
    cp[node] += pp[node];
    for(int x : adjList[node]) {
        if(x != par) dfs1(x, node, path);
    }
    int n = path[path.size()-1];
    if(par!=-1) cp[par] += cp[n];
}

void dfs2(int node, int par) {
    if((cp[node] + h[node]) & 1 || abs(h[node]) > cp[node]) {
        poss = false; return;
    }
    good[node] = (cp[node] + h[node])/2;
    for(int x : adjList[node]) {
        if(x != par) dfs2(x, node);
    }
}

void solve() {
    cin >> N >> M;
    for(int i = 1; i <= N; i++) cin>>pp[i];
    for(int i = 1; i <= N; i++) cin>>h[i];
    for(int i = 1; i <= N; i++) {
        cp[i] = 0; good[i] = 0;
    }
    adjList.clear(); adjList.resize(N+1); path.clear();
    for(int i = 0; i<N-1; i++) {
        cin>>u>>v;
        adjList[u].pb(v); adjList[v].pb(u);
    }
    dfs1(1, -1, path);
    poss = true;
    
    dfs2(1, -1);
    
    if(poss) {
        for(int i = 1; i <= N; i++) {
            int g = 0;
            for(int x : adjList[i]) {
                if(x != parent[i]) g += good[x];
            }
            if(good[i] < g) {
                poss = false;
                break;
            }
        }
    }
    
    if(poss) cout<<"YES\n";
    else cout<<"NO\n";
}

int main() {
    fast 
    // input output
    int t; cin>>t; 
    while(t--) solve();
    return 0;
}