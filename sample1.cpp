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
    int n, k; cin >> n >> k;

    if(n >= k) {
        if((k%2==0 && n%2==0) || (k%2==1 && n%2==1)) cout << 0 << "\n";
        else cout << 1 << "\n";
    }
    else cout << k - n << "\n";
}

int main() {
    fast   // input output
    int t; cin>>t; 
    while(t--) solve();
    return 0;
}