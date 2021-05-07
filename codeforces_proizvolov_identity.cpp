#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int p = 998244353;

int add(int a, int b) {
    return (a+b >= p) ? a+b-p : a+b;
}

int mul(int a, int b) {
    long long r = 1ll*a*b;
    return (r >= p) ? r%p : r;
}

int taakat(int x, int y) {
    long long r = 1;
    while(y) {
        if(y&1) r = mul(r, x);
        y >>= 1;
        x = mul(x, x);
    }
    return r;
}

void solve() {
    int n; cin >> n;
    int a[2*n];
    for(int i = 0; i < 2*n; i++) cin >> a[i];
    sort(a, a+2*n);
    
    int L = 0, R = 0;
    for(int i = 0; i < n; i++) {
        L = add(L, a[i]%p);
        R = add(R, a[i+n]%p);
    }

    int ans = R - L;
    if(ans < 0) ans += p;

    // calculate 2nCn
    int pro = 1;
    for(int i = 2; i < n+1; i++) {
        pro = mul(pro, i);
    }

    pro = taakat(pro, p-2);

    for(int i = 2*n; i > n; i--) pro = mul(pro, i);

    cout << mul(ans, pro);
}

int main() {
    fast
    int t = 1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}
