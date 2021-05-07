#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int maxn = 3e4+10;

int a[maxn];
void solve() {
    int n; cin >> n;
    int zero = 0, one = 0, two = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        int rem = a[i]%3;
        zero += (rem == 0); one += (rem == 1); two += (rem == 2);
    }

    int ans = 0;
    int nby3 = n/3;
    if(zero > nby3) {
        if(one < nby3) {
            int save = min(nby3-one, zero-nby3);
            one += save; zero -= save;
            ans += save;
        }

        if(two < nby3) {
            int save = min(nby3-two, zero-nby3);
            two += save; zero -= save;
            ans += save*2;
        }
    }

    if(one > nby3) {
        if(two < nby3) {
            int save = min(nby3-two, one-nby3);
            two += save; one -= save;
            ans += save;
        }

        if(zero < nby3) {
            int save = min(nby3-zero, one-nby3);
            zero += save; one -= save;
            ans += save*2;
        }
    }

    if(two > nby3) {
        if(zero < nby3) {
            int save = min(nby3-zero, two-nby3);
            zero += save; two -= save;
            ans += save;
        }

        if(one < nby3) {
            int save = min(nby3-one, two-nby3);
            one += save; two -= save;
            ans += save*2;
        }
    }

    cout << ans << "\n";
}

signed main() {
    fast int t;
    cin >> t;
    while(t--) solve();
    return 0;
}