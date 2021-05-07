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
int N, Q;

inline int64_t gO(int x, int y, int pow, int rotate) {
	if(pow == 0){
		return 0;
	}
	int hpow = 1 << (pow - 1);
	int seg = (x < hpow) ? ( (y < hpow) ? 0 : 3) : ((y < hpow) ? 1 : 2);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	int64_t subSquareSize = int64_t(1) << (2 * pow - 2);
	int64_t ans = seg * subSquareSize;
	int64_t add = gO(nx ,ny ,pow - 1, nrot);
	ans += (seg == 1||seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}

struct query{
	int id, l, r;
    int64_t billa;
    inline void cO() {
	    billa = gO(l, r, 19, 0);
	}
};

inline bool cmp(query a, query b) {
	return a.billa < b.billa;
}

void compute(query QQ[], int a[]) {
    int curL = QQ[0].l, curR = QQ[0].l - 1;
    int diff = 0; 
    int cnt[N+1] = {0}, ANS[Q] = {0};
    for(int i = 0; i < Q; i++) {
        while(curL < QQ[i].l) {
            cnt[a[curL]]--; 
            if(cnt[a[curL]] == 0) diff--;
            curL++;
        }

        while(curL > QQ[i].l) {
            --curL;
            cnt[a[curL]]++;
            if(cnt[a[curL]] == 1) diff++;
        }

        while(curR < QQ[i].r) {
            ++curR;
            cnt[a[curR]]++;
            if(cnt[a[curR]] == 1) diff++;
        }

        while(curR > QQ[i].r) {
            cnt[a[curR]]--;
            if(cnt[a[curR]] == 0) diff--;
            curR--;
        }

        ANS[QQ[i].id] = diff;
    }
    for(int i = 0; i < Q; i++) cout << ANS[i] << "\n";
}

void solve() {
    int L, R; cin >> N >> Q;
    query QQ[Q]; int a[N+1];
    for(int i = 1; i <= N; i++) cin>>a[i];
    for(int i = 0; i < Q; i++) {
        cin >> L >> R;
        QQ[i].l = L; QQ[i].r = R; QQ[i].id = i;
        QQ[i].cO();
    }
    sort(QQ, QQ + Q, &cmp);
    compute(QQ, a);   
}

int main() {
    fast 
    // input output
    int t = 1; 
    // cin>>t; 
    while(t--) solve();
    return 0;
}