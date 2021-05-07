#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define ll long long 
#define vl vector<ll>

using namespace std;

const int maxn = 1e5 + 5;
const ll p = 1e9 + 7;

inline ll mul(ll a, ll b) {
    ll r = a * b;
    if(r >= p) return r % p;
    return r; 
}

inline ll add(ll a, ll b) {
    return (a + b >= p) ? (a + b - p) : (a + b);
}

bool cmp(ll a, ll b) {
    return a > b;
}

vi adj[maxn];
vl w, pr;
ll n;

ll dfs(int node, int p) {
    ll d = 1;
    for(int x : adj[node]) {
        if(x != p) d += dfs(x, node);
    }
    if(p != -1) w.pb(d*(n-d));
    return d;
}

void solve() {
    cin >> n;
    int u, v, m;
    for(int i = 1; i <= n; i++) adj[i].clear();
    w.clear(); pr.clear();
    for(int i = 0; i < n-1; i++) {
        cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }

    cin >> m;
    pr.resize(m);  

    for(int i = 0; i < m; i++)  cin >> pr[i];
    
    if(m < n-1) {
        pr.resize(n-1, 1);
        m = n-1;
    }
    
    sort(pr.begin(), pr.end(), &cmp);
    
    dfs(1, -1);
    
    sort(w.begin(), w.end(), &cmp);

    for(int i = 0; i < w.size(); i++) w[i] %= p;
    
    ll ans = 0;
    int ind = 0;
    ll pro = 1;
    
    for(int i = 0; i < m-n+1; i++) {
        pro = mul(pro, pr[i]);    
        ind++;
    }
    
    
    for(int i = 0; i < w.size(), ind < pr.size(); i++, ind++) {
        (i == 0) ? ans = add(ans, mul(w[i], mul(pro, pr[ind]))) :
        ans = add(ans, mul(w[i], pr[ind]));
    }

    cout << ans << "\n";
    
}

int main() {
    int t;  cin >> t;
    while(t--) solve();
    return 0;
}