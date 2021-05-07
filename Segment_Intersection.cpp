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
    ll N, K; cin >> N >> K;
    ll l1, r1, l2, r2;
    cin>> l1 >> r1 >> l2 >> r2;
    // coincide ?
    if(min(r2, r1) >= max(l1, l2)) {
        ll common = N * (min(r2, r1) - max(l1, l2));

        if(common >= K) cout << 0 << "\n";
        else {
            K -= common;
            ll acc = N * (max(r2, r1) - min(l1, l2)) - common;
            ll steps = 0;
            if( K > acc) steps += acc + 2 * (K - acc);
            else steps = K;
            cout << steps << "\n";
        }
    }
    else {
        ll extra = max(l1, l2) - min(r1, r2); // per segment
        ll steps = 0;
        ll acc = extra + (r1 - l1) + (r2 - l2); 

        if(K > acc) {
            steps += acc + extra; // acc is the max available length each increment in steps for full interval adds extra  as cost
            K -= acc;
            ll after_first = 0;
            ll temp = K;
            N--;
            while(temp != 0 && N  != 0) {
                if(temp > acc) {
                    after_first += min(acc + extra, 2 * acc);
                    temp -= acc; 
                }
                else {
                    after_first += min(extra + temp, 2 * temp);
                    temp = 0;
                }
                N--;
            }

            if(temp) after_first += temp * 2;

            cout << steps + after_first << "\n";
        }
        else {
            steps = K + extra;
            cout << steps << "\n";
        }
    }
}

int main() {
    fast 
    // input output
    int t; cin>>t; 
    while(t--) solve();
    return 0;
}

