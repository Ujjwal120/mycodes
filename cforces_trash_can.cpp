#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define input freopen("1.txt","r",stdin);
#define output freopen("output.txt","w",stdout);
#define ll long long int
#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define vi vector<int>
#define vii vector<vi>
#define vl vector<ll>
#define vll vector<vl>
#define pii pair<int, int>
#define pll pair<ll,ll>
#define mp make_pair
#define vpi vector<pii>
#define vpl vector<pll> 
#define ss second 
#define ff first

using namespace std;

const int p = 1e9 + 7;
const int maxn = 1e5 + 1;

set<int> all;
multiset<int> maxgap;

void solve() {
    int n, q, x, y; cin >> n >> q; 
    for(int i = 0; i < n; i++) {
        cin >> x;
        all.insert(x);
    }

    for(auto i = next(all.begin()); i != all.end(); i++) {
        maxgap.insert(*i - *prev(i));
    }       

    if(n > 2) {
        int beg = *all.begin(), end = *prev(all.end());
        cout << end - beg - *prev(maxgap.end()) << "\n";
    }
    else cout << 0 << "\n";


    for(int i = 0; i < q; i++) {
        cin >> x >> y;
        if(x) { 
            all.insert(y); 
            auto it = all.find(y); 
            
            if(it != all.begin() && it != prev(all.end())) {
                maxgap.insert(*it - *prev(it)); 
                maxgap.insert(*next(it) - *it); 
                auto del1 = maxgap.find(*next(it) - *prev(it));
                maxgap.erase(del1);
            }
            else if(it != all.begin()) maxgap.insert(*it - *prev(it));
            else maxgap.insert(*next(it) - *it);
        }
        else {
            auto it = all.find(y); 
            if(it != all.begin()) {
                auto del1 = maxgap.find(*it - *prev(it));
                maxgap.erase(del1);
            }
            
            if(next(it) != all.end()) {
                auto del1 = maxgap.find(*next(it) - *it);
                maxgap.erase(del1);
            }
            
            if(it != all.begin() && it != prev(all.end())) maxgap.insert(*next(it) - *prev(it));
            all.erase(it);
        }
        
        if(all.size() > 2) {
            int beg = *all.begin(), end = *prev(all.end()); 
            cout << end - beg - *prev(maxgap.end()) << "\n";
        }
        else cout << 0 << "\n";
    }
}

int main() {
    fast
    int t = 1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}