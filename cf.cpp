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
const int maxn = 1e5 + 1;

void solve() {
    int n; cin >> n;
    int a[n];
    int curmax = 0;
    for(int ind = 1; ind < n; ind++) {
        cout << "? " << curmax + 1 << " " << ind + 1 << endl;
        fflush(stdout);
        int frem; cin >> frem;
        cout << "? " << ind + 1 << " " << curmax + 1 << endl;
        fflush(stdout);
        int srem; cin >> srem;
        if(frem > srem) {
            a[curmax] = frem;
            curmax = ind;
        }
        else {
            a[ind] = srem;
        }
    }
    a[curmax] = n;
    cout << "! ";
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    fflush(stdout);
}

int main() {
    fast
    // int t; cin >> t;
    // while(t--) 
    solve();
    return 0;
}