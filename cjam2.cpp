#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int cs = 0;
vector<int> a, prefix;

void solve() {
    int n, c; cin >> n >> c;
    int max_poss_cost = n*(n+1)/2 - 1;

    bool poss = true;
    a.resize(n, 0);
    
    prefix.resize(n-1);
    for(int i = 0; i < n-1; i++) prefix[i] = n-i-1;
    for(int i = 1; i < n-1; i++) prefix[i] += prefix[i-1];

    if(c > max_poss_cost || c < n-1) {
        poss = false;
    }
    else {
        int to_rem = max_poss_cost-c;
        int ind = lower_bound(prefix.begin(), prefix.end(), to_rem) - prefix.begin();
        if(prefix[ind] != to_rem) ind--;

        for(int i = 0; i <= ind; i++) a[i] = i+1; 

        int extra_rem = (ind >= 0) ? to_rem - prefix[ind] : to_rem - 0;

        int l = ind+1, r = n-1;
        bool sabotage = false;
        bool left_turn = false;
        int num = l+1;

        while(l <= r) {
            if(!sabotage && extra_rem != 0) {
                if(l == r) break;
                if(num == n-extra_rem) {
                    sabotage = true;
                    if(left_turn) a[l++] = n;
                    else a[r--] = n;
                }
                else {
                    if(left_turn) a[l++] = num;
                    else a[r--] = num;
                    num++;
                    left_turn ^= 1;
                }
            }
            else if(l <= r){
                if(left_turn) a[l++] = num;
                else a[r--] = num;
                num++;
                left_turn ^= 1;
            }
        }
    }

    cout << "Case #" << ++cs << ": ";
    // here either array or IMPOSSIBLE
    if(poss) {
        for(int i = 0; i < n; i++) cout << a[i] << " ";
    }
    else cout << "IMPOSSIBLE";
    cout << "\n";
}

signed main() {
    fast int t;
    // output
    cin >> t;
    while(t--) solve();
}