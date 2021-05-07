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
const int maxn=2e5+2;
map<ll, vl> R, L;
map<ll, ll> valL, valR;

int main() {
    fast 
    // input output
    int t, c = 1, x, y;
    for(cin >> t; t--;) {
        ll ans = 0;
        R.clear(); L.clear(); valR.clear(); valL.clear();
        int N; cin >> N;
        vpi PosHei;
        for(int i = 0; i < N; i++) {
            cin >> x >> y;
            PosHei.pb({x, y});
        }
        
        sort(PosHei.begin(), PosHei.end());
        
        for(int i = 0; i < PosHei.size(); i++) {
            ll endpoint = PosHei[i].first + PosHei[i].second;
            ll pos = PosHei[i].first;
            R[endpoint].pb(pos);
        }
        
        for(int i = PosHei.size() - 1; i >= 0; i--) {
            ll endpoint = PosHei[i].first - PosHei[i].second;
            ll pos = PosHei[i].first;
            L[endpoint].pb(pos);
        }
        
        for(auto i = R.begin(); i != R.end(); i++) {
            vl vec = i->second;
            ll endpoint = i->first;
            ll m = INT_MIN;
            for(int j=0; j<vec.size(); j++) {
                m = max(m, endpoint - vec[j] + valR[vec[j]]);
            }
            valR[endpoint] = m;
            ans = max(ans, m);
        }

        map<ll,vl> :: reverse_iterator it;
        
        for(it = L.rbegin(); it != L.rend(); it++) {
            vl vec = it->second;
            ll endpoint = it->first;
            ll m = INT_MIN;
            for(int j=0; j<vec.size(); j++) {
                m = max(m, vec[j] - endpoint + valL[vec[j]]);
            }
            valL[endpoint] = m;
            ans = max(ans, m);
        }
        
        for(auto i = R.begin(); i != R.end(); i++) {
            if(valL[i->first]) {
                ans = max(ans, valL[i->first] + valR[i->first]);
            }
        }

        cout << "Case #" << c++ << ":" << " " << ans << "\n";
    }
    return 0;
}