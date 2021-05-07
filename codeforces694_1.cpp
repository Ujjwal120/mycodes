#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int maxn = 3e5+10;
map<int, int> group;

bitset<1001> bs;
vector<int> pr;

void sieve() {
    bs.set();
    pr.push_back(2);    

    for(int i = 3; i <= 1000; i += 2) {
        if(bs[i]) {
            pr.push_back(i);
            for(int j = i*i; j <= 1000; j += i) {
                bs[j] = 0;
            }
        }
    }
}

void solve() {
    int n; cin >> n;
    group.clear();

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        int temp = x;
        int pro = 1;
        for(int j = 0; j < pr.size(); j++) {
            if(temp == 1) break;

            bool acc = 0;
            while((temp % pr[j]) == 0) {
                temp /= pr[j];
                acc ^= 1;
            }
            
            if(acc) pro *= pr[j];
        }

        if(temp != 1) pro *= temp;
        group[pro]++;
    }

    int for_zero = -1, even = 0;
    for(auto i : group) {
        for_zero = max(for_zero, i.second);
        if(i.first == 1 || (i.second&1) == 0) even += i.second;
    }

    int q; cin >> q;
    for(int i = 0; i < q; i++) {
        long long x; cin >> x;
        if(x == 0) cout << for_zero << "\n";
        else cout << max(for_zero, even) << "\n";
    }
}

signed main() {
    fast int t; cin >> t;
    sieve();
    while(t--) solve();
    return 0;
}