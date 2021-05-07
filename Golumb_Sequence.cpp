#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include <algorithm>
#include <cmath>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef int64_t ll;

struct Mod {
	ll mod = 1000000007, val = 0;
	Mod() {}
	Mod(const ll& newVal) { val = newVal % mod; if (val < 0) { val += mod; } }
	Mod(const ll& newVal, const ll& newMod) { mod = newMod; val = newVal % mod; if (val < 0) { val += mod; } }
	Mod(const Mod& other) { val = other.val; mod = other.mod; }
	Mod& operator=(const ll& newVal) { val = newVal % mod; if (val < 0) { val += mod; } return *this; }
	Mod& operator=(const Mod& other) { val = other.val; mod = other.mod; return *this; }
	Mod& operator*=(const Mod& other) { val = (val * other.val) % mod; return *this; }
	Mod& operator+=(const Mod& other) { val += other.val; if (val >= mod) { val -= mod; } return *this; }
	Mod& operator-=(const Mod& other) { val -= other.val; if (val < 0)   { val += mod; } return *this; }
	Mod& operator/=(const Mod& other) { val = (val * pow(other, mod - 2) .val) % mod; return *this; }
	Mod& operator++() { val++; if (val >= mod) { val -= mod; } return *this; }
	Mod& operator--() { val--; if (val < 0)   { val += mod; } return *this; }
	bool operator==(const Mod& other) const { return val == other.val; }
	bool operator< (const Mod& other) const { return val < other.val; }
	bool operator> (const Mod& other) const { return val > other.val; }
	bool operator!=(const Mod& other) const { return val != other.val; }
	bool operator<=(const Mod& other) const { return val <= other.val; }
	bool operator>=(const Mod& other) const { return val >= other.val; }
	explicit operator ll() const { return val; }
	explicit operator bool() const { return val?true:false; }
	friend Mod operator+(Mod lhs, const Mod& rhs) { lhs += rhs; return lhs; }
	friend Mod operator-(Mod lhs, const Mod& rhs) { lhs -= rhs; return lhs; }
	friend Mod operator*(Mod lhs, const Mod& rhs) { lhs *= rhs; return lhs; }
	friend Mod operator/(Mod lhs, const Mod& rhs) { lhs /= rhs; return lhs; }
	friend Mod operator+(const ll &lhs, const Mod &rhs) { return Mod(lhs, rhs.mod) + rhs; }
	friend Mod operator-(const ll &lhs, const Mod &rhs) { return Mod(lhs, rhs.mod) - rhs; }
	friend Mod operator*(const ll &lhs, const Mod &rhs) { return Mod(lhs, rhs.mod) * rhs; }
	friend Mod operator/(const ll &lhs, const Mod &rhs) { return Mod(lhs, rhs.mod) / rhs; }
	friend bool operator==(const ll &lhs, const Mod &rhs) { return lhs == rhs.val; }
	friend bool operator!=(const ll &lhs, const Mod &rhs) { return lhs != rhs.val; }
	friend bool operator< (const ll &lhs, const Mod &rhs) { return lhs < rhs.val; }
	friend bool operator> (const ll &lhs, const Mod &rhs) { return lhs > rhs.val; }
	friend bool operator<=(const ll &lhs, const Mod &rhs) { return lhs <= rhs.val; }
	friend bool operator>=(const ll &lhs, const Mod &rhs) { return lhs >= rhs.val; }
	friend Mod pow(Mod base, ll exp) {
		Mod ans = {1, base.mod}; do{ if (exp & 1) { ans *= base; } base *= base; } while (exp >>= 1); return ans;
	}
	friend ostream& operator<<(ostream& os, const Mod& obj) { return (os << obj.val); }
	friend istream& operator>>(istream& is, Mod& obj) { ll newVal; is >> newVal; obj = newVal; return is; }
};

vector<ll> golomb(2000000);
vector<ll> golombSum(2000000);
vector<Mod> preSum(2000000);

Mod prefixSum(ll boundary) {
	// cerr << boundary << endl;
	if (boundary == 0) return 0;
	ll value = distance(golombSum.begin(),lower_bound(golombSum.begin(), golombSum.end(),boundary));
	Mod ans = preSum[value-1];
	Mod temp = 1;
	temp *= value;
	temp *= value;
	temp *= (boundary-golombSum[value-1]);
	ans += temp;
	return ans;
}

int main() {
	int numCase;
	cin >> numCase;

	golomb[0]=0; golomb[1]=1;
	golombSum[0]=0; golombSum[1]=1;
	preSum[0] = 0; preSum[1] = 1;
	ll count = 0;
	for (int i = 2; i < 2000000; i++) {
		golomb[i] = 1+golomb[i-golomb[golomb[i-1]]];
		golombSum[i] = golombSum[i-1] + golomb[i];
		Mod temp = 1;
		temp *= golomb[i];
		temp *= i;
		temp *= i;
		preSum[i] = preSum[i-1] + temp;
		if (golombSum[i] > 10000000000ll) {
			count = i+1;
			cerr << "Found: " << i << endl;
			break;
		}
	}

	golomb.resize(count);
	golombSum.resize(count);
	preSum.resize(count);

	while (numCase--) {
		ll L,R;
		cin >> L >> R;

		cout << prefixSum(R)-prefixSum(L-1) << endl;
	}
	return 0;
}