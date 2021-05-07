// mod of two equation same 

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll gcd (ll a, ll b) {
    return ( a == 0 ) ? b : gcd (b%a, a);
}

void solve () {
    ll m, d, w; cin >> m >> d >> w;
    ll bound = min(d, m);
    ll w_ = w / gcd(d-1, w);
    if(bound <= w_) cout << 0 <<"\n";
    else {
        ll K = bound / w_;
        ll rem = bound % w_;
        ll ans = (K * (K-1))/2 * w_ + K * rem;
        cout << ans << "\n";  
    } 
}

int main() {

    return 0;
}