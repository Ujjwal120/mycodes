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

map<int, pair<int, int>> arr;

void solve() {
    ll n; cin >> n;
    ll lastdig = n%10;
    arr.clear();
    
    for(int i = 1; i <= 10; i++) {
        arr[9*i%10] = {i, 9*i};
    }
    
    if(arr.count(lastdig) == 1) {
        if(n >= arr[lastdig].second) cout << arr[lastdig].first << "\n";
        else cout << -1 << "\n";
    }
    else cout << "-1\n";
}

int main() {
    fast
    int t; cin >> t;
    while(t--) solve();
    return 0;
}