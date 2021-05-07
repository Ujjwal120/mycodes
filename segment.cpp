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

const int maxn=2e5+1;
int N, Q;

void build(ll *t) {  
  for (int i = N-1 ; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(ll *t, int p, int diff) { 
    p+=N; t[p] += diff; 
    for(; p > 1; p >>= 1) t[p>>1] =t[p] + t[p^1];
}

ll query(ll *t, int l, int r) {  
  ll res = 0;
  for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
    if(l&1) res += t[l++];
    if(r&1) res += t[--r];
  }
  return res;
}

void solve() {
    cin >> N >> Q;
    int a[N];
    for(int i=0;i<N;i++) cin>>a[i];
    
    ll tree[2*N] = {0};
    for(int i=0; i<N; i++) tree[N + i] = a[i];
    build(tree);     
}

int main() {
    fast 
    // input output
    int t = 1;
    while(t--) solve();
    return 0;
}

