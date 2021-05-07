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

vii adj;
vi path, ans;

void dfs(int node, int p) {
    path[node] = 1;
    for(int x : adj[node]) {
        if(x != p ) dfs(x, node);
    }
    if(p != -1) path[p] = max(path[p], path[node] + 1);
}

void solve() {
    int N, x, y; cin>>N;
    adj.clear(); adj.resize(N+1);
    path.clear(); path.resize(N+1);
    for(int i=1;i<N;i++) {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1,-1);
    ans.clear();
    for(int x : adj[1]) {
        ans.pb(path[x]);
    }

    sort(ans.begin(),ans.end());
    if(ans.size() > 1) cout<< ans[ans.size()-1] + ans[ans.size()-2] + 1<< "\n";
    else cout << ans[ans.size()-1] + 1<< "\n";
}
int main() {
    int t; cin >> t;
    while(t--) solve();
    return 0;
}