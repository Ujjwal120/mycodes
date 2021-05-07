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

const int p = 1e9 + 7;
const int maxn = 1e5 + 5;

// brute force ques

void solve() {
    ll p, f, cnts, cntw, s, w;
    cin >> p >> f >> cnts >> cntw >> s >> w;
    if(s > w) {
        swap(s, w); swap(cnts, cntw);
    } 
    ll ans = -1;
    for(int i = 0; i <= cnts; i++) {
        if(i*s > p) break;
        ll cnt = i;
        ll leftp = p - i*s;
        cnt += min(cntw, leftp / w);
        ll leftcntw = cntw - min(cntw, leftp / w);
        ll leftcnts = cnts - i;
        cnt += min(leftcnts, f / s);
        ll leftf = f - min(leftcnts, f / s)*s;
        cnt += min(leftcntw, leftf / w);
        ans = max(ans, cnt);
    }
    cout << ans << "\n";
}

int main() {
    fast
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
