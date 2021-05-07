#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define sz(a) (int)(a.size())
using namespace std;
const int MAX = 100005;
int occ[MAX][2];
int banned[3 * MAX];
int color[3 * MAX];
int ptr[MAX];
vector<pair<int , int> > g[MAX];

pair<int, int> getNext(int u) {
    while(ptr[u] < sz(g[u])) {
        if(banned[g[u][ptr[u]].y]) {
            ptr[u]++;
            continue;
        }
        banned[g[u][ptr[u]].y] = 1;
        return g[u][ptr[u]];
    }
    return {-1 , -1};
}

void dfs(int u) {
    vector<int> stV = {u};
    vector<int> stE;
    occ[u][0] = 0;
    
    while(!stV.empty()) {
        int u = stV.back();
        pair<int, int> edge = getNext(u);
        if(edge.x == -1) {
            stV.pop_back();
            if(sz(stE)) stE.pop_back();
            occ[u][sz(stV) % 2] = -1;
            continue;
        }
        if(occ[edge.x][sz(stV) % 2] != -1) {
            color[edge.y] = (((sz(stE) + 1) % 2) == 1) ? 1 : -1;
            int oc = occ[edge.x][sz(stV) % 2] + 1;
            while(sz(stV) > oc) {
                int v = stV.back();
                stV.pop_back();
                occ[v][sz(stV) % 2] = -1;
                color[stE.back()] = ((sz(stE) % 2) == 1) ? 1 : -1;
                stE.pop_back();
            }
            continue;
        }
        occ[edge.x][sz(stV) % 2] = sz(stV);
        stV.pb(edge.x);
        stE.pb(edge.y);
    }
    occ[u][0] = -1;
}
 
int main() {
    memset(occ, -1 , sizeof occ);
    int T;
    cin >> T;
    int sumN = 0 , sumM = 0;
    while(T--) {
        int n, m;
        cin >> n >> m;
        assert(1 <= n && n <= 1e5);
        assert(0 <= m && m <= 3e5);
        sumN += n;sumM += m;
        assert(sumN <= 3e5);
        assert(sumM <= 9e5);
        set<pair<int,int> > edges;
        for(int i = 0; i < m; i++) {
            int u , v;
            cin >> u >> v;
            if(u > v) swap(u , v);
            assert(u != v);
            assert(1 <= u && u <= n);
            assert(1 <= v && v <= n);
            edges.insert({u , v});
            u--; v--;
            g[u].pb({v , i});
            g[v].pb({u , i});
        }
        assert(sz(edges) == m);
        for(int i = 0; i < n; i++) {
            dfs(i);
        }
        for(int i = 0; i < m; i++) {
            cout << color[i] << endl;
            banned[i] = color[i] = 0;
        }
        for(int i = 0; i < n; i++) {
            g[i].clear();
            ptr[i] = 0;
        }
    }
    return 0;
} 