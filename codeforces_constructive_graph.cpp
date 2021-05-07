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

const int p = 1e9 + 7;
const int maxn = 3e5 + 1;
map<int, vi> ganggang;

void solve() {
    int n; cin >> n;
    int x;
    ganggang.clear();
    for(int i = 0; i < n; i++) {
        cin >> x;
        ganggang[x].pb(i+1);
    }

    if(ganggang.size() == 1) cout << "NO\n";
    else {
        cout << "YES\n";

        for(auto i = ganggang.begin(); next(i) != ganggang.end(); i++) {
            vi vec = i->ss;
            vi vec2 = next(i)->ss;
            cout << vec[0] << " " << vec2[0] << "\n";
            if(i == ganggang.begin()) {
                for(int j = 1; j < vec.size(); j++) cout << vec[j] << " " << vec2[0] << "\n";
            }
            for(int j = 1; j < vec2.size(); j++) cout << vec2[j] << " " << vec[0] << "\n";
        }
    }
}

int main() {
    fast
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}