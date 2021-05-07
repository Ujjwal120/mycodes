#include<bits/stdc++.h>
#define ll long long 
#define vi vector<int>
#define vii vector<vi>
#define pb push_back
#define ppb pop_back

using namespace std;

const int maxn = 1e5 + 5;
const int p = 1e9 + 7;

priority_queue<pair<ll, int>> q;
ll e[maxn], r[maxn];
int cs = 1;

void solve() {
    
    int n; cin >> n;
    q = priority_queue<pair<ll, int>>();
    ll sum = 0, ans;
    
    for(int i = 0; i < n; i++) {
        cin >> e[i] >> r[i];
        sum += e[i]; 
    }
    
    ans = sum;
    int rem = p;
    int totrem = 0;
    ll cur = sum; 
    
    for(int i = 0; i < n; i++) {
        q.push({e[i] + r[i], i});
        ll check = q.top().first;
        int ind = q.top().second;
        if(check > sum) {
            q.pop();
            sum -= e[ind] + e[ind];
            cur -= e[ind] + e[ind];
            if(ind == i) { sum += e[i]; cur += e[i]; }
            totrem++;
        }
        else cur += e[i];
        
        if(ans < cur) { ans = cur; rem = totrem; }
    }
    
    if(!q.empty()) {
        ll check = q.top().first;
        int ind = q.top().second;
        if(check > sum) {
            q.pop();
            sum -= e[ind] + e[ind];
            totrem++;
        }
    }
    
    if(rem == p) rem = 0;
    
    if((int)q.size() > 1) {
        cout << "Case #" << cs << ": " << n - (int)q.size() << " " << "INDEFINITELY\n";
    }
    else cout << "Case #" << cs << ": " << rem << " " << ans << "\n";
    cs++; 
}

signed main() {
    int t; cin >> t;
    while(t--) solve();
    return 0;
}