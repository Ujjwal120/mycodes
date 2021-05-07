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

inline int mulmod(int a,int b) { 
    ll x= (a*1ll*b);
    if(x>=p) return x%p; return x;
}

inline int addmod(int a,int b){ return (a+b>=p?a+b-p:a+b); }

inline int submod(int a, int b) { return (a-b<0?a-b+p:a-b); }

int taakat(int x,int y) { 
    ll r = 1;    
    while(y>0) { 
        if (y & 1) r = mulmod(r,x); 
        y = y>>1;  x = mulmod(x,x); 
    } 
    return r; 
}

//sieve
const int maxn = 1e5;
bitset<maxn> bs;
vi pr;

void sieve(){
    bs.set();
    pr.push_back(2);
    for(int i = 3; i < maxn; i += 2){
        if(bs[i]) {
            pr.push_back(i);
            for(ll j = 1LL*i*i; j < maxn; j += i) bs[j]=0;
        }
    }
}

// DSU 
int parent[200001], sz[200001];

void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
}

// path compression

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

// Union by sz

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

void solve() {

}

int main() {
    fast
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
