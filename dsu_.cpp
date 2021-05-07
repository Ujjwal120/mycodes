#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define x first
#define y second
#define sz(a) (int)(a.size())
using namespace std;
const int MAX = 200005;
vector<int> g[MAX] , t[MAX];
int P[MAX] , A[MAX], B[MAX], present[MAX], p[MAX], pos[MAX], answer[MAX];

int find(int u) {
    return p[u] = (p[u] == u ? u : find(p[u]));
}

void unite(int u, int v) { 
    v = find(v);
    p[v] = u;
    t[u].pb(v);
}

vector<ll> path;
vector<int> path2;

void dfs(int u) {
    path.pb(sz(path) ? path.back() + A[u] : A[u]);
    path2.pb(pos[u]);
    int T = lower_bound(path.begin(), path.end(), B[u]) - path.begin();
    answer[u] = T == sz(path) ? -1 : path2[T];
    for(auto v : t[u]) dfs(v);
    path.pop_back();
    path2.pop_back();
}

int main(){    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        for(int i = 0; i < N; i++) p[i] = i;
        for(int i = 1; i < N; i++) {
            int u , v;
            cin >> u >> v;
            u--; v--;
            g[u].pb(v); g[v].pb(u);
        }
        for(int i = 0; i < N; i++) cin >> P[i];
        for(int i = 0; i < N; i++) cin >> A[i];
        for(int i = 0; i < N; i++) cin >> B[i];
        for(int i = N - 1; i >= 0; i--) {
            P[i]--;
            pos[P[i]] = i;
            for(auto j : g[P[i]])
                if(present[j])
                    unite(P[i] , j);
            present[P[i]] = 1;
        }
        dfs(P[0]);
        for(int i = 0; i < N; i++) {
            cout << answer[i] + 1 << " ";
            g[i].clear(); t[i].clear();
            present[i] = 0;
        }
        cout << endl;
    }           
    return 0;     
}