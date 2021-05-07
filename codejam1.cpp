#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int cs = 0, X, Y;
vector<int> non_q;

int calc(int n, int mode) {
    if(n < 0) return 0;
    if(n == 0 && (mode == 0 || mode == 1)) return 0;
    if(n == 0) return (mode == 2) ? X : Y;
    
    int cum = X+Y;
    int ans;
    if(mode == 0 || mode == 1) {
        if(n&1) ans = min(0, cum + (n-1)/2*cum);
        else ans = min(0, cum*n/2);
    }
    if(mode == 2) {
        if(n&1) ans = min(X, X+cum*(n-1)/2);
        else ans = min(X, X+cum*n/2);
    }
    if(mode == 3) {
        if(n&1) ans = min(Y, Y+cum*(n-1)/2);
        else ans = min(Y, Y+cum*n/2);
    }

    return ans;
}

void solve() {
    string s;
    non_q.clear();
    cin >> X >> Y >> s;

    int n = s.length();

    for(int i = 0; i < n; i++) {
        if(s[i] != '?') non_q.push_back(i);
    }

    int ans = 0;
    if(non_q.empty()) {
        ans = min({calc(n-2, 0), calc(n-2, 1), calc(n-2, 2), calc(n-2, 3)});
    }
    else {
        int le = non_q.back();
        if(le != n-1) {
            if(s[le] == 'C') {
                ans += min(calc(n-le-2, 0), calc(n-le-2, 2));
            }
            else {
                ans += min(calc(n-le-2, 1), calc(n-le-2, 3));
            }
        }

        while(!non_q.empty()) {
            int sz = non_q.size();
            if(sz == 1 && non_q[0] == 0) {
                non_q.pop_back(); continue;
            }

            if(sz == 1) {
                int le = non_q[0];
                if(s[le] == 'C') {
                    ans += min(calc(le-1, 0), calc(le-1, 3)); 
                }
                else {
                    ans += min(calc(le-1, 1), calc(le-1, 2)); 
                }
            }
            else {
                int l = non_q[sz-2], r = non_q[sz-1];
                if(s[l] == 'C' && s[r] == 'C') ans += calc(r-l-1, 0);
                if(s[l] == 'J' && s[r] == 'J') ans += calc(r-l-1, 1);
                if(s[l] == 'C' && s[r] == 'J') ans += calc(r-l-1, 2);
                if(s[l] == 'J' && s[r] == 'C') ans += calc(r-l-1, 3);
            }

            non_q.pop_back();
        }
    }
    
    cout << "Case #" << ++cs << ": " << ans << "\n";
}

signed main() {
    fast int t;
    // output
    cin >> t;
    while(t--) solve();
}