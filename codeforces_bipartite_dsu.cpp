#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long 
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pii pair<int, int>
#define ss second
#define ff first
 
const int maxn = 2e5+1;
const int p = 1e9+7;

int par[maxn], sz[maxn];

struct edge {
    int x, y, w;
};

bool cmp(edge a, edge b) {
    return (a.w > b.w);
}

int f_s(int v) {
    if (v == par[v]) return v;
    return par[v] = f_s(par[v]);
}

bool unite(int a, int b) {
    a = f_s(a); b = f_s(b);
    if (a != b) {
        if (sz[a] < sz[b]) swap(a, b);
        par[b] = a; sz[a] += sz[b];
        return true;
    }
    return false;
}

void solve() {
    int tcolor, tvert, n, node; cin >> tcolor >> tvert;
    vector<edge> E;
    int cc[tcolor+1], vc[tvert+1];

    for(int i = 1; i <= tcolor; i++) cin >> cc[i];
    for(int i = 1; i <= tvert; i++) cin >> vc[i];

    ll tc = 0;

    for(int c = 1; c <= tcolor; c++) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> node;
            edge e;
            e.w = cc[c] + vc[node];
            tc += e.w;
            e.x = c+tvert;
            e.y = node;
            E.pb(e);
        }
    }

    for(int i = 1; i <= tvert+tcolor; i++) { par[i] = i; sz[i] = 1; }

    sort(E.begin(), E.end(), &cmp);

    for(edge e : E) {
        if(unite(e.x, e.y)) tc -= e.w; 
    }

    cout << tc << "\n";
}
 
int main() {
    fast 
    int t = 1; 
    while(t--) solve();    
    return 0;
}