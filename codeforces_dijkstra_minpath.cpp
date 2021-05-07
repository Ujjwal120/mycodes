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

const ll p = 1e18;
const int maxn = 1e5 + 1;

struct pt {
    ll x, y;
    int ind;
};

vector<pt> points;
vpi adj[maxn+4];
ll cost[maxn+4];

bool cmpx (pt a, pt b) {
    return a.x < b.x; 
}

bool cmpy (pt a, pt b) {
    return a.y < b.y;
}

ll dijkstra(int src, int dest) {
    priority_queue<pair<ll, int> , vector<pair<ll, int >>, greater<pair<ll, int>>> pq;
    for(int i = 0; i < maxn+4; i++) cost[i] = p;
    cost[src] = 0;
    pq.push({0, src});
    while(!pq.empty()) {
        ll dist = pq.top().ff;
        int node = pq.top().ss;
        pq.pop();
        if(cost[node] < dist) continue;
        for(auto x : adj[node]) {
            ll dist1 = x.ss;
            ll nnode = x.ff;
            if(cost[nnode] > cost[node] + dist1) {
                cost[nnode] = cost[node] + dist1;
                pq.push({cost[nnode], nnode});
            }
        }
    }
    return cost[dest];
}

void solve() {
    int n, m; cin >> n >> m;
    ll sx, sy, fx, fy;
    cin >> sx >> sy >> fx >> fy;
    for(int i = 0; i < m; i++) {
        pt X;
        X.ind = i;
        cin >> X.x >> X.y;
        points.pb(X);
    }

    sort(points.begin(), points.end(), cmpx);
    for(int i = 1; i < m; i++) {
        ll w = points[i].x - points[i-1].x;
        adj[points[i].ind].pb({points[i-1].ind, w});
        adj[points[i-1].ind].pb({points[i].ind, w});
    }
    sort(points.begin(), points.end(), cmpy);
    for(int i = 1; i < m; i++) {
        ll w = points[i].y - points[i-1].y;
        adj[points[i].ind].pb({points[i-1].ind, w});
        adj[points[i-1].ind].pb({points[i].ind, w});
    }

    for(int i = 0; i < m; i++) {
        ll w = min(abs(points[i].x - sx), abs(points[i].y - sy));
        adj[m].pb({points[i].ind, w});
        adj[points[i].ind].pb({m+1, abs(points[i].x - fx) + abs(points[i].y - fy)});
    }

    cout << min(dijkstra(m, m+1), abs(fx-sx) + abs(fy- sy)) << "\n";
}

int main() {
    fast
    int t = 1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}