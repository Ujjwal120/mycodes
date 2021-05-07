#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

const int maxn = 2e5+10;

void printResult(int n, vector<vector<int>> arr, int t) {
    vector<pair<int, int>> p(n);
    vector<int> con(n);

    vector<int> req = arr[n];

    for(int i = 0; i < n; i++) {
        p[i].first = i;
        for(int j = 0; j < n; j++) {
            if(arr[i][j] == 1) {
                p[i].second++;
                con[i]++;
            }
        }
    }

    sort(p.begin(), p.end(), [&](pair<int, int> a, pair<int, int> b) {
        if(a.second > b.second) return true;
        if(a.second < b.second) return false;
        // go in a.first and b.first
        vector<int> A, B;
        for(int i = 0; i < n; i++) {
            if(arr[a.first][i] == 1) A.push_back(con[i]);
        }
        for(int i = 0; i < n; i++) {
            if(arr[b.first][i] == 1) B.push_back(con[i]);
        }

        sort(A.begin(), A.end(), greater<int>());
        sort(B.begin(), B.end(), greater<int>());

        bool equal = true;
        for(int i = 0; i < A.size(); i++) {
            if(A[i] > B[i]) return true;
            if(A[i] < B[i]) return false;
        }
        return (a.first < b.first);
    });


    for(int i = 0; i < n; i++) {
        int node = p[i].first;
        if(t >= req[node]) {
            cout << node << " ";
            t -= req[node];
        }
    }
    cout << "\n";
}

signed main() {
    fast int T = 1;
    // cin >> t;
    int t, n;
    cin >> n >> t;

    vector<vector<int>> arr(n+1, vector<int>(n));

    for(int i = 0; i < n+1; i++) {
        for(int j = 0; j < n; j++) cin >> arr[i][j];
    }

    while(T--) printResult(n, arr, t);
    return 0;
}