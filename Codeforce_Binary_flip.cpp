#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define input freopen("1.txt","r",stdin);
#define output freopen("output.txt","w",stdout);
#define ll long long int
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define vii vector<vi>
#define vl vector<ll>
#define vll vector<vl>
#define pll pair<ll,ll>
#define mp make_pair
#define vpl vector<pll> 
using namespace std;
 
const int p=1e9+7;
const int maxn=2e5+2;

void solve() {
    int N;
    cin>>N;
    string x, y;
    cin>>x>>y;
    int a[N], b[N];
    for(int i=0;i<N;i++) a[i]=x[i]-'0';
    for(int i=0;i<N;i++) b[i]=y[i]-'0';
    vi len; 
    int inv=0, Z=0, C=N-1;
    for(int i=N-1;i>=0;i--) {
        if(inv&1) {
            if((a[C]^1)!=b[i]) {
                if((a[Z]^1)==b[i]) len.pb(1);
            }
            else {
                C++;
                continue;
            }
            len.pb(Z-C+1);
            swap(Z,C); C--;
            inv++;
        }
        else {
            if(a[C]!=b[i]) {
                if(a[Z]==b[i]) len.pb(1);
            }
            else {
                C--;
                continue;
            }
            len.pb(C-Z+1);
            swap(Z,C); C++;
            inv++;
        }
    }
    cout<<len.size()<<" ";
    for(int i=0;i<len.size();i++) cout<<len[i]<<" ";
    cout<<"\n";
}

int main() {
    fast
    int t; cin>>t; 
    while(t--) solve();
    return 0;
}