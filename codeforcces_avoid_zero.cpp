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

void solve() {
   int n; cin >> n;
   vi pos, neg; int zero = 0;
   for(int i = 0; i < n; i++) {
       int x; cin >> x;
       if(x < 0) neg.pb(x);
       else if(x > 0) pos.pb(x);
       else {
           zero++;
       }
   }

   int sum1 = accumulate(pos.begin(), pos.end(), 0);
   int sum2 = accumulate(neg.begin(), neg.end(), 0);

   if(sum1 + sum2 == 0 || zero == n) cout << "NO\n";
   else {
       cout << "YES\n";
       if(sum1 > abs(sum2)) {
            for(int x : pos) cout << x << " ";  
            for(int x : neg) cout << x << " ";
       }
       else {
            for(int x : neg) cout << x << " ";  
            for(int x : pos) cout << x << " ";
       }
       
       for(int i = 0; i < zero; i++) cout << "0 ";
       cout << "\n";
   }
}

int main() {
    fast
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}