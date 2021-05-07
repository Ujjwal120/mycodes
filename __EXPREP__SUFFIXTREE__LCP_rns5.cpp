
//  1.06 sec solution


#include <bits/stdc++.h>
using namespace std;

#define N 500050
char s[N];
int n;
int w[30];
typedef long long ll;
const int mod = 998244353;

ll expmod(ll a, ll b) {
    ll rlt = 1;
    for (a %= mod; b; a = a * a % mod, b >>= 1) if (b & 1) rlt = rlt * a % mod;
    return rlt;
}
int sa[N], rnk[N], lcp[N], cnt[N];
void build(char *s) {
    int n = strlen(s) + 1, m = 27;
    int *x = rnk, *y = lcp, *z;
    for (int i = 0; i < m; i ++) cnt[i] = 0;
    for (int i = 0; i < n; i ++) cnt[x[i]=s[i]] ++;
    for (int i = 1; i < m; i ++) cnt[i] += cnt[i-1];
    for (int i = n - 1; i >= 0; i --) sa[--cnt[x[i]]] = i;
    for (int j = 1, p = 1; p < n; j <<= 1, m = p) {
        p = 0;
        for (int i = n - j; i < n; i ++) y[p++] = i;
        for (int i = 0; i < n; i ++) if (sa[i] >= j) y[p++] = sa[i] - j;
        for (int i = 0; i < m; i ++) cnt[i] = 0;
        for (int i = 0; i < n; i ++) cnt[x[i]] ++;
        for (int i = 1; i < m; i ++) cnt[i] += cnt[i-1];
        for (int i = n - 1; i >= 0; i --) sa[--cnt[x[y[i]]]] = y[i];
        z = x, x = y, y = z;
        x[sa[0]] = 0, p = 1;
        for (int i = 1; i < n; i ++) {
            x[sa[i]] = (y[sa[i]] == y[sa[i-1]] && y[sa[i]+j] == y[sa[i-1]+j]) ? p - 1 : p ++;
        }
    }
    for (int i = 0; i < n; i ++) rnk[sa[i]] = i;
    for (int i = 0, k = 0; i < n - 1; lcp[rnk[i++]] = k) {
        if (k) k --;
        for (int j = sa[rnk[i]-1]; s[i+k] == s[j+k]; k ++);
    }
}

struct Query {
	int x; int y;
	int g;
	Query(int x = 0, int y = 0, int g = 0):x(x), y(y), g(g) {}
	bool operator < (const Query&a) const {
		return x < a.x;
	}
};

vector<Query> all;

int f[N], g[N], sz;

void update(int x, ll w) {
	for (; x <= sz; x += x & -x) f[x] ++, g[x] = (g[x] + w) % mod;
}

int query(int x, ll w) {
	w %= mod;
	int rlt = 0;
	for (; x; x -= x & -x) rlt = (rlt + w * f[x] - g[x]) % mod;
	return rlt;
}

void solve() {
	cin>>s;
	n = strlen(s);
	for (int i = 0; i < n; i ++) s[i] -= 'a' - 1;
	for (int i = 1; i <= 26; i ++) cin>>w[i];
	vector<ll> we(n+1);
	for (int i = n - 1; i >= 0; i --) we[i] = we[i+1] + w[s[i]];

	build(s);
	lcp[0] = lcp[n+1] = -1;
	vector<int> prv(n+1), nxt(n+1);
	for (int i = 1; i <= n; i++) {
		prv[i] = i - 1;
		while (lcp[prv[i]] >= lcp[i]) prv[i] = prv[prv[i]];
	}
	for (int i = n; i >= 1; i --) {
		nxt[i] = i + 1;
		while (lcp[nxt[i]] > lcp[i]) nxt[i] = nxt[nxt[i]];
	}

	vector<ll> a(n+1);
	for (int i = 0; i <= n; i ++) a[i] = we[sa[i]];

	vector<ll> presum(n+1);
	for (int i = 1; i <= n; i ++) presum[i] = (presum[i-1] + a[i]) % mod;

	int ans = 0;
	vector<ll> b = a;
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	sz = b.size();

	vector<int> id(n+1);
	for (int i = 0; i <= n; i ++) id[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;

	all.clear();
	for (int i = 1; i <= n; i ++) {
		int fl = prv[i], fr = i - 1, sl = i, sr = nxt[i] - 1;
		if (fr - fl > sr - sl) swap(fl, sl), swap(fr, sr);

		int now = 0;
		now = (now + (presum[sr] - (sl>0?presum[sl-1]:0)) * (fr - fl + 1) - (presum[fr] - (fl>0?presum[fl-1]:0)) * (sr - sl + 1)) % mod;
		ans = (ans + 1ll * now * (lcp[i] + 1)) % mod;

		for (int j = fl; j <= fr; j ++) {
			all.push_back(Query(sr, id[j], 2 * (lcp[i] + 1)));
			if (sl > 0) all.push_back(Query(sl - 1, id[j], -2 * (lcp[i] + 1)));
		}

	}

	for (int i = 0; i <= sz; i ++) f[i] = g[i] = 0;
	sort(all.begin(), all.end());

	for (int i = 0, l = 0; i <= n; i ++) {
		update(id[i], a[i]);
		int r = l;
		while (r < all.size() && all[r].x == i) r ++;
		for (int j = l; j < r; j ++) {
			ans = (ans + 1ll * all[j].g * query(all[j].y - 1, b[all[j].y-1])) % mod;
		}
		l = r;
	}
	ans = 1ll * ans * expmod(1ll * n * (n + 1) / 2, mod - 2) % mod;
	if (ans < 0) ans += mod;
	cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while (T --) solve();
}
