#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int maxn = 1e5+10;
int n, q, a[maxn];

vector<vector<int>> bit_struct;

vector<pair<int, int>> LR;

vector<vector<int>> DP;

vector<int> BIT(int x) {
    vector<int> s;
    while(x) {
        s.push_back(x&1);
        x >>= 1;
    }
    
    while(s.size()<31) {
        s.push_back(0);
    }
    // reverse(s.begin(), s.end());
    return s;
}

void solve() {
    cin >> n >> q;
    LR.resize(q);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < q; i++) {
        cin >> LR[i].first >> LR[i].second;
    }

    for(int i = 0; i < n; i++) {
        bit_struct.push_back(BIT(a[i]));
    }

    DP.resize(n, vector<int>(bit_struct[0].size(), 0));

    DP[0] = bit_struct[0];

    for(int i = 1; i < n; i++) { 
        for(int j = 0; j < bit_struct.size(); j++) {
            DP[i][j] = DP[i-1][j] + bit_struct[i][j];
        }
    }

    vector<int> calc;
    for(int i = 0; i < q; i++) {
        calc.clear();
        if(LR[i].first == 0) {
            calc = DP[LR[i].second];
        }
        else {
            for(int j = 0; j < DP[i].size(); j++) {
                calc.push_back(DP[LR[i].second][j] - DP[LR[i].first-1][j]);
            }
        }

        // for(int x : calc) cout << x << " ";
        // cout << " -> ";

        int pro = 1, ans = -1; bool found = false;
        for(int j = 0; j < calc.size(); j++, pro *= 2) {
            if(calc[j] < 2) {
                if((ans == -1)) ans = pro*(2 - calc[j]);
            }
            else {
                found = true;
                break;
            }
        }

        if(found) cout << 0 << " ";
        else cout << ans << " ";
        // cout << "\n";
    }
}

signed main() {
    fast
    int t = 1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}