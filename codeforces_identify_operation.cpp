#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

const int maxn = 2e5+1;
const int p = 998244353;

int mul(int a, int b) {
    int r = a*b;
    if(r >= p) return r%p;
    return r;
}

int ind[maxn], a[maxn], b[maxn];
set<int> a_ind, B;

void solve() {
    int n, k; cin >> n >> k;
    a_ind.clear();
    B.clear();
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        ind[a[i]] = i; a_ind.insert(i);
    }

    for(int i = 0; i < k; i++) {
        cin >> b[i];
        B.insert(b[i]);
    }

    int ans = 1;
    for(int i = 0; i < k; i++) {
        auto it = a_ind.find(ind[b[i]]);
        // cout << *it << " ";
        if(it == a_ind.begin()) {
            // cout << "first\n";
            auto it1 = B.find(a[*next(it)]);
            if(it1 == B.end()) {
                a_ind.erase(next(it));
            }
            else {
                ans = 0; break;
            }
        }
        else if(it == prev(a_ind.end())) {
            // cout << "sec\n";
            auto it1 = B.find(a[*prev(it)]);
            if(it1 == B.end()) {
                a_ind.erase(prev(it));
            }
            else {
                ans = 0; break;
            }
        }
        else {
            // cout << "YES mid ";
            auto it1 = B.find(a[*next(it)]);
            auto it2 = B.find(a[*prev(it)]);
            // cout << (it1 == B.end()) << " " << (it2 == B.end()) << "\n";
            if(it1 == B.end() && it2 == B.end()) {
                ans = mul(ans, 2);
                a_ind.erase(next(it));
            }
            else if(it1 != B.end() && it2 != B.end()){
                ans = 0; break;
            }
            else if(it1 != B.end()) {
                a_ind.erase(prev(it));
            }
            else a_ind.erase(next(it));
        }
        // cout << " " << ans << "\n";
        B.erase(B.find(b[i]));
    }
    // cout << "\n";
    cout << ans << "\n";
}

signed main() {
    fast
    int t; cin >> t;
    while(t--) solve();
    return 0;
}