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
#define pll pair<ll,ll>
#define mp make_pair
#define vpl vector<pll> 
using namespace std;
 
const int pr = 1e9 + 7;
const int maxn = 1e6 + 1;

inline int mul(int a,int b, int p) { 
    ll x= (a*1ll*b);
    if(x>=p) return x%p;
    return x;
}

inline int add(int a,int b, int p) { return (a+b >= p ? a+b-p : a+b); }

int n, k, w, a1, b1, c1, d1, a2, b2, c2, d2;
int L[maxn], H[maxn], P[maxn], EP[maxn], tree[2*maxn];

void build() {  
  for (int i = n-1 ; i > 0; --i) tree[i] = max(tree[i<<1], tree[i<<1|1]);
}

int query(int l, int r) {  
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if(l&1) res = max(res, tree[l++]);
    if(r&1) res = max(res, tree[--r]);
  }
  return res;
}

int main() {
    fast 
    // input output
    int t, c=1;
    for(cin >> t; t--;) {
        cin >> n >> k >> w;
        for(int i = 0; i < k; i++) cin >> L[i];
        cin >> a1 >> b1 >> c1 >> d1; 
        for(int i = 0; i < k; i++) cin >> H[i];
        cin >> a2 >> b2 >> c2 >> d2;

        // rest of sides calculation

        for(int i = k; i < n; i++) {
            L[i] = add(mul(a1%d1, L[i-2], d1), add(mul(b1%d1, L[i-1], d1), c1%d1, d1), d1) + 1;
            H[i] = add(mul(a2%d2, H[i-2], d2), add(mul(b2%d2, H[i-1], d2), c2%d2, d2), d2) + 1;
        }

        for(int i = 0; i < n; i++) tree[n + i] = H[i];
        build();

        P[0] = mul(H[0] + w, 2, pr);
        int ans = P[0];
        EP[0] = L[0] + w;

        for(int i = 1; i < n; i++) {
            int ind = lower_bound(EP, EP + i, L[i]) - EP;
            if(ind == i) {
                int extra = mul(H[i] + w, 2, pr);
                P[i] = add(P[i-1], extra, pr);
                ans = mul(ans, P[i], pr);
                EP[i] = L[i] + w;
            }
            else {
                int extra = mul(L[i]+w - EP[i-1], 2, pr);
                int maxh = query(ind, i);
                if(H[i] > maxh) extra = add(mul(H[i] - maxh, 2, pr), extra, pr);     
                P[i] = add(extra, P[i-1], pr);
                ans = mul(ans, P[i], pr);
                EP[i] = L[i] + w;
            }
        }

        cout << "Case #" << c++ << ": " << ans << "\n";
    }
    return 0;
}