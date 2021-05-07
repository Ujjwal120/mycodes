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
    ll n; cin >> n;
    ll actualsum;
    cout << 1 << " " << (1 << 20) << endl;
    fflush(stdout);
    cin >> actualsum;
    actualsum -= n * (1 << 20);
    ll pro = 1;
    ll temp, XOR = 0;

    if(actualsum&1) XOR = 1;

    for(int i = 1; i <= 19; i++) {
        cout << 1 << " " << (1<<i) << endl;
        fflush(stdout);
        cin >> temp;
        if(temp > actualsum) {
            ll diff = temp - actualsum;
            if(diff == n*(1<<i)) continue;
            diff /= (1<<i);
            ll bitson = n - (diff+n)/2;
            if(bitson&1) XOR += (1<<i);
        }
        else {
            ll diff = actualsum - temp;
            diff /= (1<<i);
            ll bitson = (diff+n) / 2;
            if(bitson&1) XOR += (1<<i);
        }
    }
    cout << 2 << " " << XOR << endl;
    fflush(stdout);
    cin >> temp;
    assert(temp == 1);
}

int main() {
    fast
    int t; cin >> t;
    while(t--) solve();
    return 0;
}