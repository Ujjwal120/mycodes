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

map<int,int> cnt;
void solve() {
    int k, n; cin >> k >> n;
    int a;
    cnt.clear();

    for(int i = 0; i < n; i++) {
        cin >> a;
        cnt[a]++;
    }

    if(n % k !=0 ) cout << "No\n";
    else {
        bool poss =  true;
        for(auto i = cnt.begin(); i != cnt.end(); i++) {
            if(i->second > n/k) {
                poss = false;
                break;
            }
        }

        if(poss) cout << "Yes\n";
        else cout << "No\n";
    }

}

int main() {
    fast 
    // input output
    int t = 1; 
    // cin>>t; 
    while(t--) solve();
    return 0;
}