// codechef problem

#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define input freopen("1.txt","r",stdin);
#define output freopen("output.txt","w",stdout);
#define ll long long int
#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define vi vector<int>
#define vii vector<vi>
#define vl vector<ll>
#define vll vector<vl>
#define pii pair<int, int>
#define pll pair<ll,ll>
#define mp make_pair
#define vpi vector<pii>
#define vpl vector<pll> 
using namespace std;
 
const int p=1e9+7;
const int maxn=1e5+2;
string s, t;

void solve() {
    cin>>s>>t;
    int n = s.length();
    int m = t.length();
    if(n==m) cout << t <<"\n";
    else {
        int a1[26] = {0}, a2[26] = {0};
        for(int i = 0; i< n; i++) a1[s[i] - 'a']++;
        for(int i = 0; i< m; i++) a2[t[i] - 'a']++;
    
        for( int i = 0; i < 26; i++) a1[i] -= a2[i];
        
        s = "";
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < a1[i]; j++) s += 'a' + i;
        }
        
        n = s.length();
        int ind = lower_bound(s.begin(), s.end(), t[0]) - s.begin();
    
        if(ind == 0 && t[0] != s[0]) {
            cout << t + s <<"\n";
        }
        else if(ind == n) {
            cout << s + t <<"\n";
        }
        else {
            if(s[ind] == t[0]) {
                bool after = false;
                for(int i = 1 ; i < m; i++) {
                    if(t[i] != t[0] && t[i] > t[0]) {
                        after = true; break;
                    }
                }
                if(after) {
                    ind = upper_bound(s.begin(), s.end(), t[0]) - s.begin();
                    // if(ind == n) {
                    //     cout << s + t <<"\n";
                    // }
                    // else {
                    string ans = s.substr(0,ind);
                    ans += t; ans += s.substr(ind);
                    cout << ans << "\n";
                    // }
                }
                else {
                    string ans = s.substr(0,ind);
                    ans += t; ans+= s.substr(ind);
                    cout << ans <<"\n";
                }
            }
            else {
                string ans = s.substr(0,ind);
                ans += t; ans += s.substr(ind);
                cout << ans <<"\n";
            }
        }
    }
}

int main() {
    fast 
    // input output
    int t; cin>>t; 
    while(t--) solve();
    return 0;
}
