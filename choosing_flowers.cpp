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
    int N, M, x, y;
    cin>>N>>M;
    vpi happy;
    ll a[M], b[M];
    for(int i=0;i<M;i++) {
        cin>>x>>y;
        happy.pb({x,y});
    }
    sort(happy.begin(), happy.end());
    ll psum[M];
    
    for(int i=M-1; i>=0; i--) {
        a[i]=happy[i].first;
        b[i]=happy[i].second;
        psum[i] = (i+1 > M-1) ? a[i]: psum[i+1] + a[i];
    }
    ll ans=INT_MIN;
    for(int i=0;i<M;i++) {
        int ind = upper_bound(a,a+M,b[i])-a;
        if(ind==M) {
            ans=max(ans, a[i] + (N-1)*b[i]);
        }
        else {
            if(M-ind <= N) {
                if(ind<=i) {
                    ans=max(ans, psum[ind] + (N-M+ind)*b[i]);
                }
                else ans=max(ans, psum[ind] + a[i] + (N-M+ind-1)*b[i]);
            }
            else ans=max(ans, psum[M-N]);
        }
    }
    cout<<ans<<"\n";
}

int main() {
    fast 
    // input output
    int t; cin>>t; 
    while(t--) solve();
    return 0;
}