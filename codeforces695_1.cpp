#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int maxn = 3e5+10;

vector<long long> bags[3], psuedo_bags[3];

void solve() {
    int a, b, c; cin >> a >> b >> c;
    bags[0].resize(a); bags[1].resize(b); bags[2].resize(c);
    for(int i = 0; i < a; i++) cin >> bags[0][i];
    for(int i = 0; i < b; i++) cin >> bags[1][i];
    for(int i = 0; i < c; i++) cin >> bags[2][i];

    sort(bags[0].begin(), bags[0].end());
    sort(bags[1].begin(), bags[1].end());
    sort(bags[2].begin(), bags[2].end());

    long long ans = -1;

    for(int i = 0; i < 3; i++) {
        int ind3 = i;
        int ind1 = (i+1)%3, ind2 = (i+2)%3;

        psuedo_bags[0] = bags[0]; psuedo_bags[1] = bags[1]; psuedo_bags[2] = bags[2]; 

        if(psuedo_bags[ind1].size() > psuedo_bags[ind2].size()) {
            long long sum = 0;
            for(int i = psuedo_bags[ind2].size(); i < psuedo_bags[ind1].size(); i++) {
                sum += psuedo_bags[ind1][i];
            }
            psuedo_bags[ind1].resize(psuedo_bags[ind2].size());
            psuedo_bags[ind2][0] -= sum;
        }
        else if(psuedo_bags[ind1].size() < psuedo_bags[ind2].size()) {
            long long sum = 0;
            for(int i = psuedo_bags[ind1].size(); i < psuedo_bags[ind2].size(); i++) {
                sum += psuedo_bags[ind2][i];
            }
            psuedo_bags[ind2].resize(psuedo_bags[ind1].size());
            psuedo_bags[ind1][0] -= sum;
        }

        // now both index have same length
        while((psuedo_bags[ind1].size() > 0) && (psuedo_bags[ind2].size() > 0)) {
            bool s = false;
            if(psuedo_bags[ind1].back() < psuedo_bags[ind2].back()) s = true;

            if(s) swap(ind1, ind2);

            if((psuedo_bags[ind1].size() == 1) && (psuedo_bags[ind1][0] < 0)) {
                if((psuedo_bags[ind2].size() == 1) && (psuedo_bags[ind2][0] < 0)) {
                    break;
                }
                else if(psuedo_bags[ind2].size() > 0) {
                    psuedo_bags[ind1][0] -= psuedo_bags[ind2].back();
                    psuedo_bags[ind2].pop_back();
                }
            }
            else if(psuedo_bags[ind1].size() > 0) {
                psuedo_bags[ind2][0] -= psuedo_bags[ind1].back();
                psuedo_bags[ind1].pop_back();  
            }

            if((psuedo_bags[ind2].size() == 1) && (psuedo_bags[ind2][0] < 0)) {
                if((psuedo_bags[ind1].size() == 1) && (psuedo_bags[ind1][0] < 0)) {
                    break;
                }
                else if(psuedo_bags[ind1].size() > 0) {
                    psuedo_bags[ind2][0] -= psuedo_bags[ind1].back();
                    psuedo_bags[ind1].pop_back();
                }
            }
            else if(psuedo_bags[ind2].size() > 0) {
                psuedo_bags[ind1][0] -= psuedo_bags[ind2].back();
                psuedo_bags[ind2].pop_back();    
            }
        }

        long long temp_ans = 0;
        long long sum = 0;

        for(int i = 0 ; i < psuedo_bags[ind1].size(); i++) {
            sum += psuedo_bags[ind1][i];
        }

        for(int i = 0 ; i < psuedo_bags[ind2].size(); i++) {
            sum += psuedo_bags[ind2][i];
        }

        for(int i = 0; i < psuedo_bags[ind3].size(); i++) temp_ans += psuedo_bags[ind3][i];

        ans = max(ans, temp_ans-sum);
    }

    cout << ans << "\n";
}

signed main() {
    fast int t = 1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}