#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, max_size, min_diff;
const int maxn = 1e5+2;
vector<int> power, diff, sim_max_diff, actual_ind;

void ratchet_ass_hoe(int from_start, int from_last) {
    int cnt = 0, new_beg;
    for(int i = from_start; i < from_last; i++) {
        if(diff[i] == min_diff) {
            if(cnt == 0) new_beg = i;
            cnt++;
        }
        else {
            if(cnt > max_size) {
                max_size = cnt;
                sim_max_diff.clear();
                sim_max_diff.push_back(new_beg); 
            }
            else if(cnt == max_size) {
                sim_max_diff.push_back(new_beg);
            }
            cnt = 0;
        }
    }

    if(cnt > max_size) {
        max_size = cnt;
        sim_max_diff.clear();
        sim_max_diff.push_back(new_beg); 
    }
    else if(cnt == max_size) {
        sim_max_diff.push_back(new_beg);
    }
}

void solve() {
    cin >> n;
    string s; cin >> s;
    int p = s.length()-1;
    power.clear(); diff.clear(); sim_max_diff.clear(); actual_ind.clear();
    int pehla_pyar = -1;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '1') {
            power.push_back(p);
            if(pehla_pyar == -1) pehla_pyar = i+1;
        }
        p--;
    }
    power.push_back(-pehla_pyar);

    if(power.size() == 0 && power.size() == 1) {

    }
    else {
        min_diff = 1e9+7;
        for(int i = 1; i < power.size(); i++) {
            diff.push_back(abs(power[i]-power[i-1]));
        }

        for(int i = 0; i < diff.size(); i++) {
            min_diff = min(min_diff, diff[i]);
        }

        if(min_diff == diff[0] && min_diff == diff[diff.size()-1]) {
            int from_last, from_start = 0;
            
            for(int i = diff.size()-1; i >= 0; i--) {
                if(diff[i] != min_diff) break;
                from_last = i;
            }

            for(int i = 0; i < from_last; i++) {
                if(diff[i] == min_diff) from_start++;
                else break;
            }

            max_size = diff.size()-from_last+from_start;
            sim_max_diff.push_back(from_last);
            ratchet_ass_hoe(from_start, from_last);
        }
        else {
            max_size = 0;
            ratchet_ass_hoe(0, diff.size());
        }

        cout << diff.size() << " -> " << max_size << " : ";
        for(int i = 0; i < sim_max_diff.size(); i++) cout << sim_max_diff[i] << " ";
        cout << "\n";

        actual_ind.push_back(sim_max_diff[0]);
        int sz = diff.size(), cnt;

        for(int i = 1; i < sim_max_diff.size(); i++) {
            cnt = 0;
            int ep_ind = actual_ind.back() + max_size;
            if(ep_ind > diff.size()-1) 
                ep_ind%(diff.size()-1);

            int cur_ind = sim_max_diff[i] + max_size;
            if(cur_ind > diff.size()-1) 
                cur_ind%(diff.size()-1);
                
            bool add_krdu_kya = true;
            for(int j = ep_ind; j < sim_max_diff[i]; j++) {
                if(cur_ind+cnt == n || cur_ind+cnt == diff[i+1]) {     // makesure the condition is right
                    // cout << "1" << "\n";
                    actual_ind.clear();
                    actual_ind.push_back(sim_max_diff[i]);
                    add_krdu_kya = false;
                    break;
                }
                if(diff[j] < diff[cur_ind+cnt]) {
                    add_krdu_kya = false;
                    break;
                }
                if(diff[j] > diff[cur_ind+cnt]) {
                    // cout << "2\n";
                    add_krdu_kya = false;
                    actual_ind.clear();
                    actual_ind.push_back(sim_max_diff[i]);
                    break;
                }
                cnt++;
            }
            if(add_krdu_kya) actual_ind.push_back(sim_max_diff[i]);
        }        

        for(int x : actual_ind) cout << x << " ";
        cout << "\n";
    }
}

signed main() {
    fast int t; cin >> t;
    while(t--) solve();
    return 0;
}
