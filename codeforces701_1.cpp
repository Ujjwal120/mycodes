#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long 

using namespace std;

const int maxn = 1e5+10;
int n, q, k, a[maxn];

int tree[2*maxn];

int query(int l, int r) {
    l += n; r+= n;
    int res = 0;
    for(; l < r; l >>= 1, r >>= 1) {
        if(l&1) res += tree[l++];
        if(r&1) res += tree[--r];
    }
    return res;
}

void solve() {
    cin >> n >> q >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    tree[n] = a[1]-2;
    tree[2*n-1] = k-a[n-2]-1;
    for(int i = 1; i < n-1; i++) {
        tree[i+n] = a[i+1]-a[i-1]-2;
    }

    for(int i = n-1; i > 0; i--) tree[i] = tree[i<<1] + tree[i<<1|1];

    for(int i = 0; i < q; i++) {
        int x, y; cin >> x >> y;
        if(x == y) {
            cout << k-1 << "\n"; continue;
        } 
        y--;
        cout << a[x]-2 + k-a[y-1]-1 + query(x, y) << "\n";
    }
}

signed main() {
    fast int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}