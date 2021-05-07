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

const int p = 1e9+7;
const int maxn = 1e5 + 1;
vii slope_colour;
int w[3001]; 
ll dp[3001][3001], val[3001];
int dp_size;
map<int,int> cnt;
vi temp, one;

void solve() {
    int n , c, k; cin >> n >> c >> k;
    int x, y, z;
    slope_colour.clear(); slope_colour.resize(c+1);
    for(int i = 0; i < n; i++) {
        cin >> x >> y >> z;
        slope_colour[z].pb(x);
    }

    for(int i = 1; i <= c; i++) cin >> w[i];

    // preprocess

    ll tri = 0;   
    dp_size = 0;
    int c_ind[3001];

    for(int i = 1; i <= c; i++) {
        if(! slope_colour[i].empty()) {
            cnt.clear();
            temp.clear();
            one.clear();
            
            for(int slope : slope_colour[i]) {
                cnt[slope]++;
            }

            ll pro = 1;                             // calculate no of colour traingles
            for(auto j = cnt.begin(); j != cnt.end(); j++) {
                if(j->second != 1) {
                    temp.pb(j->second); pro *= j->second;
                }
                else one.pb(1);    
            }
            
            sort(temp.begin(), temp.end());

            int x = (int)temp.size(), y = (int)one.size();
            
            int as = x + y;
            if(as < 3) continue;

            if(x < 2) {
                temp.clear();
                one.resize(y - (2-x));
            }
            else temp.resize(x - 2);
            

            int sz = (int)cnt.size();               // distinct sloped triangle
            ll nc3 = 1LL* sz * (sz - 1) * (sz - 2) / 6;
            ll c_tri = pro * nc3;
            tri += c_tri;
                                                    // havent initialised val array check if it is needed

            while(!one.empty() || !temp.empty()) {
                if((! one.empty()) && (! temp.empty())) {
                    if( (temp[0] - 1) * sz <= temp[0] * (sz - 3) ) {
                        ++dp_size;
                        pro /= temp[0];
                        temp[0]--;
                        pro *= temp[0];
                        val[dp_size] = c_tri - (pro*nc3);
                        c_tri = pro * nc3;
                        c_ind[dp_size] = i;
                        if(temp[0] == 1) {
                            one.pb(1); 
                            temp.erase(temp.begin());
                        }
                    }
                    else {
                        ++dp_size;
                        val[dp_size] = pro * (sz-1) * (sz-2) / 2;
                        c_ind[dp_size] = i;
                        c_tri -= val[dp_size];
                        sz--;
                        nc3 = 1LL* sz * (sz - 1) * (sz - 2) / 6;
                        one.erase(one.begin());
                    }
                }
                else if( !one.empty() ) {
                    ++dp_size;
                    val[dp_size] = pro * (sz-1) * (sz-2) / 2;
                    c_ind[dp_size] = i;
                    sz--;
                    nc3 = 1LL* sz * (sz - 1) * (sz - 2) / 6;
                    one.erase(one.begin());
                }
                else {
                    ++dp_size;
                    pro /= temp[0];
                    temp[0]--;
                    pro *= temp[0];
                    val[dp_size] = c_tri - (pro*nc3);
                    c_tri = pro * nc3;
                    c_ind[dp_size] = i;
                    if(temp[0] == 1) {
                        one.pb(1); 
                        temp.erase(temp.begin());
                    }
                }
            }
        }
    }

    for(int i = 0; i <= dp_size; i++) {
        for(int j = 0; j <= k; j++) dp[i][j] = 0;
    }

    for(int i = 1; i <= dp_size; i++) {
        int ind = c_ind[i];
        for(int j = 1; j <= k; j++) {
            // not picking
            dp[i][j] = dp[i-1][j];
            // picking
            if(j >= w[ind]) dp[i][j] = max(dp[i-1][j - w[ind]] + val[i], dp[i][j]);
        }
    }
    
    // cout << tri << "\n";
    cout << tri - dp[dp_size][k] << "\n";
    // cout << dp_size << "\n";
    // for(int i = 1; i <= dp_size; i++) cout<< val[i] << " " ;
    // cout << "\n";
}

int main() {
    fast
    int t; cin>>t;
    while(t--) solve();
    return 0;
}