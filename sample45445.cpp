#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int maxn = 1e5 + 1;

vector<int> power;
vector<int> diff;
vector<int> similar_diff_ind;
int min_diff, ini_size;

void runit(int from_start, int from_last) {
    int cnt = 0, new_beg;
    for(int i = from_start; i < from_last; i++) {
        if(diff[i] == min_diff) {
            if(cnt == 0) new_beg = i;
            cnt++;
        }
        else {
            if(cnt > ini_size) {
                ini_size = cnt;
                similar_diff_ind.clear();
                similar_diff_ind.push_back(new_beg); 
            }
            else if(cnt == ini_size) {
                similar_diff_ind.push_back(new_beg);
            }
            cnt = 0;
        }
    }

    if(cnt > ini_size) {
        ini_size = cnt;
        similar_diff_ind.clear();
        similar_diff_ind.push_back(new_beg); 
    }
    else if(cnt == ini_size) {
        similar_diff_ind.push_back(new_beg);
    }
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    power.clear();
    diff.clear();
    similar_diff_ind.clear();
    
    int p = s.length()-1;
    int firstzero = -1;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '1') power.push_back(p);
        p--;
    }

    for(int i = 0; i < power.size(); i++) {
        cout << power[i] << " ";
    }
    cout << "\n";

    for(int i = 1; i < power.size(); i++) {
        diff.push_back(abs(power[i]-power[i-1]));
    }

    if(power.size() == 0) {

    }
    else if(power.size() == 1) {

    }
    else {
        min_diff = 1e9+7;
        if(s[0] == s[s.length()-1] && s[0] == '1') {
            diff.push_back(1);
        }

        for(int i = 0; i < diff.size(); i++) {
            cout << diff[i] << " ";
        }
        cout << "\n";    

        for(int i = 0; i < diff.size(); i++) {
            min_diff = min(min_diff, diff[i]);
        }

        cout << min_diff << "\n";

        if(min_diff == diff[0] && min_diff == diff[diff.size()-1] && s[0] == s[s.length()-1] && s[0] == '1') {
            // continuity exists
            int from_last;
            for(int i = diff.size()-1; i >= 0; i--) {
                if(diff[i] != min_diff) break;
                from_last = i;
            }

            int from_start = 0;
            for(int i = 0; i < from_last; i++) {
                if(diff[i] == min_diff) from_start++;
                else break;
            }

            ini_size = diff.size()-from_last+from_start;
            // pushed the last index first

            similar_diff_ind.push_back(from_last);
            runit(from_start, from_last);

            cout << ini_size << " : ";
            for(int i = 0; i < similar_diff_ind.size(); i++) cout << similar_diff_ind[i] << " ";
            cout << "\n";
        }
        else {
            ini_size = 0;
            runit(0, diff.size());
            cout << ini_size << " : ";
            for(int i = 0; i < similar_diff_ind.size(); i++) cout << similar_diff_ind[i] << " ";
            cout << "\n";
        }
    }
}

signed main() {
    fast int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}