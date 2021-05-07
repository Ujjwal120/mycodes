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
const int maxn = 1e6;
int n, k;

struct th{
    ll diff, big, small;
    bool L, R;
};

vector<th> backtrack;

priority_queue<ll> q;
map<ll, vi> np_bits;
vector<bool> ans;

void solve() {
    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        if(k == 1) q.push(i+1);
        else if(k == 2) q.push(1ll*(i+1)*(i+1));
        else if(k == 3) q.push(1ll*(i+1)*(i+1)*(i+1));
        else {
            ll x = 1ll*(i+1)*(i+1);
            x *= x;
            q.push(x);
        }
    }

    backtrack.clear();
    backtrack.resize(n);
    
    int r = n-1;
    np_bits.clear();
    
    while(q.size()>1) {
        ll f = q.top(); q.pop();
        ll s = q.top(); q.pop();
        q.push(f-s);
        np_bits[f-s].pb(0);
        
        if(np_bits[f].size() == 0) backtrack[r].R = true;
        else  backtrack[r].R = false; 

        if(np_bits[s].size() == 0) backtrack[r].L = true;
        else  backtrack[r].L = false;

        backtrack[r].diff = f-s;
        backtrack[r].big = f;
        backtrack[r].small = s;
        r--;
    }

    for(int i = 1; i <= n-1; i++) {
        cout << backtrack[i].small << " " << backtrack[i].big << "\n";
        cout << backtrack[i].L << " " << backtrack[i].R << "\n";
    }
    
    cout << q.top() << "\n";
    q = priority_queue<ll>();
}

int main() {
    fast
    cin >> k;
    int t; cin >> t;
    while(t--) solve();
    return 0;
}