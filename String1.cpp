// String Cyclic Shift Question

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

void solve() {
    string s; cin>>s;
    int sz = s.length();
    int alter = 0;
    int cnt[10] = {0};
    
    for(int i = 0; i < sz; i++) {
        cnt[s[i] - '0']++;
    }
    
    int alone = 0;
    for(int i = 0; i < 10; i++) alone = max(alone, cnt[i]);

    for( char c = '0'; c <= '9'; c++) {
        for( char d = '0'; d <= '9'; d++) {
            int count = 0;
            bool C = false, D = false; 
            for(int i = 0; i < sz; i++) {
                if(!C) {
                    if(s[i]==c) C = true; 
                    else continue;
                }
                else {
                    if(!D) {
                        if(s[i]==d) D = true;
                        else continue;
                    }
                }
                if(C && D) {
                    count++; C = false; D = false;
                }
            }
            alter = max(alter, count);
        }
    }
    int ans = max(alter*2, alone);
    cout<<sz - ans<<"\n";
}

int main() {
    fast 
    // input output
    int t; cin>>t; 
    while(t--) solve();
    return 0;
}