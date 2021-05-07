#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long 

using namespace std;

const int maxn = 2e5+10;
const int p = 998244353;

int n;

int mul(int a, int b) {
    int r = a*b;
    if(r >= p) return r%p;
    else return r;
}

int add(int a, int b) {
    int s = a+b;
    if(s >= p) return s-p;
    else return s;
}

int taakat(int x, int y) {
    int r = 1;
    while(y) {
        if(y&1) r = mul(r, x);
        y >>= 1;
        x = mul(x, x);
    }
    return r;
}

int fib[maxn];

void solve() {
    int n; cin >> n;
    int ans = taakat(2, n*(p-2));
    fib[1] = 1; fib[2] = 1; 
    for(int i = 3; i <= n; i++) fib[i] = add(fib[i-1], fib[i-2]);
    cout << mul(fib[n], ans);
}

signed main() {
    fast int t = 1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}

