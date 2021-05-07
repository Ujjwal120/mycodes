#include<bits/stdc++.h>
using namespace std;

#define farrata ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>
#define vii vector<vi>
#define pb push_back
#define ll long long

ll dp[3001][3001];
int w[3001], val[3001], ind_c[3001], n, k, c, dp_sz;
vi sc[3001], temp;
int x , y, z;
map<int, int> cnt;
ll tri;

void solve() {
    cin >> n >> c >> k;
    for(int i = 1; i <= c; i++) sc[i].clear();

    for(int i = 0; i < n ; i++) {
        cin >> x >> y >> z;
        sc[z].pb(x);
    }

    for(int i = 1; i <= c; i++) cin >> w[i];

    tri = 0;
    dp_sz = 0;

    for(int i = 1; i <= c; i++) {
        if(! sc[i].empty()) {
            cnt.clear();
            temp.clear();
            for(int x : sc[i]) cnt[x]++;

            for(auto j = cnt.begin(); j != cnt.end(); j++) {
                temp.pb(j->second);
            }

            sort(temp.begin(), temp.end(), greater<int>());

            int sum = 0, pr = 0; 

            for(int j = 0; j < (int)temp.size(); j++) {
                for(int z = 1; z <= temp[j]; z++) {
                    ++dp_sz; 
                    ind_c[dp_sz] = i;
                    val[dp_sz] = pr;
                }
                tri += temp[j] * pr;
                pr += temp[j] * sum;
                sum += temp[j];   
            }
        }
    }

    for(int i = 0; i <= dp_sz; i++) {
        for(int j = 0; j <= k; j++) dp[i][j] = 0;
    }

    for(int i = 1; i <= dp_sz; i++) {
        int ind = ind_c[i];
        for(int j = 1; j <= k; j++) {
            dp[i][j] = dp[i-1][j];
            if(j >= w[ind]) dp[i][j] = max(dp[i][j], val[i] + dp[i-1][j-w[ind]]);
        }
    }

    cout << tri - dp[dp_sz][k] << "\n";
}

int main() {
    farrata
    int t; cin >> t;
    while(t--) solve();
    return 0;
}