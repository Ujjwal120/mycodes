#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int maxn = 1e5+1;
vector<int> a(maxn);

// this is rn for LIS

int solve(vector<int> input, vector<int>& solution) {
    vector<int> magic;
    vector< vector<int> > history; // OPTIONAL
    for (int x: input) {
        vector<int>::iterator it = upper_bound(magic.begin(), magic.end(), x);
        // ....... change to lower_bound for LSIS
        if (it == magic.end()) {
            magic.push_back(x);
            history.push_back(vector<int>(1, x)); // OPTIONAL
        }
        else {
            *it = x;
            history[it-magic.begin()].push_back(x); // OPTIONAL
        }
    }
    
    // OPTIONAL
    int result = magic.size();
    solution.resize(result);
    solution.back() = magic.back();
    for (int i=result-2; i>=0; i--) {
        auto it = upper_bound(history[i].rbegin(), history[i].rend(), solution[i+1]);
        //........ change to lower_bound() for LSIS
        it --;
        solution[i] = *it;
    }
    
    for(int x : solution) cout << x << " ";
    cout << "\n";
    
    return magic.size();
}

int main() {
    fast
    int n; cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> ans;
    cout << solve(a, ans);
    return 0;
}