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
vi adj[maxn];



void solve() {
    cin >> n; 
    for(int i = 0; i < n; i++) {
        cin >> u >> v;
        u--; v--;
        adj[u].pb(v); adj[v].pb(u); 
    }
    int maxdeg = 0;

    for(int i = 0; i < n; i++) adj[i].clear();
}

int main() {
    fast
    int t; cin >> t;
    while(t--) solve();
    return 0;
}