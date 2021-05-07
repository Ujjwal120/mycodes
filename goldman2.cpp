#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

const int maxn = 2e5+10;

void solve(string str) {
    
    for(int i = 1; i <= str.length()/2; i++) {
        if(str.length()%i == 0) {

            int count[26] = {0}, count1[26] = {0};
            bool adj = false;
            
            for(int j = 0; j < str.length()-i; j += i) {
                for(int k = 0; k < i; k++) {
                    count[str[j+k]%97]++;
                    count1[str[j+k+i]%97]++;
                }
      
                for(int j = 0; j < 26; j++) {
                    if(count[j] != count1[j]) {
                        adj = false;
                        break;
                    }
                    else adj = true;
                }

                if(!adj) {
                    break;
                } 

                memset(count, 0, sizeof(count));
                memset(count1, 0, sizeof(count1));
                
            }
            
            if(adj) {
                cout << i << "\n"; return;
            }
        }
  
    }

    cout << "-1\n";
}

signed main() {
    fast int t = 1;
    // cin >> t;
    string s; cin >> s;
    while(t--) cout << solve(s);
    return 0;
}