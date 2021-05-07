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

inline int mul(int a,int b) { 
    ll x= (a*1ll*b);
    if(x>=p) return x%p;
    return x;
}

inline int add(int a,int b){ return (a+b>=p?a+b-p:a+b); }

inline int sub(int a, int b) {return (a-b<0?a-b+p:a-b); }

int taakat(int x,int y) { 
    ll r = 1;    
    while(y>0) { 
        if (y & 1) r = mul(r,x); 
        y = y>>1;  x = mul(x,x); 
    } 
    return r; 
}

void solve() {
    int N; cin>>N;
    int ans = 1;
    for(int i = 2; i <= N; i++) ans = mul(ans, i);
    cout << sub(ans, taakat(2, N-1));
}

int main() {
    fast 
    // input output
    int t; cin>>t; 
    while(t--) solve();
    return 0;
}