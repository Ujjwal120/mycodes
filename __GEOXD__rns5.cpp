
// 1.87 second sec


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int X1, X2, Y1, Y2, a, b, c;
ll d;

const ll inf = 1e18;
const int mod = 1e9 + 7;

ll gcd(ll a, ll b, ll &x, ll &y) {
    if (!b) {
        x = 1, y = 0; return a;
    }
    ll rlt = gcd(b, a % b, y, x);
    y -= a / b * x;
    return rlt;
}

ll presolve(ll A, ll B, ll C) {
    if (C < 0) return 0;
    if (A > B) swap(A, B);
    if (!A) {
		assert(0);
		return inf;
    }
    ll p = C / B;
    ll k = B / A;
    ll d = (C - p * B) / A;
    return presolve(B - k * A, A, C - A * (k * p + d + 1)) + (p + 1) * (d + 1) + k * p * (p + 1) / 2;
}

ll calc(ll x, ll y, ll a, ll b) {
    if (x >= b || y >= b) {
		ll rx = x / b, ry = y / b;
		return (rx * (y + 1) + ry * (x + 1) - b * rx * ry + calc(x % b, y % b, a, b)) % mod;
    }
	if (a * x <= y) return x + 1;
	ll rlt = presolve(a, b, a * x) - presolve(a, b, a * x - y - 1);
	rlt %= mod;
	if (rlt < 0) rlt += mod;
	return rlt;
}

void solve() {
	cin>>X1>>X2>>Y1>>Y2>>a>>b>>c>>d;
	X2 -= X1, Y2 -= Y1;
	if (X2 < 0 || Y2 < 0) {
		cout<<0<<endl;
		return;
	}
	d = (d - 1ll * a * X1 - 1ll * b * Y1) % c;
	int dbc = __gcd(b, c);
	if (dbc > 1) {
		ll x, y;
        ll dall = gcd(a, dbc, x, y);
		if (d % dall != 0) {
			cout<<0<<endl;
			return;
		}
		d /= dall, a /= dall, b /= dall, c /= dall, dbc /= dall;
		x = x * d % dbc;
		if (x < 0) x += dbc;
		if (X2 < x) {
			cout<<0<<endl;
			return;
		}
        X2 -= x, d = (d - 1ll * a * x) % c;
        assert(d % dbc == 0);
        b /= dbc, d /= dbc, c /= dbc, X2 /= dbc;
	}
	int dac = __gcd(a, c);
	if (dac > 1) {
		ll x, y;
		assert(gcd(b, dac, x, y) == 1);
		x = x * d % dac; if (x < 0) x += dac;
		if (Y2 < x) {
			cout<<0<<endl;
			return;
		}
		Y2 -= x, d = (d - 1ll * b * x) % c;
		assert(d % dac == 0);
		a /= dac, d /= dac, c /= dac, Y2 /= dac;
	}
	ll x, y;
    assert(gcd(b, c, x, y) == 1);
	a = 1ll * a * x % c, d = 1ll * d * x % c;
	if (a < 0) a += c;
	if (d < 0) d += c;
	ll p = Y2 / c * c + c;
	ll rlt = calc(X2, d + p, a, c) - calc(X2, d + p - Y2 - 1, a, c);
	rlt = (rlt % mod + mod) % mod;
	cout<<rlt<<endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T;
	cin>>T;
	while (T --) solve();
}
