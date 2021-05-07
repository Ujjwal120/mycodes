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
const int maxn = 1e5;
int n;
int u, v;
vi adj[maxn+1];
vi centroid;

int dfs(int node, int par) {
    int subtree = 1;
    int worst = 0;
    for(int x : adj[node]) {
        if(x != par) {
            int chsub = dfs(x, node);
            worst = max(worst, chsub);
            subtree += chsub;
        }
    }

    if(node != 0) worst = max(worst, n-subtree);
    centroid[node] = worst;
    return subtree;
}

pii ghumkeaao(int node, int par) {
    if(adj[node].size() == 1) return (mp(node, par));
    for(int x : adj[node]) {
        if(x != par) return ghumkeaao(x, node);
    }
}

void solve() {
    cin >> n; 
    for(int i = 0; i < n-1; i++) {
        cin >> u >> v;
        u--; v--;
        adj[u].pb(v); adj[v].pb(u); 
    }

    centroid.clear();
    centroid.resize(n);
    dfs(0, -1);

    int cent = p;
    int id;
    for(int i = 0; i < n; i++) {
        if(centroid[i] < cent) { cent = centroid[i]; id = i; }
    }

    bool two = false;
    int otherid;
    for(int x : adj[id]) {
        if(centroid[x] == cent) {
            otherid = x;
            two = true;
            break;
        }
    }

    if(two) {
        pii k = ghumkeaao(id, otherid);
        cout << k.first + 1 << " " << k.second + 1 << "\n";
        cout << k.first + 1 << " " << otherid + 1 << "\n"; 
    }
    else {
        cout << id + 1 << " " << adj[id][0] + 1 << "\n";
        cout << id + 1 << " " << adj[id][0] + 1 << "\n";
    }

    for(int i = 0; i < n; i++) adj[i].clear();
}

int main() {
    fast
    int t; cin >> t;
    while(t--) solve();
    return 0;
}