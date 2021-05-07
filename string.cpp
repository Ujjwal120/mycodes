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
    string s;
    getline(cin,s);
    int prev[257]; memset(prev, -1, sizeof(prev));
    int ans = 0, subs = 0;
    int beg = 0;
    for(int i=0; i < s.length(); i++) {
        if(prev[s[i]] == -1 || (prev[s[i]] != -1 && prev[s[i]] < beg) ) {
            prev[s[i]] = i;
            subs++;
        }
        else {
            beg = prev[s[i]];
            subs = i - beg;
            prev[s[i]] = i;
        }
        ans = max(ans, subs);
    }
    cout<<ans<<"\n";
}

int main() {
    fast 
    // input output
    int t; cin>>t; 
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while(t--) solve();
    return 0;
}