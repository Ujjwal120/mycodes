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
const int maxn = 32000;

bitset<maxn> bs;
vi pr;

void sieve(){
    bs.set();
    pr.push_back(2);
    for(int i = 3; i < maxn; i += 2){
        if(bs[i]) {
            pr.push_back(i);
            for(ll j = 1LL*i*i; j < maxn; j += i) bs[j] = 0;
        }
    }
}

vi fact, cnt, divi, useles;

void solve() {
    int n; cin >> n;
    int temp = n;
    fact.clear(); divi.clear(); cnt.clear();

    for(int i = 0; i < pr.size(); i++) {
        if(temp == 1) break;
        int tt = 0;
        while(temp % pr[i] == 0) {
            temp /= pr[i];
            tt++;
        }

        if(tt > 0) {
            fact.pb(pr[i]); cnt.pb(tt);
        }
    }
    
    if(temp != 1) {
        fact.pb(temp); cnt.pb(1);
    }

    for(int i = 0; i < fact.size(); i++) {
        useles.clear();
        int pro = 1;
        for(int j = 1; j <= cnt[i]; j++) {
            pro *= fact[i];
            useles.pb(pro);
        }

        int sz = divi.size();
        for(int j = 0; j < useles.size(); j++) {
            for(int k = sz-1; k >= 0; k--) {
                divi.pb(useles[j]*divi[k]);
            }
        }
        
        for(int j = 0; j < useles.size(); j++) divi.pb(useles[j]);
    }

    int sz = divi.size();
    
    if(fact.size() > 1)
    swap(divi[sz-1], divi[sz-1-cnt[cnt.size()-1]]);
    
    int ans = accumulate(cnt.begin(), cnt.end(), 0);
    
    
    for(int x : divi) cout << x << " ";
    cout << "\n";
    
    if(ans > 2 || ((ans == 2) && (fact.size() == 1))) cout << "0\n";
    else cout << 1 << "\n";
}

int main() {
    fast
    sieve();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}