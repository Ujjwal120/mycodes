#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define ll long long

using namespace std;

const int maxn = 35000;

vector<int> pr;
bitset<maxn> bs;
void sieve(){
    bs.set();
    pr.push_back(2);
    for(int i = 3; i < maxn; i += 2){
        if(bs[i]) {
            pr.push_back(i);
            for(ll j = 1LL*i*i; j < maxn; j += i) bs[j]=0;
        }
    }
}

ll taakat(ll x, ll y) {
    ll r = 1;
    while(y) {
        if(y&1) r *= x;
        y >>= 1;
        x *= x;
    }
    return r;
}

void solve() {
    ll p, q; cin >> p >> q;
    if((p%q) != 0) cout << p << "\n";
    else {
        ll temp = q;
        vector<int> yere;
        vector<int> cnt;
        for(int i = 0; i < pr.size(); i++) {
            if(temp%pr[i] == 0) {
                yere.pb(pr[i]);
                cnt.pb(0);
            }
            
            while(temp%pr[i] == 0) {
                temp /= pr[i];
                cnt[cnt.size()-1]++;
            }

            if(temp == 1) break;
        }

        if(temp != 1) {
            yere.pb(temp);
            cnt.pb(1);
        }

        temp = p;
        ll cum = 1e18+9;

        for(int i = 0; i < yere.size(); i++) {
            int power = 0;
            while(temp%yere[i] == 0) {
                temp /= yere[i];
                power++;
            }

            cum = min(cum, taakat(yere[i], power-cnt[i]+1));
        }
        cout << p / cum << "\n";
    }
}

int main() {
    fast sieve();
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}