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
#define ss second 
#define ff first
 
using namespace std;
 
const int p = 1e9+7;
const int maxn = 1e5 + 1;
 
void solve() {
    int n; cin >> n;
    bool poss = true;
    vpi st;
    vi ans(n);
    int ind = 0;

    for(int i = 0; i < 2*n; i++) {
        char x; cin >> x;
        int rem;
        if(x == '+') {
            st.pb({-1, ind});
            ind++;
        }
        else {
            cin >> rem;
            if(st.size() == 0) {
                poss = false;
                continue;
            }
            
            int peeche = st.back().ff;
            int j = st.back().ss;
            
            st.ppb();

            ans[j] = rem;
            if(st.size() == 0) {
                if(rem < peeche) poss = false;
                continue;
            }

            if(peeche == -1) {
                st[st.size()-1].ff = max(rem, st[st.size()-1].ff);
            }
            else {
                if(rem < peeche) poss = false;
                st[st.size()-1].ff = max(rem, st[st.size()-1].ff);
            }
        }
    }

    if(poss) {
        cout << "YES\n";
        for(int i : ans) cout << i << " ";
    }
    else cout << "NO";
}
 
int main() {
    fast
    int t = 1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}