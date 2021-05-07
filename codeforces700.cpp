#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

const int maxn = 1e5+10;

int a[maxn], b[maxn];

void solve() {
    int A, B, n;
    cin >> A >> B >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    bool poss = true;

    for(int i = 0; i < n; i++) {
        if(B <= 0) {
            poss = false; break;
        }

        if(b[i] > A) {
            int turn = (b[i]%A == 0) ? b[i]/A-1 : b[i]/A; 
            B -= turn*a[i];
            b[i] -= turn*A;
        }
    }

    if(poss) {
        sort(a, a+n);
        for(int i = 0; i < n; i++) {
            if(B <= 0) {
                poss = false; break;
            }
            B -= a[i];
        }
    }

    if(poss) cout << "YES\n";
    else cout << "NO\n";
}

signed main() {
    fast int t; cin >> t;
    while(t--) solve();
    return 0;
}
