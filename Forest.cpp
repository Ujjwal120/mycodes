// connected components in forest = total vertices - edges

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
using namespace std;
 
const int p=1e9+7;
const int maxn=1e5+2;

void solve() {
    ll N, u, v; cin >> N;
    ll sum = 0;
    for(int i = 0; i < N-1; i++) {
        cin >> u >> v;
        if(u > v) swap(u, v);
        sum -= u * (N - v + 1);
    }
    for(int i = 1; i <= N; i++) {
        sum += i * (N - i + 1);
    }
    cout << sum <<"\n";
}

int main() {
    fast 
    // input output
    int t=1; 
    // cin>>t; 
    while(t--) solve();
    return 0;
}