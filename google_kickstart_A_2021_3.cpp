#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 

using namespace std;

int cs = 0;
// priority_queue<pair<int, pair<int, int>>> pq; 
int mat[1000][1000], ideal[1000][1000];
bool touched[1000][1000];
map<int, vector<pair<int, int>>> mp;
vector<pair<int, int>> max_h;
vector<pair<int, int>> temp;

void solve() {
    int r, c;
    cin >> r >> c;

    mp.clear();
    int m = -1;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> mat[i][j];
            m = max(m, mat[i][j]);
            touched[i][j] = false;
            ideal[i][j] = 0;
            mp[mat[i][j]].push_back({i, j});
        } 
    }

    max_h.clear();
    temp.clear();

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(mat[i][j] == m) {
                max_h.push_back({i, j});
                touched[i][j] = true;
            }
        } 
    }

    while(!max_h.empty()) {
        temp.clear();
        for(auto x : max_h) {
            int i = x.first, j = x.second;
            ideal[i][j] = m;
            if(i-1 >= 0 && !touched[i-1][j]) {
                touched[i-1][j] = true;
                temp.push_back({i-1, j});
            }
            if(i+1 < r && !touched[i+1][j]) {
                touched[i+1][j] = true;
                temp.push_back({i+1, j});
            }

            if(j-1 >= 0 && !touched[i][j-1]) {
                touched[i][j-1] = true;
                temp.push_back({i, j-1});
            }
            if(j+1 < c && !touched[i][j+1]) {
                touched[i][j+1] = true;
                temp.push_back({i, j+1});
            }
        }

        for(auto x : mp[m-1]) {
            if(!touched[x.first][x.second]) {
                temp.push_back(x);
                touched[x.first][x.second] = true;
            }
        }

        max_h = temp;
        m--;
    }


    ll ans = 0;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            ans += ideal[i][j] - mat[i][j];
        }
    }


    cout << "Case #" << ++cs << ": " << ans << "\n"; 
}

signed main() {
    fast int t;
    cin >> t;
    while(t--) solve();
    return 0;
}