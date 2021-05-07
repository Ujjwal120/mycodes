

// 1.27 sec solution

# include <bits/stdc++.h>
using namespace std;
# define rep(i,a,n) for (int i=a; i<=n; ++i)
# define per(i,a,n) for (int i=a; i>=n; --i)
# define bug puts("H");
# define pb push_back
# define mp make_pair
# define all(x) (x).begin(), (x).end()
# define fi first
# define se second
# define lch p<<1,l,mid
# define rch p<<1|1,mid+1,r
# define mem(a,b) memset(a,b,sizeof(a))
# define INF 1000000001
# define MOD 1000000007
typedef vector<int> Vi;
typedef long long i64;
typedef pair<int, int> Pi;
i64 powmod(i64 a, i64 b){i64 res=1;a%=MOD;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
i64 Inv(i64 b){return powmod(b,(i64)MOD-2);}
inline int Scan() {
    int x=0; char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    return x;
}
const int N = 40;
//const int M = 524288;
const double eps = 1e-9;

int n;
i64 ans;
map<int, int> Mp;
int top;
int G[6][N][N], w[6], mi[6][N], mark[6][N];
struct newG{
    int E[N][N];
    int n;
    int val;
}ng;
int id[N];

void initnewG() {
    mem(ng.E, 0);
    ng.n = ng.val = 0;
}
void buildnewG(int i, int j) {
    if (mark[i][j] == 1) return ;
    mark[i][j] = 1; ++ng.n; id[j] = ng.n;
    for (int k = 1; k <= n; ++k) {
        if (G[i][j][k] != -1 && id[k]) ng.E[id[j]][id[k]] = ng.E[id[k]][id[j]] = 1;
        if (mark[i][k] == 1 || G[i][j][k] == -1) continue;
        buildnewG(i, k);
    }
}
int sta[1<<24], tmp[25];
int dp[16][1<<15];

void dfs(int now, int n, int d, int s, int num) {
    if (now > n) {
        d == 0 ? (sta[s] = 1) : (dp[num][s] = 1);
        return ;
    }
    dfs(now+1,n,d,s,num);
    bool flag = false;
    rep(i,d+1,d+now-1) if (tmp[i-d] && ng.E[i][d+now]) {flag = true; break;}
    if (flag) return ;
    tmp[now] = 1;
    dfs(now+1, n, d, s|(1<<(now-1)), num+1);
    tmp[now] = 0;
}
i64 solve() {
    if (ng.n == 1) return (1 + ng.val);
    if (ng.n == 2) return (1 + 2*ng.val);

    i64 res = 0;
    int mid = (ng.n+4) / 5 * 3;
    int S = (1<<mid)-1;
    int s = (1<<(ng.n-mid))-1;
    rep(i,0,S) sta[i] = 0;
    rep(j,0,ng.n-mid) rep(i,0,s) dp[j][i] = 0;

    mem(tmp,0); dfs(1,mid,0,0,0);
    mem(tmp,0); dfs(1,ng.n-mid,mid,0,0);

    rep(j,0,ng.n-mid) per(k,s,0) for (int i = (k-1)&k; i!=k; i=(i-1)&k) {
        //cout << ((-1)&k) << endl;
        dp[j][k] = (dp[j][k] + dp[j][i]) % MOD;
    }

    mem(tmp,0);
    rep(i,1,mid) rep(j,mid+1,ng.n) {
        if (ng.E[i][j] == 0) tmp[i] |= (1<<(j-mid-1));
    }

    rep(i,0,S) {
        if (sta[i] == 0) continue;
        int t = s, num = 0;
        rep(j,0,mid-1) if ((i>>j)&1) t &= tmp[j+1], ++num;
        rep(j,0,ng.n-mid) {
            res = (res + dp[j][t]*powmod(ng.val, j+num)) % MOD;
        }
    }

    return res;
}
int main ()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        mem(G, -1); top = 0; Mp.clear(); mem(mi, -1); mem(mark, 0); ans = 1;
        int m, x, y, r, p, e;
        bool flag = false;
        scanf("%d%d", &n, &m);
        rep(i,1,m) {
            scanf("%d%d%d", &x, &y, &r);
            mem(w, 0);
            rep(j,1,r) {
                scanf("%d%d", &p, &e);
                if (Mp.find(p) == Mp.end()) Mp[p] = ++top;
                w[Mp[p]] += e;
            }
            rep(j,1,5) {
                if (G[j][x][y] != -1 && G[j][x][y] != w[j]) flag = true;
                G[j][x][y] = G[j][y][x] = w[j];
            }
        }
        if (flag) {puts("0"); continue;}
        rep(i,1,n) rep(j,i+1,n) rep(k,1,5) {
            if (G[k][i][j] == -1) continue;
            mi[k][i] = (mi[k][i] == -1 ? G[k][i][j] : min(mi[k][i], G[k][i][j]));
            mi[k][j] = (mi[k][j] == -1 ? G[k][i][j] : min(mi[k][j], G[k][i][j]));
        }
        rep(i,1,n) rep(j,i+1,n) rep(k,1,5) {
            if (G[k][i][j] == -1) continue;
            if (mi[k][i] < G[k][i][j] && mi[k][j] < G[k][i][j]) flag = true;
            else if (mi[k][i] < G[k][i][j]) mark[k][j] = 1;
            else if (mi[k][j] < G[k][i][j]) mark[k][i] = 1;
        }
        rep(i,1,n) rep(j,1,5) if (mi[j][i] == 0) mark[j][i] = 1;
        if (flag) {puts("0"); continue;}
        rep(i,1,n) rep(j,1,5) if (mi[j][i] == -1) flag = true;
        if (flag) {puts("-1"); continue;}

        rep(i,1,5) {
            mem(id, 0);
            rep(j,1,n) {
                if (mark[i][j] == 1) continue;
                initnewG();
                ng.val = mi[i][j];
                buildnewG(i,j);

                //for (int i = 1; i <= n; ++i) {for (int j = 1; j <= n; ++j) cout << ng.E[i][j] << " "; cout << endl;}

                ans = ans * solve() % MOD;
            }
        }

        printf("%lld\n", ans);
    }
    return 0;
}
