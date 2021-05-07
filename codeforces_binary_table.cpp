#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int maxn = 1e5+1;

vector<vector<pair<int, int>>> instruct(maxn*10);
string a[101];
bool use[101][101];

void solve() {
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == '1') use[i][j] = 1;
            else use[i][j] = 0;
        }
    }

    int cnt = 0;
    for(int i = 0; i < n-2; i++) {
        for(int j = 0; j < m; j++) {
            if(use[i][j] == 1) {
                // needs fixing
                // check immediate right if it needs fixatioon too
                if(j+1 < m) {
                    if(use[i][j+1] == 1) {
                        instruct[cnt] = {{i+1,j+1}, {i+1,j+2}, {i+2,j+2}};
                        use[i][j+1] ^= 1; use[i+1][j+1] ^= 1;
                        cnt++;
                    }
                    else {
                        instruct[cnt] = {{i+1,j+1}, {i+2,j+1}, {i+2,j+2}};
                        use[i+1][j] ^= 1; use[i+1][j+1] ^= 1;
                        cnt++;
                    }
                }
                else {
                    instruct[cnt] = {{i+1,j+1}, {i+2,j+1}, {i+2,j}};
                    use[i+1][j] ^= 1; use[i+1][j-1] ^= 1;
                    cnt++;
                }
            }
            use[i][j] = 0;
        }
    }

    for(int j = 0; j < m-2; j++) {
        if(use[n-2][j]) {
            instruct[cnt] = {{n-1,j+1}, {n,j+1}, {n-1,j+2}}; cnt++;
            use[n-2][j] ^= 1; use[n-2][j+1] ^= 1; use[n-1][j] ^= 1;
        }
        if(use[n-1][j]) {
            instruct[cnt] = {{n, j+1}, {n,j+2}, {n-1,j+2}}; cnt++;
            use[n-1][j] ^= 1; use[n-1][j+1] ^= 1; use[n-2][j+1] ^= 1;
        }
    }

    vector<pair<int, int>> one, zero;
        if(use[n-2][m-2] == 1) one.push_back({n-1, m-1});
        else zero.push_back({n-1, m-1});
        if(use[n-2][m-1] == 1) one.push_back({n-1, m});
        else zero.push_back({n-1, m});
        if(use[n-1][m-1] == 1) one.push_back({n, m});
        else zero.push_back({n, m});
        if(use[n-1][m-2] == 1) one.push_back({n, m-1});
        else zero.push_back({n, m-1});

        if(one.size() == 1) {
            instruct[cnt] = {one[0], zero[0], zero[1]}; cnt++;
            instruct[cnt] = {zero[0], one[0], zero[2]}; cnt++;
            instruct[cnt] = {zero[1], one[0], zero[2]}; cnt++;
        }
        else if(one.size() == 2) {
            instruct[cnt] = {one[0], zero[0], zero[1]}; cnt++;
            instruct[cnt] = {zero[0], zero[1], one[1]}; cnt++;
        }
        else if(one.size() == 3) {
            instruct[cnt] = {one[0], one[1], one[2]}; cnt++;
        }
        else if(one.size() == 4) {
            instruct[cnt] = {one[0], one[1], one[2]}; cnt++;
            instruct[cnt] = {one[3], one[0], one[2]}; cnt++;
            instruct[cnt] = {one[0], one[3], one[1]}; cnt++;
            instruct[cnt] = {one[3], one[1], one[2]}; cnt++;
        }

    cout << cnt << "\n";
    for(int i = 0; i < cnt; i++) {
        for(auto x : instruct[i]) cout << x.first << " " << x.second << " ";
        cout << "\n";
    }
}

signed main() {
    fast int t; cin >> t;
    while(t--) solve();
    return 0;
}