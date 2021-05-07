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

const int p = 1e9 + 7;
const int maxn = 1e5 + 2;

int min_Doori[maxn], n;                                  // Keeps minimum distance to each node
vpi E[maxn];                                            // Adjacency list

void dijk(int src) {
    for(int i = 1; i <= n; i++) min_Doori[i] = p;
    min_Doori[src] = 0;
    priority_queue< pii, vpi, greater<pii>> q;
    q.push({0, src});
    while(!q.empty()) {
        pii p = q.top();
        q.pop();

        int u = p.second, dist = p.first;
        if(dist > min_Doori[u]) continue;

        for(pii pr : E[u]) {
            int v = pr.first, nxt_dist = dist + pr.second;

            if(nxt_dist < min_Doori[v]) {
                min_Doori[v] = nxt_dist;
                q.push({nxt_dist, v});
            }
        }
    }
}