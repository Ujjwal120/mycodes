
// 0.83 sec sol   WHATTT !!!

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
ll expmod(ll a, ll b) {
    ll rlt = 1;
    for (a %= mod; b; a = a * a % mod, b >>= 1) if (b & 1) rlt = rlt * a % mod;
    return rlt;
}

#define N 110
int n, m, q;
int lap[N][N];
int dj[N];

int a[N][N];
int det(int n) {
	int res = 1;
    for (int i = 1; i <= n; i ++) {
        int p = 0;
        for (int j = i; j <= n; j ++) if (a[j][i]) {
			p = j;
			break;
		}
        if (p == 0) return 0;
        if (p != i) for (int j = 1; j <= n; j ++) swap(a[i][j], a[p][j]);
        int inv = expmod(a[i][i], mod-2);
        for (int j = i+1; j <= n; j ++) if (a[j][i]) {
            int coe = 1ll * a[j][i] * inv % mod;
            for (int k = i; k <= n; k ++) {
                a[j][k] -= 1ll * a[i][k] * coe % mod;
                if(a[j][k] < 0) a[j][k] += mod;
            }
        }
        res = 1ll * res * a[i][i] % mod;
    }
    return res;
}

void get_matrix(int x) {
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			if (j == i) a[i][j] = (1ll * x * lap[i][j] + n - 1 - lap[i][j]) % mod;
			else a[i][j] = (1ll * x * lap[i][j] + mod - 1 - lap[i][j]) % mod;
		}
	}
}

void multiply(vector<int> &f, int x) {
	int n = f.size() - 1;
	f.push_back(0);
	for (int j = n; j >= 0; j --) f[j+1] = f[j];
	f[0] = 0;
	for (int j = 0; j <= n; j ++) {
		f[j] = (f[j] - 1ll * x * f[j+1]) % mod;
		if (f[j] < 0) f[j] += mod;
	}
}

void divide(vector<int> &g, int x) {
	int n = g.size() - 1;
	for (int j = n - 1; j >= 0; j --) {
		g[j] = (g[j] + 1ll * g[j+1] * x) % mod;
	}
	for (int j = 0; j < n; j ++) g[j] = g[j+1];
	g.pop_back();
}

void calc_disjoint() {
    vector<int> val(n);
    for (int i = 0; i < n; i ++) {
		get_matrix(i);
		val[i] = det(n-1);
    }
    vector<int> f, g;
    f.push_back(1);
    for (int i = 0; i < n; i ++) {
        multiply(f, i);
    }
    for (int i = 0; i < n; i ++) {
        g = f;
        divide(g, i);

        int c = 1;
        for (int j = 0; j < n; j ++) {
            if (j == i) continue;
            c = 1ll * c * (i - j) % mod;
        }
        if (c < 0) c += mod;
        c = 1ll * expmod(c, mod - 2) * val[i] % mod;

        for (int j = 0; j < n; j ++) {
			dj[j] = (dj[j] + 1ll * g[j] * c) % mod;
        }
    }
}

int coe[N];
int h[N];

void calc_poly() {
	vector<int> f = {1};
	for (int i = 0; i < n - 1; i ++) multiply(f, 1);
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) coe[j] = (coe[j] + 1ll * f[j] * dj[i]) % mod;
		if (i != n - 1) {
			divide(f, 1);
			multiply(f, mod - 1);
		}
	}
	int d = expmod(2, mod - 1 - (n - 1));
	for (int i = 0; i < n; i ++) coe[i] = 1ll * coe[i] * d % mod;
	for (int i = 0; i < n; i ++) {
		h[i] = n * (n - 1) / 2 - 2 * (n - 1) + 2 * i;
		if (h[i] < 0) h[i] += mod;
	}
}

int pw[N][60];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>q;
    while (m --) {
        int u, v;
        cin>>u>>v;
        lap[u][u] ++, lap[v][v] ++;
        lap[u][v] = lap[v][u] = mod - 1;
    }
	calc_disjoint();
	calc_poly();
	for (int i = 0; i < n; i ++) {
		pw[i][0] = h[i];
		for (int j = 1; j < 60; j ++) pw[i][j] = 1ll * pw[i][j-1] * pw[i][j-1] % mod;
	}
	vector<int> tmp(n);
	while (q --) {
		ll k;
		cin>>k;
		int ans = 0;
		for (int i = 0; i < n; i ++) tmp[i] = coe[i];
		for (int j = 0; j < 60; j ++) if ((k>>j)&1) {
			for (int i = 0; i < n; i++) tmp[i] = 1ll * tmp[i] * pw[i][j] % mod;
		}
		for (int i = 0; i < n; i ++) ans = (ans + tmp[i]) % mod;
		ans = ans * expmod(n * (n - 1) / 2, mod - 1 - k % (mod - 1)) % mod;
		if (ans < 0) ans += mod;
		cout<<ans<<endl;
	}
}
