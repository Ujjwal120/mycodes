#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define input freopen("output1.txt","r",stdin);
#define output freopen("output.txt","w",stdout);
#define int long long 

using namespace std;

int arr[103], cs = 1;
vector<vector<int>> adj;

int changeit(int i) {
    int prev = adj[i-1].size();
    int now = adj[i].size();

    if(now > prev) return 0;

    if(now == prev) {
        for(int j = 0; j < prev; j++) {
            if(adj[i][j] > adj[i-1][j]) return 0;
            if(adj[i][j] < adj[i-1][j]) break;
        }
    }

    if(prev == now) {
        adj[i].push_back(0);
        return 1;
    }

    for(int j = 0; j < adj[i].size(); j++) {
        if(adj[i][j] > adj[i-1][j]) {
            for(int k = 0; k < prev-now; k++) {
                adj[i].push_back(0);
            }
            return prev - now;
        }
        if(adj[i][j] < adj[i-1][j]) {
            for(int k = 0; k < prev-now+1; k++) {
                adj[i].push_back(0);
            }
            return prev-now+1;
        }
    }


    int ind = -1;

    for(int j = adj[i].size(); j < adj[i-1].size(); j++) {
        if(adj[i-1][j] != 9) {
            ind = j;
        }
    }

    if(ind == -1) {
        for(int j = 0; j < prev-now+1; j++) {
            adj[i].push_back(0);
        }
        return prev-now+1;
    }
    else {
        for(int j = adj[i].size(); j < adj[i-1].size(); j++) {
            if(j == ind) {
                adj[i].push_back(adj[i-1][j]+1);
            }
            else if(j > ind) {
                adj[i].push_back(0);
            }
            else {
                adj[i].push_back(adj[i-1][j]);
            }
        }
        return prev-now;
    }
}

void convert (vector<int> &x, int n) {
    while(n) {
        x.push_back(n%10);
        n /= 10;
    }
    reverse(x.begin(), x.end());
}

void solve() {
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    adj.resize(n, vector<int>());

    for(int i = 0; i < n; i++) {
        adj[i].clear();
        convert(adj[i], arr[i]);
    }

    int sum = 0;
    for(int i = 1; i < n; i++) {
        // this i will either change or remain same
        sum += changeit(i);
    }


    cout << "Case #" << cs++ << ": " << sum << "\n";
}

signed main() {
    fast int t;
    // input
    // output
    cin >> t;
    while(t--) solve();
    return 0;
}