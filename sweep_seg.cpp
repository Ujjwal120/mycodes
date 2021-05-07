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
const int maxn = 1e6;

int tree[2*(maxn+1)], n, m;

vpi V(maxn+1);
vector<bool> ex(maxn+1, 0);

vi s[maxn+1], e[maxn+1];

void modify(int p, int val) { 
    p += maxn; tree[p] = val; 
    for(; p > 1; p >>= 1) tree[p>>1] = tree[p] + tree[p^1];
}

ll query(int l, int r) {  
    ll res = 0;
    for (l += maxn, r += maxn; l < r; l >>= 1, r >>= 1) {
    if(l&1) res += tree[l++];
    if(r&1) res += tree[--r];
    }
    return res;
}

void solve() {
    cin >> n >> m;
    int z ,x ,y;
    ll ans = 1;
    for(int i = 0; i < n; i++) {
        cin >> z >> x >> y;
        s[x].pb(z); e[y].pb(z);
        if(x == 0) modify(z, 1);
        if(x == 0 && y == maxn) ans++;
    }
    modify(0, 1);
    modify(maxn,1);

    for(int i = 0; i < m; i++) {
        cin >> x >> y >> z;
        ex[x] = 1; V[x] = {y, z};
    }

    for(int i = 1; i < maxn; i++) {
        if(!s[i].empty()) {
            for(int j : s[i]) modify(j, 1);
        }
        if(ex[i]) {
            ans += query(V[i].first, V[i].second + 1) - 1;
        }
        if(!e[i].empty()) {
            for(int j : e[i]) modify(j, 0);
        }
    }
    cout << ans << "\n";
}

int main() {
    fast
    int t = 1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}
