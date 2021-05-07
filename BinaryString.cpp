// create minimum subsequences that follow a particular order and prinnt their subsequence no too

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
    
vi ezero, eone, subs;
void solve() {
    int N; cin>>N;
    string s; cin>>s;
    ezero.clear(); eone.clear(); subs.clear();
    if(s[0] == '1') eone.pb(1);
    else ezero.pb(1);
    int total = 1;
    subs.pb(1);
    for(int i=1;i<s.length();i++) {
        if(s[i]=='1') {
            if(!ezero.empty()) {
                int subno = ezero[0];
                ezero.erase(ezero.begin());
                subs.pb(subno);
                eone.pb(subno);
            }
            else {
                total++; eone.pb(total); subs.pb(total);
            }
        }
        else {
            if(!eone.empty()) {
                int subno = eone[0];
                eone.erase(eone.begin());
                subs.pb(subno);
                ezero.pb(subno);
            }
            else {
                total++; ezero.pb(total); subs.pb(total);
            }
        }
    }

    cout<<total<<"\n";
    for(int x : subs) cout<<x<<" ";
    cout<<"\n";
}

int main() {
    fast 
    // input output
    int t; cin>>t; 
    while(t--) solve();
    return 0;
}