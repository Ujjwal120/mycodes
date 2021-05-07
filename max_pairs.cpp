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
map<int,int> tw;
map<int,int> teams;

void solve() {
    int N; cin>>N;
    int w[N];
    teams.clear(); tw.clear();
    for(int i=0;i<N;i++) {
        cin>>w[i]; tw[w[i]]++;
    }
    
    for(auto i = tw.begin(); i!=tw.end(); i++) {
        for(auto j = i; j!=tw.end(); j++) {
            if(j==i) teams[2*(i->first)] += (i->second)/2;
            else {
                teams[i->first + j->first] += min(i->second,j->second);
            }
        }
    }
    int ans = 0;
    for(auto i = teams.begin(); i!=teams.end(); i++) ans= max(ans,i->second);
    cout<<ans<<"\n";
}

int main() {
    fast 
    // input output
    int t; cin>>t; 
    while(t--) solve();
    return 0;
}