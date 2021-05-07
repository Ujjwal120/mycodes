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
 
const int p = 1e9+7;
const int maxn = 1e5 + 1;
 
void solve() {
    ll n, s; cin >> n >> s;
    vpl dig;
    ll temp = n;
    ll j = 1;
    while(temp > 0) {
        dig.pb({temp%10, j}); 
        j *= 10; temp /= 10;
    } 

    ll sum = 0;
    int ind = -1; bool okay = true;

    for(int i = dig.size()-1; i >= 0; i--) {
        sum += dig[i].ff;
        if(sum >= s) {
            if(ind == -1) ind = i;
            if(sum > s) {
                okay = false; break;
            }
        } 
    }

    if(okay) cout << "0\n";
    else {
        ll ans = 0;
        sum = 0;
        int non_nine_ind = -1;
        for(int i = ind+1; i < dig.size(); i++) {
            if(dig[i].ff < 9) {
                non_nine_ind = i; break;
            }
        }

        if(non_nine_ind == -1) {
            ans += dig[dig.size()-1].ss*10;
        }
        else {
            for(int i = non_nine_ind+1; i < dig.size(); i++) {
                ans += dig[i].ff * dig[i].ss;
                sum += dig[i].ff;
            }
            sum += dig[non_nine_ind].ff+1;
            ans += (dig[non_nine_ind].ff+1)*dig[non_nine_ind].ss;
        }

        // cout << ans << " : ";
        ans -= n;
        cout << ans << "\n";
    }
}
 
int main() {
    fast
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}


