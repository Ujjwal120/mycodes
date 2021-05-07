
// 0.84 sec sol WHATTTTTT !!!!  i'm a fan now

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 998244353;
#define G 3
ll expmod(ll a, ll b) {
    ll rlt = 1;
    for (a %= mod; b; a = a * a % mod, b >>= 1) if (b & 1) rlt = rlt * a % mod;
    return rlt;
}

#define N (1<<19)

namespace FFT{
	int bh[N],tmpA[N],tmpB[N],tmp[N],lim=N,w[2][N];
	int qpow(int a,int b){
		int ans=1,tmp=a;
		for(;b;b>>=1,tmp=1ll*tmp*tmp%mod)
			if(b&1)ans=1ll*ans*tmp%mod;
		return ans;
	}
	void init(int b){
		for(int i=1;i<(1<<b);i<<=1){
			int wn=qpow(G,(mod-1)/(i<<1));
			for(int j=0;j<i;++j)w[1][i+j]=(j?1ll*wn*w[1][i+j-1]%mod:1);
			wn=qpow(G,mod-1-(mod-1)/(i<<1));
			for(int j=0;j<i;++j)w[0][i+j]=(j?1ll*wn*w[0][i+j-1]%mod:1);
		}
	}
	int gmod(long long x){
		return x>=mod?x-mod:x;
	}
	void fft(int h[],int len,int flag){
		if(flag==-1)flag=0;
		for(int i=0,j=0;i<len;++i){
			if(i<j)swap(h[i],h[j]);
			for(int k=len>>1;(j^=k)<k;k>>=1);
		}
		for(int i=1;i<len;i<<=1)
			for(int j=0;j<len;j+=(i<<1))
				for(int k=0;k<i;++k){
					int x=h[j+k],y=1ll*h[j+k+i]*w[flag][i+k]%mod;
					h[j+k]=gmod(1ll*x+y);
					h[j+k+i]=gmod(1ll*x-y+mod);
				}
		if(flag==0){
			int x=qpow(len,mod-2);
			for(int i=0;i<len;++i)
				h[i]=1ll*h[i]*x%mod;
		}
	}
	void poly_mul(const int A[],int lenA,const int B[],int lenB,int C[],int lenc){
		int l=1,k=0,L=min(lenA,lenc)+min(lenB,lenc)+1;
		while(l<L)l<<=1,k++;
		memset(tmpA,0,l<<2);
		memset(tmpB,0,l<<2);
		memcpy(tmpA,A,min(lenA,lenc)<<2);
		memcpy(tmpB,B,min(lenB,lenc)<<2);
		fft(tmpA,l,1),fft(tmpB,l,1);
		for(int i=0;i<l;++i)tmpA[i]=1ll*tmpA[i]*tmpB[i]%mod;
		fft(tmpA,l,-1);
		for(int i=0;i<lenc&&i<L;++i)C[i]=tmpA[i];
		for(int i=L;i<lenc;++i)C[i]=0;
	}
	void poly_inv(int n,const int a[],int C[]){
		if(n==1){
			C[0]=qpow(a[0],mod-2);
			return ;
		}
		static int A[N];
		A[0]=qpow(a[0],mod-2);
		int m=(n+1)/2,len=1,k=0;
		poly_inv(m,a,C);
		while(len<n+n)len<<=1,k++;
		memcpy(A,a,n<<2);
		memset(A+n,0,(len-n)<<2);
		memset(C+m,0,(len-m)<<2);
		fft(A,len,1),fft(C,len,1);
		for(int i=0;i<len;++i)C[i]=1ll*(2ll-1ll*A[i]*C[i]%mod+mod)*C[i]%mod;
		fft(C,len,-1);
	}

	void poly_div(const int a[],int lena,const int b[],int lenb,int C[],int& plen){
		static int A[N],B[N];
		while(!a[lena-1]&&lena>=1)lena--;
		while(!b[lenb-1]&&lenb>=1)lenb--;
		if(lena<lenb){
			plen=1,C[0]=0;
			return ;
		}
		plen=lena-lenb+1;
		memcpy(A,a,lena<<2);
		memcpy(B,b,lenb<<2);
		reverse(A,A+lena);
		reverse(B,B+lenb);
		poly_inv(plen,B,tmp);
		poly_mul(tmp,plen,A,lena,C,plen);
		reverse(C,C+plen);
	}
	typedef vector<int> Poly;
	int SZ(const Poly& v){return v.size();}
	void upd(Poly& v){while(v.size()>1&&!v.back())v.pop_back();}
	Poly operator*(const Poly& a,const Poly& b){
		Poly ret(SZ(a)+SZ(b)-1);
		poly_mul(a.data(),SZ(a),b.data(),SZ(b),ret.data(),SZ(ret));
		upd(ret);
		return ret;
	}
	Poly operator/(const Poly& a,const Poly& b){
		int len;
		poly_div(a.data(),SZ(a),b.data(),SZ(b),tmp,len);
		Poly ret=Poly(tmp,tmp+len);
		upd(ret);
		return ret;
	}
	Poly operator-(const Poly& a,const Poly& b){
		Poly ret(max(SZ(a),SZ(b)));
		for(int i=0;i<SZ(ret);++i)
			ret[i]=(1ll*(i<SZ(a)?a[i]:0)-(i<SZ(b)?b[i]:0)+mod)%mod;
		upd(ret);
		return ret;
	}
	Poly operator+(const Poly& a,const Poly& b){
		Poly ret(max(SZ(a),SZ(b)));
		for(int i=0;i<SZ(ret);++i)
			ret[i]=(1ll*(i<SZ(a)?a[i]:0)+(i<SZ(b)?b[i]:0))%mod;
		upd(ret);
		return ret;
	}
	Poly operator%(const Poly& a,const Poly& b){
		int len;
		poly_div(a.data(),SZ(a),b.data(),SZ(b),tmp,len);
		poly_mul(b.data(),SZ(b),tmp,len,tmp,SZ(a));
		for(int i=0;i<SZ(a);++i)
			tmp[i]=(1ll*a[i]-tmp[i]+mod)%mod;
		for(len=SZ(a);len>1&&!tmp[len-1];len--);
		return Poly(tmp,tmp+len);
	}
	int eval(Poly &x, int a) {
		int rlt = 0;
		for (int i = SZ(x) - 1; i >= 0; i --) rlt = (1ll * rlt * a + x[i]) % mod;
		return rlt;
	}
	void print(const Poly& x){
		printf("\n[len=%d]",SZ(x));
		for(int i=0;i<SZ(x);++i)
			printf("%d ",x[i]);
		puts("");
	}
};
using namespace FFT;

vector<int> a;
Poly s[N<<2];
Poly der(Poly s){
	Poly ret(SZ(s)-1);
	for(int i=0;i<SZ(ret);++i)
		ret[i]=1ll*s[i+1]*(i+1)%mod;
	return ret;
}
void predfs(int o,int l,int r){
	if(l==r){
		s[o]=Poly{mod-a[l],1};
		return ;
	}
	int mid=l+r>>1;
	predfs(o<<1,l,mid);
	predfs(o<<1|1,mid+1,r);
	s[o]=s[o<<1]*s[o<<1|1];
}
vector<int> f;
void get(int o,int l,int r,Poly c){
	c=c%s[o];
	if(r - l <= 512){
		for (int i = l; i <= r; i ++) f[i] = eval(c, a[i]);
		return ;
	}
	int mid=l+r>>1;
	get(o<<1,l,mid,c);
	get(o<<1|1,mid+1,r,c);
}

void solve() {
    int n, x;
    cin>>n>>x;
    a.resize(n+1);
    a[0] = 0;
    for (int i = 1; i <= n; i ++) cin>>a[i];
    if (x == 0) {
        int ans = 1;
        for (int l = 1; l <= n; l ++) ans = ans * expmod(a[l], 2 * (n + 1 - l)) % mod;
        cout<<ans<<endl;
        return;
    }
    int e = 0;
    for (int l = 1; l <= n; l ++) e = (e + 2ll * l * (n + 1 - l)) % (mod - 1);
    int ans = expmod(x, mod - 1 - e);
    for (int i = 1, c = x; i <= n; i++, c = 1ll * c * x % mod) {
        a[i] = 1ll * a[i] * c % mod;
        a[i] = (a[i] + a[i-1]) % mod;
    }
    ll tmp = 1ll * (n + 1) * n / 2;
    if (tmp&1) ans = (mod - ans) % mod;
    predfs(1, 0, n);
    f.resize(n+1);
	get(1, 0, n, der(s[1]));
    for (int i = 0; i <= n; i ++) ans = 1ll * ans * f[i] % mod;
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    FFT::init(18);
    int T;
    cin>>T;
    while (T --) solve();
}
