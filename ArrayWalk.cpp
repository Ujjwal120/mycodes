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
    int N, k, z; cin>>N>>k>>z;
    int a[N];
    for(int i=0;i<N;i++) cin>>a[i];
    int ans = a[0];
    int presum[N+1] = {0};
    for(int i=1;i<=k;i++) presum[i]=presum[i-1] + a[i]; 
    if(z==0) {
        cout<<presum[k] + a[0]<<"\n";
    }
    else {
        for(int i=1;i<=k;i++) {
            int temp = a[0];
            int movesleft = k - i;
            int zigzag = min(movesleft/2, z);
            if(zigzag == 0) {
                temp += presum[i];
                temp += movesleft*a[i-1];
            }
            else {
                if(zigzag*2 == movesleft) temp+=presum[i];
                else{
                    if(zigzag==z) temp+=presum[i+movesleft-zigzag*2];
                    else temp+=presum[i]+a[i-1];
                }
                temp += zigzag*(a[i]+a[i-1]);
            }
            ans = max(ans, temp);
        }
        cout<<ans<<"\n";
    }
}

int main() {
    fast 
    // input output
    int t; cin>>t; 
    while(t--) solve();
    return 0;
}