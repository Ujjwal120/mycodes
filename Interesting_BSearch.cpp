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
 
const int p = 1e9 + 7;
const int maxn = 1e5 + 2;

bool doesitexceed (vi a, int mid, int K) {
    int total_cuts = 0;
    for(int i : a) {
        total_cuts += (i <= mid) ? 0 : ((i % mid != 0) ? i/mid : i/mid -1); 
    }
    return total_cuts > K;
}

void solve() {
    int N, K; cin>>N>>K;
    vi a; a.resize(N);
    for(int i = 0; i < N; i++) cin >> a[i]; 
    int beg = 1, end = p, mid;
    while(beg != end) {
        mid = beg + (end - beg)/2;
        if(doesitexceed(a, mid, K)) beg = mid + 1;
        else end = mid;
    }
    cout<<beg<<"\n";
}

int main() {
    fast 
    // input output
    int t=1; 
    // cin>>t; 
    while(t--) solve();
    return 0;
}
