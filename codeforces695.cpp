#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int maxn = 3e5+10;

int h[maxn];
vector<int> ind;

void solve() {

    int n; cin >> n;
    ind.clear();
    ind.resize(n, 0);
    for(int i = 0; i < n; i++) cin >> h[i];

    int total = 0;

    if(n == 1 || n == 2) cout << 0 << "\n";
    else {
        for(int i = 1; i < n-1; i++) {
            if(h[i] > h[i-1] && h[i] > h[i+1]) {
                ind[i] = 1; total++;
            }
            if(h[i] < h[i-1] && h[i] < h[i+1]) {
                ind[i] = -1; total++;
            }
        }

        int max_tak = 0;

        for(int i = 1; i < n-1; i++) {
            if(ind[i] == 1) {
                if(ind[i-1] == -1 && ind[i+1] == -1) {
                    max_tak = 3; break;
                }
                else if(ind[i-1] == 0 && ind[i+1] == 0) max_tak = max(max_tak, 1);
                else {
                    // make it equal to left one
                    int count_nonzero_ini = 2;
                    int count_nonzero_fin = (i+2 == n) ? 0 : ((h[i-1] < h[i+1] && h[i+2] < h[i+1]) || (h[i-1] > h[i+1] && h[i+2] > h[i+1]));
                    max_tak = max(max_tak, count_nonzero_ini - count_nonzero_fin);
                    
                    // make it equal to right
                    count_nonzero_ini = 2;
                    count_nonzero_fin = (i-2 == -1) ? 0 : ((h[i+1] < h[i-1] && h[i-2] < h[i-1]) || (h[i+1] > h[i-1] && h[i-2] > h[i-1]));
                    max_tak = max(max_tak, count_nonzero_ini - count_nonzero_fin);
                }
            }
            else if(ind[i] == -1) {
                if(ind[i-1] == 1 && ind[i+1] == 1) {
                    max_tak = 3; break;
                }
                else if(ind[i-1] == 0 && ind[i+1] == 0) max_tak = max(max_tak, 1);
                else {
                    // make it equal to left one
                    int count_nonzero_ini = 2;
                    int count_nonzero_fin = (i+2 == n) ? 0 : ((h[i-1] < h[i+1] && h[i+2] < h[i+1]) || (h[i-1] > h[i+1] && h[i+2] > h[i+1]));
                    max_tak = max(max_tak, count_nonzero_ini - count_nonzero_fin);
                    
                    // make it equal to right
                    count_nonzero_ini = 2;
                    count_nonzero_fin = (i-2 == -1) ? 0 : ((h[i+1] < h[i-1] && h[i-2] < h[i-1]) || (h[i+1] > h[i-1] && h[i-2] > h[i-1]));
                    max_tak = max(max_tak, count_nonzero_ini - count_nonzero_fin);
                }
            }
        }

        cout << total - max_tak << "\n"; 
    }
}

signed main() {
    fast int t; cin >> t;
    while(t--) solve();
    return 0;
}