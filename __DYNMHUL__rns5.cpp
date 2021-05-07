
// Challenge Problem DYNAMIC HULL


#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef pair<int, int> pii;
#define sq(x) ((x)*(x))

static uint64_t splitmix64() {
    static uint64_t seed = 0x3afdf3;
    seed += 0x9e3779b97f4a7c15;
    seed = (seed ^ (seed >> 30)) * 0xbf58476d1ce4e5b9;
    seed = (seed ^ (seed >> 27)) * 0x94d049bb133111eb;
    return seed ^ (seed >> 31);
}

int RAND(int l, int r) {
    assert(l <= r);
    return rand() % (r - l + 1) + l;
}

struct Timer {
	time_t st;
	Timer() {st = clock();}
	double get_time() {return 1.0 * (clock() - st) / CLOCKS_PER_SEC;}
} cl;

double TIME_LIMIT = 4.9;

const int inf = 0x3f3f3f3f;
template<class T> void chkmax(T &a, T b) {
    if (a < b) a = b;
}
template<class T> bool chkmin(T &a, T b) {
    if (b < a) {
		a = b;
		return true;
    }
    return false;
}

struct Point {
    int x, y;
    Point(int _x = 0, int _y = 0);
    void input();
    void output();
    bool operator == (const Point &a) const;
    bool operator != (const Point &a) const;
    bool operator < (const Point &a) const;
    Point operator * (const int &b) const;
    Point operator + (const Point &a) const;
    Point operator - (const Point &a) const;
    int operator & (const Point &a) const;
    int operator ^ (const Point &a) const;
    int GCD();
    Point smallest();
};

typedef vector<Point> Polygon;

Point::Point(int _x, int _y) {
    x = _x, y = _y;
}

void Point::input() {
    cin>>x>>y;
}

void Point::output() {
    cout<<x<<'\t'<<y<<endl;
}

bool Point::operator == (const Point &a) const {
    return x == a.x && y == a.y;
}

bool Point::operator != (const Point &a) const {
    return !(*this == a);
}

bool Point::operator < (const Point &a) const {
    return x != a.x?x<a.x:y<a.y;
}

Point Point::operator * (const int &b) const {
    return Point(x * b, y * b);
}

Point Point::operator + (const Point &a) const {
    return Point(x + a.x, y + a.y);
}

Point Point::operator - (const Point &a) const {
    return Point(x - a.x, y - a.y);
}

int Point::operator & (const Point &a) const {
    return x * a.x + y * a.y;
}

int Point::operator ^ (const Point &a) const {
    return x * a.y - a.x * y;
}

int Point::GCD() {
    return __gcd(abs(x), abs(y));
}

Point Point::smallest() {
    int d = GCD();
    assert(d);
    return Point(x / d, y / d);
}

int dist(Point p) {return p&p;}

int cross(const Point &a, const Point &b, const Point &c) {
    return (b - a) ^ (c - a);
}

Polygon Points_on_seg(const Point &a, const Point &b) {
    Polygon rlt;
    if (a == b) rlt.push_back(a);
    else {
        Point c = (b - a).smallest();
        Point now = a;
        while (1) {
            rlt.push_back(now);
            if (now == b) break;
            now = now + c;
        }
    }
    return rlt;
}

void convexhull(Polygon &p) {
    sort(p.begin(), p.end());
    int n = p.size();
    Polygon rlt;
    rlt.reserve(n);
    for (int i = 0, j = 0; i < n; i ++) {
        while (j > 1 && cross(rlt[j-2], rlt[j-1], p[i]) <= 0) rlt.pop_back(), j --;
        rlt.push_back(p[i]), j ++;
    }
    int m = rlt.size();
    for (int i = n - 2, j = m; i >= 0; i --) {
        while (j > m && cross(rlt[j-2], rlt[j-1], p[i]) <= 0) rlt.pop_back(), j --;
        rlt.push_back(p[i]), j ++;
    }
    if (n > 1) rlt.pop_back();
    p = rlt;
}

int area(const Polygon &P) {
    int ans = 0;
    for (int i = 2; i < P.size(); i ++) {
        ans += cross(P[0], P[i-1], P[i]);
    }
    assert(ans >= 0);
    return ans;
}

Polygon generate(int type) {
    if (type == 1) {
        Polygon rlt;
        int runs = 1024;
        while (runs --) rlt.emplace_back(RAND(1, 512), RAND(1, 512));
        return rlt;
    }
    else {
        set<Point> rlt;
        Polygon border;
        for (int x = 0; x <= 512; x ++) {
            border.emplace_back(x, 0);
            border.emplace_back(x, 512);
        }
        for (int y = 1; y < 512; y ++) {
            border.emplace_back(0, y);
            border.emplace_back(512, y);
        }
        while (rlt.size() < 1024) {
            Point P, Q;
            if (type == 3) {
                P = Point(RAND(0, 512), RAND(0, 512));
                Q = Point(RAND(0, 512), RAND(0, 512));
            }
            else if (type == 2) {
                P = border[RAND(0, border.size()-1)];
                Q = border[RAND(0, border.size()-1)];
            }
            else if (type == 4) {
                P = Point(256, 256);
                Q = border[RAND(0, border.size()-1)];
            }
            else {
                cerr<<"Invalid type."<<endl;
                assert(0);
            }
            if (Q < P) swap(P, Q);
            Polygon add = Points_on_seg(P, Q);
            for (auto &p:add) {
                rlt.insert(p);
                if (rlt.size() >= 1024) break;
            }
        }
        Polygon vec;
        for (auto &p:rlt) vec.push_back(p);
        return vec;
    }
}

int N, M;
Polygon location;

int check(vector<int> ids) {
    if (ids.size() != N) {
        puts("No permutation.");
        assert(0);
    }
    reverse(ids.begin(), ids.end());

    vector<bool> vis(N);
    Polygon cnv;
    int sum = 0;

    int tot = 0;

    for (int i:ids) {
		tot ++;
        if (vis[i]) {
            puts("No permutation.");
            assert(0);
        }
        if (tot == N) break;
        vis[i] = 1;
        cnv.push_back(location[i]);
        convexhull(cnv);
        sum += area(cnv);
        if (cnv.size() > 2) {
			bool ok = false;
			for (auto p:cnv) {
				if (p == location[i]) {
					ok = true;
					break;
				}
			}
			assert(ok);
        }
    }
    return sum;
}

void input() {
    cin>>N;
    location.resize(N);
    for (auto &p:location) p.input();
    cin>>M;
}

struct Data {
	int mx, fi;
	Point step;
	double distance;
	Data(int mx = 0, int fi = 0, Point step = Point(0, 0)):mx(mx), fi(fi), step(step) {}
	bool operator < (const Data &a) {
		if (mx != a.mx) return mx > a.mx;
		return distance < a.distance;
	}
};

vector<Data> all;

vector<int> best_ans;
int best_score;

bool update(vector<int> &ans, int score) {
	if (score < best_score) {
		best_score = score;
		best_ans = ans;
		return true;
	}
	return false;
}

struct LIST {
	vector<int> prv, nxt;
	int front, back;
	vector<bool> exist;
	LIST() {}
	LIST (vector<int> &v) {
		int n = v.size();
		prv.resize(n+2), nxt.resize(n+2);
		front = n, back = n + 1;
		nxt[front] = v[0], prv[v[0]] = front;
		for (int i = 0; i + 1 < v.size(); i ++) nxt[v[i]] = v[i+1], prv[v[i+1]] = v[i];
		nxt[v.back()] = back, prv[back] = v.back();
		exist.assign(n+2, true);
	}
	void pop(int x) {
        assert(exist[x]);
        exist[x] = false;
        int le = prv[x], ri = nxt[x];
        nxt[le] = ri, prv[ri] = le;
	}
	vector<int> get_vector() {
		vector<int> rlt;
		int i = nxt[front];
        while (i != back) {
			rlt.push_back(i);
			i = nxt[i];
        }
        return rlt;
	}
};

void reverse_solve(double delta = 0.5, int maxjump = 30) {
    vector<int> id(N);
    for (int i = 0; i < N; i ++) id[i] = i;
    sort(id.begin(), id.end(), [&](int i, int j) {return location[i] < location[j];});
    auto positive = [&](Point p) {
    	return p.x > 0 || (p.x == 0 && p.y > 0);
    };
    for (int i:id) {
		int cnt = 0;
		map<Point, int> dup;
		bool bad = false;
        for (int j:id) {
			if (location[j] == location[i]) {
				cnt ++;
				if (j > i) {
					bad = true;
					break;
				}
			}
			else {
				Point P = (location[j]-location[i]).smallest();
				dup[P] ++;
			}
        }
        if (bad) continue;
        assert(!dup.empty());
        int cur = -1;
        Point step;
        for (auto &p:dup) if (positive(p.first)) {
			if (!dup.count(Point()-p.first) && cnt + p.second > 3) all.push_back(Data(cnt+p.second, i, p.first));
        }
    }
    for (auto &d:all) {
		d.mx = 0;
		for (int i = 0; i < N; i ++) if (abs(cross(location[d.fi], location[i], location[d.fi]+d.step))/sqrt(dist(d.step)) < delta) d.mx ++;
		d.distance = abs(cross(Point(256, 256), location[d.fi], location[d.fi] + d.step)) / sqrt(dist(d.step));
    }
    sort(all.begin(), all.end());
    if (all.size() > 15) all.resize(15);

	for (auto &d:all) {

		vector<int> ans;
		Polygon cnv;
		for (int i = 0; i < N; i ++) {
			if (location[i] == location[d.fi]) ans.push_back(i), cnv.push_back(location[i]);
			else if ((location[i] - location[d.fi]).smallest() == d.step) ans.push_back(i), cnv.push_back(location[i]);
		}
		convexhull(cnv);
		assert(cnv.size() == 2);
		vector<int> dis(N);
		vector<int> id(N);
		for (int i = 0; i < N; i ++) dis[i] = cross(cnv[0], location[i], cnv[1]), id[i] = i;
		sort(id.begin(), id.end(), [&](int i, int j) {return dis[i] < dis[j];});
		vector<int> rank(N);
		for (int i = 0; i < N; i ++) rank[id[i]] = i;

		int left, right;
		for (int i = 0; i < N; i++) {
			if (dis[id[i]] >= 0) {
				left = id[i];
				break;
			}
		}

		for (int i = N - 1; i >= 0; i --) {
			if (dis[id[i]] <= 0) {
				right = id[i];
				break;
			}
		}

		LIST ord(id);

		int sum = 0;
		int up = rank[right], dn = rank[left];
		int D = maxjump;
		while (ans.size() < N) {
			int mn = inf, best = -1;
			{
				int i = ord.nxt[right];
				int hu = dis[id[min(N-1,up + D)]];
				while (i != ord.back && dis[i] <= hu) {
					Polygon upd = cnv;
					upd.push_back(location[i]);
					convexhull(upd);
					int ar = area(upd);
					if (mn > ar) {
						mn = ar, best = i;
					}
					i = ord.nxt[i];
				}
			}
			{
				int i = ord.prv[left];
				int hd = dis[id[max(0,dn - D)]];
				while (i != ord.front && dis[i] >= hd) {
					Polygon upd = cnv;
					upd.push_back(location[i]);
					convexhull(upd);
					int ar = area(upd);
					if (mn > ar) {
						mn = ar, best = i;
					}
					i = ord.prv[i];
				}
			}
			assert(best >= 0);
			ans.push_back(best);
			ord.pop(best);
			if (dis[best] > 0) up = max(up, rank[best]);
			else dn = min(dn, rank[best]);
			cnv.push_back(location[best]);
			convexhull(cnv);
			if (ans.size() < N) sum += mn;
		}
		reverse(ans.begin(), ans.end());
		update(ans, sum);
	}
}

namespace greedy{
struct LIST {
	vector<int> prv, nxt;
	int front, back;
	vector<bool> exist;
	int size;
	LIST() {}
	LIST (int n) {
		prv.resize(n+2), nxt.resize(n+2);
		exist.resize(n+2);
		front = n, back = n + 1;
		nxt[front] = back, prv[back] = front;
		exist[front] = exist[back] = true;
		size = 0;
	}
	void pop(int x) {
        assert(exist[x]);
        exist[x] = false;
        size --;
        int le = prv[x], ri = nxt[x];
        nxt[le] = ri, prv[ri] = le;
	}
	void push(int x, int y) {
		assert(exist[x] && x != back && !exist[y]);
		exist[y] = true;
		size ++;
		int z = nxt[x];
		nxt[x] = y, nxt[y] = z;
		prv[z] = y, prv[y] = x;
	}
	int previous(int x) {
		assert(x != front);
		return prv[x];
	}
	int nextto(int x) {
		assert(x != back);
		return nxt[x];
	}
	vector<int> get_vector() {
		vector<int> rlt;
		int i = nxt[front];
        while (i != back) {
			rlt.push_back(i);
			i = nxt[i];
        }
        return rlt;
	}
};

LIST get_sorted_ids(Polygon &pts) {
	int n = pts.size();
	vector<int> sorted_id(n);
	for (int i = 0; i < n; i ++) sorted_id[i] = i;
	sort(sorted_id.begin(), sorted_id.end(), [&](int i, int j) {return pts[i] < pts[j];});
	LIST sorted(n);
    for (int i = 0, cur = sorted.front; i < n; cur = sorted_id[i++]) {
		sorted.push(cur, sorted_id[i]);
    }
    return sorted;
}

int under(const Point &a, const Point &b) {
    return (b.x - a.x) * (b.y + a.y);
}

struct fast_convex {
    Polygon all;
    LIST ids, sorted;
    int area;
    vector<bool> exist;
	fast_convex() {}
	void pop(int x) {
		assert(ids.exist[x]);
        int le = ids.previous(x), ri = ids.nextto(x);
        if (le != ids.front) area += under(all[x], all[le]);
        if (ri != ids.back) area += under(all[ri], all[x]);
        if (le != ids.front && ri != ids.back) area += under(all[le], all[ri]);
        ids.pop(x);
	}
	void push(int x, int y) {
		int z = ids.nextto(x);
		if (x != ids.front && z != ids.back) area += under(all[z], all[x]);
		if (x != ids.front) area += under(all[x], all[y]);
		if (z != ids.back) area += under(all[y], all[z]);
		ids.push(x, y);
	}
	void Remove_from_convex(int x) {
		pop(x);
        int le = ids.previous(x), ri = ids.nextto(x);
		while (1) {
			le = sorted.nextto(le);
			if (le == ri) break;
			if (!exist[le]) continue;
			Add_to_convex(le);
		}
	}
	void Add_to_convex(int x) {
		int l = x;
		while (l != sorted.front && ids.exist[l] == false) l = sorted.previous(l);
		int r = ids.nextto(l);

		if (r != ids.back) {
			if (l != ids.front && cross(all[l], all[x], all[r]) >= 0) return;
			while (1) {
				int t = r; r = ids.nextto(r);
				if (r == ids.back) break;
				if (cross(all[x], all[t], all[r]) < 0) break;
				else pop(t);
			}
		}
		if (l != ids.front) {
			int t;
			while (1) {
				t = l; l = ids.previous(l);
				if (l == ids.front) break;
				if (cross(all[l], all[t], all[x]) < 0) break;
				else pop(t);
			}
			l = t;
		}
		push(l, x);
	}

	void Add(int x) {
		assert(!exist[x]);
		exist[x] = true;
		Add_to_convex(x);
	}

	void Remove(int x) {
		assert(exist[x]);
		exist[x] = false;
		if (!ids.exist[x]) return;
		Remove_from_convex(x);
	}

	fast_convex(Polygon &pts) {
        all = pts;
        ids = LIST(all.size());
        exist.resize(all.size());
        area = 0;
        sorted = get_sorted_ids(all);
	}
};

struct merged_convex {
	fast_convex up, down;
	vector<ull> has;
	ull hash_code;
	merged_convex(Polygon pts, bool add = false) {
		has.resize(pts.size());
		for (ull &p:has) p = splitmix64();
		up = fast_convex(pts);
		for (auto &p:pts) p.y = -p.y;
		down = fast_convex(pts);
		hash_code = 0;
		if (add) {
			for (int i = 0; i < pts.size(); i ++) Add(i);
		}
	}
	vector<int> border() {
		vector<int> now = up.ids.get_vector();
		vector<int> tmp = down.ids.get_vector();
		now.insert(now.end(), tmp.begin(), tmp.end());
		return now;
	}
	void Remove(int i) {
		hash_code ^= has[i];
		up.Remove(i);
		down.Remove(i);
	}
	void Add(int i) {
		hash_code ^= has[i];
		up.Add(i);
		down.Add(i);
	}
	int area() {
		return up.area + down.area;
	}
	bool exist(int i) {
		return up.exist[i];
	}
};

int greedy_solve() {
	merged_convex hull(location, true);

	vector<int> ans;
	int runs = N;
	int sum = 0;
	while (runs --) {
		int mn = inf, best = -1;
		vector<int> now = hull.border();
		for (int i:now) {
			hull.Remove(i);
			int cur = hull.area();
			if (cur < mn || (cur == mn && location[i] < location[best])) {
				mn = cur;
				best = i;
			}
			hull.Add(i);
		}
		assert(best >= 0);
        sum += mn;
        hull.Remove(best);
        ans.push_back(best);
	}
	update(ans, sum);
	return sum;
}
}

namespace DOL {
void wahaha(vector<int> &ans, int d = 15) {
	reverse(ans.begin(), ans.end());

	vector<Polygon> cnvs(N);
	vector<int> ar(N);

	int score = 0;
	for (int i = 0; i < N; i ++) {
		if (i > 0) cnvs[i] = cnvs[i-1];
		cnvs[i].push_back(location[ans[i]]);
        convexhull(cnvs[i]);
        ar[i] = area(cnvs[i]);
        score += ar[i];
	}

	vector<int> possible(N, true);
	int jump = 0;
	while (1) {
		int old = score;
		for (int i = 0; i + 2 * d <= N; i ++) if (possible[i]) {
			if (cl.get_time() > TIME_LIMIT) break;
			int old = score;
			vector<int> le(d+1), ri(d+1);
			for (int j = 1; j <= d; j ++) le[j] = ans[i+j-1], ri[j] = ans[i+j+d-1];

			vector<vector<int> > dp(d+1), prv(d+1);
			for (auto &p:dp) p.resize(d+1);
			for (auto &p:prv) p.resize(d+1);

			Polygon cv;
			if (i > 0) cv = cnvs[i-1];
			for (int l = 0; l <= d; l ++) {
				if (l) {
					cv.push_back(location[le[l]]);
					convexhull(cv);
				}
				Polygon dv = cv;
				for (int r = 0; r <= d; r ++) {
					if (r) {
						dv.push_back(location[ri[r]]);
						convexhull(dv);
					}
					int &cur = dp[l][r];
					cur = inf;
					if (r && chkmin(cur, dp[l][r-1])) prv[l][r] = 1;
					if (l && chkmin(cur, dp[l-1][r])) prv[l][r] = 0;
					if (cur == inf) cur = 0;
					else cur += area(dv);
				}
			}
			int l = d, r = d, p = i + 2 * d - 1;
			while (l || r) {
				if (prv[l][r]) assert(r), ans[p] = ri[r], r --;
				else assert(l), ans[p] = le[l], l --;
				p --;
			}
			for (int l = i; l < i + 2 * d; l ++) {
				score -= ar[l];
				if (l > 0) cnvs[l] = cnvs[l-1];
				cnvs[l].push_back(location[ans[l]]);
				convexhull(cnvs[l]);
				ar[l] = area(cnvs[l]);
				score += ar[l];
			}
			int to = i + 2 * d - 2;
			for (int l = i; l <= to; l ++) {
				for (int r = l; r >= i; r --) {
					bool ok = false;
					for (auto &p:cnvs[r+1]) {
						if (p == location[ans[r+1]]) {
							ok = true;
							break;
						}
					}
					if (ok) break;
					score -= ar[r];
					swap(ans[r], ans[r+1]);
					if (r > 0) cnvs[r] = cnvs[r-1];
					cnvs[r].push_back(location[ans[r]]);
					convexhull(cnvs[r]);
					ar[r] = area(cnvs[r]);
					score += ar[r];
				}
			}
			if (score >= old) possible[i] = false;
			else {
				int le = max(0, i - 2 * d + 1), ri = min(N - 2 * d, i + 2 * d - 1);
				for (int j = le; j <= ri; j++) possible[j] = true;
				i += jump;
			}
		}
		if (score >= old) {
			if (jump == 0) d *= 2, fill(possible.begin(), possible.end(), true), jump = 0;
			else jump = 0;
		}
		if (cl.get_time() > TIME_LIMIT) break;
	}
    reverse(ans.begin(), ans.end());
}
}


void convert() {
	cl = Timer();
	best_score = 1e9;
	all.clear();
}

bool inside(Point a, Point b, Point c) {
	return abs(a - b ^ a - c) <= 0 && (a - b & a - c) <= 0;
}


int inside_poly(Point q, Polygon &p) {
    int cross = 0, n = p.size();
    for (int i = 0, j = 1; i < n; i ++, j ++) {
        if (j == n) j = 0;
        if (inside(q, p[i], p[j])) return 1;
        if (p[i].y <= q.y && q.y < p[j].y || p[j].y <= q.y && q.y < p[i].y) {
            long long x = 1ll * (p[i] - q ^ p[j] - q) * (p[j].y - p[i].y);
            if (x >= 0) cross ++;
        }
    }
    return cross & 1;
}

bool type2() {
    vector<vector<pii> > bor(4);
    for (int i = 0; i < N; i ++) {
        Point &p = location[i];
        if (p.y == 0 && p.x < 512) bor[0].emplace_back(p.x, i);
        else if (p.x == 512 && p.y < 512) bor[1].emplace_back(p.y, i);
        else if (p.y == 512 && p.x > 0) bor[2].emplace_back(p.x, i);
        else if (p.x == 0 && p.y > 0) bor[3].emplace_back(p.y, i);
    }
    int flag = 0;
    for (int i = 0; i < 4; i ++) if (!bor[i].empty()) {
            sort(bor[i].begin(), bor[i].end());
            int mx = -1, l, r;
            for (int j = 0; j < bor[i].size(); ) {
                int k = j + 1;
                while (k < bor[i].size() && bor[i][k].first - bor[i][k-1].first == 1) k ++;
                if (k - j > mx) {
                    mx = k - j, l = j, r = k;
                }
                j = k;
            }
            if (mx > 1) {
                bor[i].erase(bor[i].begin() + r, bor[i].end());
                bor[i].erase(bor[i].begin(), bor[i].begin() + l);
            } else bor[i].clear();
            if (bor[i].size() > 10) flag ++;
        }
	if (flag < 2) return false;
	vector<int> id(4);
    for (int i = 0; i < 4; i ++) id[i] = i;
    Polygon corner = {Point(512, 0), Point(512, 512), Point(0, 512), Point(0, 0)};
    while (1) {
		Polygon cnv;
		vector<int> ans;
		if (id[1] == (id[0] + 1) % 4 || id[0] == (id[1] + 1) % 4) {
			vector<int> le(1), ri(1);
			for (auto &p:bor[id[0]]) le.push_back(p.second);
			for (auto &p:bor[id[1]]) ri.push_back(p.second);
			if (le.size() > 1 && ri.size() > 1) {
				int c = id[0];
				if (id[0] == (id[1] + 1) % 4) c = id[1];
				vector<int> dis(N);
				for (int i = 0; i < N; i ++) dis[i] = abs(corner[c].x - location[i].x) + abs(corner[c].y - location[i].y);

				if (dis[le[1]] > dis[le.back()]) reverse(le.begin()+1, le.end());
				if (dis[ri[1]] > dis[ri.back()]) reverse(ri.begin()+1, ri.end());
                int n = le.size(), m = ri.size();
                vector<vector<int> > dp(n), prv(n);
                for (int i = 0; i < n; i ++) dp[i].resize(m), prv[i].resize(m);
                dp[0][0] = 0;
                for (int i = 0; i < n; i ++) {
					for (int j = 0; j < m; j ++) {
						if (i == 0 && j == 0) continue;
						dp[i][j] = inf;
                        if (j > 0 && chkmin(dp[i][j], dp[i][j-1])) prv[i][j] = 1;
                        if (i > 0 && chkmin(dp[i][j], dp[i-1][j])) prv[i][j] = 0;
                        if (i > 0 && j > 0) dp[i][j] += dis[le[i]] * dis[ri[j]];

					}
                }
                int l = n - 1, r = m - 1;
                while (l > 0 || r > 0) {
					if (prv[l][r]) ans.push_back(ri[r--]);
					else ans.push_back(le[l--]);
                }
                reverse(ans.begin(), ans.end());
			}
			else {
				for (int i = 1; i < le.size(); i ++) ans.push_back(le[i]);
				for (int i = 1; i < ri.size(); i ++) ans.push_back(ri[i]);
			}
			Polygon cnv;
			for (int i:ans) cnv.push_back(location[i]);
			convexhull(cnv);
			for (int ii = 2; ii < 4; ii ++) {
				int i = id[ii];
				vector<pii> &cur = bor[i];
				if (cur.empty()) continue;
				Polygon upd = cnv;
				upd.push_back(location[cur[0].second]);
				convexhull(upd);
				int ar = area(upd);
				upd = cnv;
				upd.push_back(location[cur.back().second]);
				convexhull(upd);
				if (area(upd) < ar) reverse(cur.begin(), cur.end());
				for (auto &p:cur) ans.push_back(p.second), cnv.push_back(location[p.second]);
				convexhull(cnv);
			}
		}
		else {
			for (int ii = 0; ii < 4; ii ++) {
				int i = id[ii];
				vector<pii> &cur = bor[i];
				if (cur.empty()) continue;
				Polygon upd = cnv;
				upd.push_back(location[cur[0].second]);
				convexhull(upd);
				int ar = area(upd);
				upd = cnv;
				upd.push_back(location[cur.back().second]);
				convexhull(upd);
				if (area(upd) < ar) reverse(cur.begin(), cur.end());
				for (auto &p:cur) ans.push_back(p.second), cnv.push_back(location[p.second]);
				convexhull(cnv);
			}
		}
		vector<Polygon> cnvs(N);
		cnvs[0].push_back(location[ans[0]]);
		for (int i = 1; i < ans.size(); i ++) {
			cnvs[i] = cnvs[i-1];
			cnvs[i].push_back(location[ans[i]]);
			convexhull(cnvs[i]);
		}
		vector<bool> vis(N);
		for (int i:ans) vis[i] = true;
		vector<vector<int> > g(ans.size());
		for (int i = 0; i < N; i ++) if (!vis[i]) {
			int l = 0, r = ans.size();
			while (r - l > 1) {
				int m = (l + r) >> 1;
				if (!inside_poly(location[i], cnvs[m])) l = m;
				else r = m;
			}
			g[l].push_back(i);
		}

		for (int i = 0; i < ans.size(); i ++) {
			Polygon now = cnvs[i];
			vector<int> tmp;
			while (tmp.size() < g[i].size()) {
				int mn = inf, best = -1;
				for (int j:g[i]) if (!vis[j]) {
					Polygon upd = now;
					upd.push_back(location[j]);
					convexhull(upd);
					int ar = area(upd);
					if (mn > ar) {
						mn = ar, best = j;
					}
				}
				assert(best >= 0);
				tmp.push_back(best), vis[best] = 1;
				now.push_back(location[best]);
				convexhull(now);
			}
			g[i] = tmp;
		}

		vector<int> upd;
		vector<int> pos(ans.size());
		for (int i = 0; i < ans.size(); i ++) {
			pos[i] = upd.size();
			upd.push_back(ans[i]);
			for (int j:g[i]) upd.push_back(j);
		}
		ans = upd;

		Polygon now;
		int sum = 0;
		for (int i:ans) {
			now.push_back(location[i]);
			convexhull(now);
			sum += area(now);
		}
		sum -= area(now);
		reverse(ans.begin(), ans.end());
		update(ans, sum);

		if (!next_permutation(id.begin(), id.end())) break;
    }
    return true;
}

namespace GETTYPE {
	bool vis[520][520];
	bool is_type4() {
		memset(vis, 0, sizeof vis);
		for (auto p : location) vis[p.x][p.y] = 1;
		if (!vis[256][256]) return 0;
		vector <Point> vec;
		for (auto p : location) {
			if (p.x == 256 && p.y == 256) continue;
			if (p.x == 256 && p.y > 256) {
				if (!vis[256][512]) vec.push_back(Point(0, 1));
				continue;
			}
			if (p.x == 256 && p.y < 256) {
				if (!vis[256][0]) vec.push_back(Point(0, -1));
				continue;
			}
			if (p.y == 256 && p.x > 256) {
				if (!vis[512][256]) vec.push_back(Point(1, 0));
				continue;
			}
			if (p.y == 256 && p.x < 256) {
				if (!vis[0][256]) vec.push_back(Point(-1, 0));
				continue;
			}
			int d = __gcd(abs(256 - p.x), abs(256 - p.y));
			int dx = (p.x - 256) / d, dy = (p.y - 256) / d;
			int xx, yy, k;
			if (p.x > 256 && p.y > 256) {
				k = min(256 / dx, 256 / dy);
			}
			else if (p.x > 256 && p.y < 256) {
				k = min(256 / dx, 256 / abs(dy));
			}
			else if (p.x < 256 && p.y > 256) {
				k = min(256 / abs(dx), 256 / dy);
			}
			else if (p.x < 256 && p.y < 256) {
				k = min(256 / abs(dx), 256 / abs(dy));
			}
			xx = 256 + dx * k;
			yy = 256 + dy * k;
			if (!(xx == 0 || xx == 512 || yy == 0 || yy == 512)) {
				return 0;
			}
			assert(xx >= 0 && xx <= 512 && yy >= 0 && yy <= 512);
			if (!vis[xx][yy]) vec.push_back(Point(dx, dy));
		}
		sort(vec.begin(), vec.end());
		int total = unique(vec.begin(), vec.end()) - vec.begin();
		if (total <= 1) return 1;
		return 0;
	}
	int get_type() {
		if (is_type4()) return 4;
		using pii = pair <int, int>;
		memset(vis, 0, sizeof vis);
		for (auto p : location) vis[p.x][p.y] = 1;
		int sz = location.size();
		long long cnt = 0;
		map <pii, int> h;
		for (int i = 0; i < sz; i ++) {
			h.clear();
			for (int j = i+1; j < sz; j ++) {
				auto p = location[j] - location[i];
				int d = __gcd(p.x, p.y);
				if (!d) continue;
				if (p.x + p.y < 0) p.x = -p.x, p.y = -p.y;
				p.x /= d, p.y /= d;
				h[pii(p.x, p.y)] ++;
			}
			for (auto x : h) cnt += 1ll * x.second * (x.second - 1) / 2;
		}
		if (cnt < 10000) return 1;
		return 3;
	}
}

using namespace GETTYPE;

int main() {
    input();
    convert();
    int rev[5] = {0, 1, 1, 0, 1};
    if (type2()) {
		if (rev[2]) reverse_solve();
		if (best_score > M) greedy::greedy_solve();
		DOL::wahaha(best_ans);
    }
    else {
		int type = get_type();
		if (rev[type]) reverse_solve();
		if (best_score > M) greedy::greedy_solve();
		DOL::wahaha(best_ans);
    }
	cout<<best_ans[0]+1;
    for (int i = 1; i < best_ans.size(); i ++) cout<<' '<<best_ans[i]+1;
}

