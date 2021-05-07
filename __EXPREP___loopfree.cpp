
// 1.15 sec sol

#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
#ifndef LOCAL
#define endl '\n'
#endif

#define fr(i, a, b) for(int i = a; i <= b; i++)
#define rf(i, a, b) for(int i = a; i >= b; i--)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

typedef long long ll;

void sc() {}

template <typename Head, typename... Tail>
void sc(Head &H, Tail &... T) { cin >> H; sc(T...); }

#ifdef LOCAL
#define debug(...) cerr << "[L:" << __LINE__ << "][" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

// -- Mint template (https://github.com/the-tourist/algo/blob/master/numeric/mint.cpp)

template <typename T>
T inverse(T a, T m) {
T u = 0, v = 1;
while (a != 0) {
    T t = m / a;
    m -= t * a; swap(a, m);
    u -= t * v; swap(u, v);
}
assert(m == 1);
return u;
}

template <typename T>
class Modular {
public:
using Type = typename decay<decltype(T::value)>::type;

constexpr Modular() : value() {}
template <typename U>
Modular(const U& x) {
    value = normalize(x);
}

template <typename U>
static Type normalize(const U& x) {
    Type v;
    if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
    else v = static_cast<Type>(x % mod());
    if (v < 0) v += mod();
    return v;
}

const Type& operator()() const { return value; }
template <typename U>
explicit operator U() const { return static_cast<U>(value); }
constexpr static Type mod() { return T::value; }

Modular& operator+=(const Modular& other) { if ((value += other.value) >= mod()) value -= mod(); return *this; }
Modular& operator-=(const Modular& other) { if ((value -= other.value) < 0) value += mod(); return *this; }
template <typename U> Modular& operator+=(const U& other) { return *this += Modular(other); }
template <typename U> Modular& operator-=(const U& other) { return *this -= Modular(other); }
Modular& operator++() { return *this += 1; }
Modular& operator--() { return *this -= 1; }
Modular operator++(int) { Modular result(*this); *this += 1; return result; }
Modular operator--(int) { Modular result(*this); *this -= 1; return result; }
Modular operator-() const { return Modular(-value); }

template <typename U = T>
typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {
#ifdef _WIN32
    uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
    uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
    asm(
    "divl %4; \n\t"
    : "=a" (d), "=d" (m)
    : "d" (xh), "a" (xl), "r" (mod())
    );
    value = m;
#else
    value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
#endif
    return *this;
}
template <typename U = T>
typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value, Modular>::type& operator*=(const Modular& rhs) {
    int64_t q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value / mod());
    value = normalize(value * rhs.value - q * mod());
    return *this;
}
template <typename U = T>
typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
    value = normalize(value * rhs.value);
    return *this;
}

Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }

template <typename U>
friend const Modular<U>& abs(const Modular<U>& v) { return v; }

template <typename U>
friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);

template <typename U>
friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);

template <typename U>
friend std::istream& operator>>(std::istream& stream, Modular<U>& number);

private:
Type value;
};

template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) == rhs; }

template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Modular<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Modular<T>& rhs) { return !(lhs == rhs); }

template <typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value < rhs.value; }

template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }

template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }

template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }

template <typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }

template<typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
assert(b >= 0);
Modular<T> x = a, res = 1;
U p = b;
while (p > 0) {
    if (p & 1) res *= x;
    x *= x;
    p >>= 1;
}
return res;
}

template <typename T>
bool IsZero(const Modular<T>& number) {
return number() == 0;
}

template <typename T>
string to_string(const Modular<T>& number) {
return to_string(number());
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, const Modular<T>& number) {
return stream << number();
}

template <typename T>
std::istream& operator>>(std::istream& stream, Modular<T>& number) {
typename common_type<typename Modular<T>::Type, int64_t>::type x;
stream >> x;
number.value = Modular<T>::normalize(x);
return stream;
}

/*
using ModType = int;

struct VarMod { static ModType value; };
ModType VarMod::value;
ModType& md = VarMod::value;
using Mint = Modular<VarMod>;

*/

constexpr int md = 998244353;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

Mint pwr(Mint a, ll k) {
    Mint ans = 1;
    while(k) {
        if(k & 1) ans = ans * a;
        a = a * a;
        k >>= 1;
    }
    return ans;
}

// -- SUFFIX ARRAY START

/*
    Characters should be in range (0, char_bound - 1)
    For strings, use char_bound = 256
*/

template <typename T>
vector<int> suffix_array(int n, const T &s, int char_bound) {
vector<int> a(n);
if (n == 0) {
    return a;
}
if (char_bound != -1) {
    vector<int> aux(char_bound, 0);
    for (int i = 0; i < n; i++) {
    aux[s[i]]++;
    }
    int sum = 0;
    for (int i = 0; i < char_bound; i++) {
    int add = aux[i];
    aux[i] = sum;
    sum += add;
    }
    for (int i = 0; i < n; i++) {
    a[aux[s[i]]++] = i;
    }
} else {
    iota(a.begin(), a.end(), 0);
    sort(a.begin(), a.end(), [&s](int i, int j) { return s[i] < s[j]; });
}
vector<int> sorted_by_second(n);
vector<int> ptr_group(n);
vector<int> new_group(n);
vector<int> group(n);
group[a[0]] = 0;
for (int i = 1; i < n; i++) {
    group[a[i]] = group[a[i - 1]] + (!(s[a[i]] == s[a[i - 1]]));
}
int cnt = group[a[n - 1]] + 1;
int step = 1;
while (cnt < n) {
    int at = 0;
    for (int i = n - step; i < n; i++) {
    sorted_by_second[at++] = i;
    }
    for (int i = 0; i < n; i++) {
    if (a[i] - step >= 0) {
        sorted_by_second[at++] = a[i] - step;
    }
    }
    for (int i = n - 1; i >= 0; i--) {
    ptr_group[group[a[i]]] = i;
    }
    for (int i = 0; i < n; i++) {
    int x = sorted_by_second[i];
    a[ptr_group[group[x]]++] = x;
    }
    new_group[a[0]] = 0;
    for (int i = 1; i < n; i++) {
    if (group[a[i]] != group[a[i - 1]]) {
        new_group[a[i]] = new_group[a[i - 1]] + 1;
    } else {
        int pre = (a[i - 1] + step >= n ? -1 : group[a[i - 1] + step]);
        int cur = (a[i] + step >= n ? -1 : group[a[i] + step]);
        new_group[a[i]] = new_group[a[i - 1]] + (pre != cur);
    }
    }
    swap(group, new_group);
    cnt = group[a[n - 1]] + 1;
    step <<= 1;
}
return a;
}
template <typename T>
vector<int> suffix_array(const T &s, int char_bound) {
return suffix_array((int) s.size(), s, char_bound);
}
template <typename T>
vector<int> build_lcp(int n, const T &s, const vector<int> &sa) {
assert((int) sa.size() == n);
vector<int> pos(n);
for (int i = 0; i < n; i++) {
    pos[sa[i]] = i;
}
vector<int> lcp(max(n - 1, 0));
int k = 0;
for (int i = 0; i < n; i++) {
    k = max(k - 1, 0);
    if (pos[i] == n - 1) {
    k = 0;
    } else {
    int j = sa[pos[i] + 1];
    while (i + k < n && j + k < n && s[i + k] == s[j + k]) {
        k++;
    }
    lcp[pos[i]] = k;
    }
}
return lcp;
}
template <typename T>
vector<int> build_lcp(const T &s, const vector<int> &sa) {
return build_lcp((int) s.size(), s, sa);
}

template<typename T, size_t N>
struct SuffixArray {
    vector<int> sa, lcp;
    int n;
    void init(int nn, const T &s, int char_bound) {
        assert(N >= sz(s));
        n = nn;
        sa = suffix_array(s, char_bound);
        lcp = build_lcp(s, sa);
    }
};

// -- SUFFIX ARRAY END

// -- SPARSE SEGTREE START 

const int NN = 4e7 + 5;
struct node {
    int l, r;
    pair<Mint, Mint> val;
} tr[NN];
int tot = 0;

const int N = 5e5 + 5;
int version[N];
SuffixArray<string, N> S;

Mint pre[N], w[N];
int n;

pair<Mint, Mint> query(int nd,int s,int e,int l,int r) { // sum query in segtree
    if(s > r || e < l || !nd) return {0, 0};
    else if(l <= s && e <= r) {
        return tr[nd].val;
    }
    int m = (s + e) >> 1;
    auto p1 = query(tr[nd].l, s, m, l, r);
    auto p2 = query(tr[nd].r, m + 1, e, l, r);
    return {p1.fi + p2.fi, p1.se + p2.se};
}

void merge(int &nd1,int nd2) { // merge two segtrees
    if(!nd1 || !nd2) {
        nd1 |= nd2;
        return;
    }
    tr[nd1].val.fi += tr[nd2].val.fi;
    tr[nd1].val.se += tr[nd2].val.se;
    merge(tr[nd1].l, tr[nd2].l);
    merge(tr[nd1].r, tr[nd2].r);
}

void upd(int &nd,int s,int e,int idx) { // for initializing segtrees
    if(!nd) nd = ++tot;
    tr[nd].val = {1, pre[idx - 1]};
    if(s == e) return;
    int m = (s + e) >> 1;
    if(idx <= m)
        upd(tr[nd].l, s, m, idx);
    else
        upd(tr[nd].r, m + 1, e, idx);
}

// -- SPARSE SEGTREE END

// -- DSU START

int dsu[N];
Mint cur = 0;
vector<int> pos[N]; // maintains the indexes of the suffix array in each component

int root(int u) {
    return ((u == dsu[u]) ? u : dsu[u] = root(dsu[u]));
}

void uni(int u,int v) { // for merging two components
    u = root(u), v = root(v);
    if(sz(pos[u]) > sz(pos[v])) swap(u, v);
    dsu[u] = v;
    for(int i : pos[u]) {
        auto p1 = query(version[v], 1, n, i + 1, n);
        cur += p1.se - p1.fi * pre[i - 1];
        auto p2 = tr[version[v]].val;
        p2.fi -= p1.fi;
        p2.se -= p1.se;
        cur += p2.fi * pre[i - 1] - p2.se;
        pos[v].pb(i);
    }
    pos[u].clear();
    merge(version[v], version[u]); // merge the second segtree into the first
}

// -- DSU END

void solve() {
    cur = 0;
    while(tot > 0) {
        tr[tot].l = tr[tot].r = 0;
        tr[tot].val = {0, 0};
        tot--;
    }
    string s;
    sc(s);
    n = sz(s);
    S.init(sz(s), s, 256);
    fr(i, 0, 25) sc(w[i]);
    fr(i, 1, n) pre[i] = pre[i - 1] + w[s[i - 1] - 'a'];
    fr(i, 1, n) {
        dsu[i] = i;
        pos[i] = {S.sa[i - 1] + 1};
        version[i] = 0;
        upd(version[i], 1, n, S.sa[i - 1] + 1);
    }
    vector<pair<int,int>> v;
    fr(i, 0, sz(S.lcp) - 1) v.eb(S.lcp[i], i + 1);
    sort(all(v));
    reverse(all(v));
    int pt = 0;
    Mint ans = 0;
    rf(l, n, 1) {
        while(pt < sz(v) && v[pt].fi == l) {
            uni(v[pt].se, v[pt].se + 1);
            pt++;
        }
        ans += cur;
    }
    Mint sum = 0;
    fr(i, 1, n) { // for handling |R| = |T|
        ans += pre[i] * i - sum;
        sum += pre[i];
    }
    ans = ((ans * 2) / (n * 1LL * (n + 1)));
    cout << ans << endl;
}

int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for(int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}