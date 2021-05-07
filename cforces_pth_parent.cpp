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
const int maxn = 1e5 + 1;

inline int mul(int a, int b) {
    ll r = 1ll * a * b;
    if(r >= p) return r%p;
    return r;
} 

inline int taakat(int x, int y) {
    int r = 1;
    while(y) {
        if(y&1) r = mul(r, x);
        y >>= 1; x = mul(x, x);
    }
    return r;
}

vi ancestor;
vi adj[maxn];
int numb[maxn], ptr = 1, one = 0, B;

void dfs(int node, int par) {
    ancestor.pb(node);
    for(int x : adj[node]) {
        if(x != par) dfs(x, node);
    }

    int sz = ancestor.size();

    if(numb[ancestor[sz-1]] == 0) {
        if(ancestor[sz-1] == 1) one++;
        if(sz-1 >= B) {
            numb[ancestor[sz-1]] = ptr;
            numb[ancestor[sz-1-B]] = ptr;
            if(ancestor[sz-1-B] == 1) one++;
        }
        ptr++;
    }
    else {
        if(sz-1 >= B) {
            numb[ancestor[sz-1-B]] = numb[ancestor[sz-1]];
            if(ancestor[sz-1-B] == 1) one++;
        }
    }
    ancestor.ppb();
}

vector<bool> exist;

void solve() {
    int n; cin >> n >> B;

    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }

    one = 0;
    dfs(1, -1);

    int inde = 0, pairs = 0;
    
    exist.clear(); exist.resize(n+1, 0);
    for(int i = 1; i <= n; i++) {
        if(numb[i] != 0 && exist[numb[i]] == 0) {
            pairs++;
            exist[numb[i]] = 1;
        }
        else if(numb[i] == 0) inde++;
    }
    
    if(one > 1) pairs -= one-1;
    
    cout << taakat(2, inde+pairs) << "\n";

    for(int i = 1; i <= n; i++) adj[i].clear(); 
}

int main() {
    fast
    int t; cin >> t;
    while(t--) solve();
    return 0;
}