#include<bits/stdc++.h>

#define ll long long int
#define ld long double
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define INF 0x3f3f3f3f // 100'000'000'000'000
#define all(x) x.begin(),x.end()

using namespace std;
const int N= 5e5+10, mod=1e9+7;
int fact[N], ifact[N];

int mul(int a,int b){
	return (a*1ll*b)%mod;
}

int add(int a,int b){
	a+=b;
	if(a<0) a+=mod;
	if(a>=mod) a-=mod;
	return a;
}

int power(int a,int n){
	if(n==0) return 1;
	int x= power(a,n/2);
	x=mul(x,x);
	if(n&1) return mul(x,a);
	return x;
}

int comb(int n,int r){
	if(n==0||r>n||r<0) return 0;
	return mul( fact[n], mul(ifact[r], ifact[n-r]));
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    fact[0]=ifact[0]=1;
    
    for(int i=1;i<N;i++){
		fact[i]=mul(fact[i-1],i);
	}
	ifact[N-1]= power(fact[N-1],mod-2);
	
	for(int i=N-2;i>0;i--){
		ifact[i]= mul(ifact[i+1],i+1);
	}
    
	int tc;
	cin>>tc;
	while(tc--){
		int n;
		cin>>n;
		
		vector<int> f(n+1);
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			f[x]++;
		}
		
		map<int,int> res[n+1];
		vector<int> temp(n+1,1), lazy(n+2,1);
		
		for(int i=n;i>0;i--){
			int preSum=1;	
			for(int j=1;j<=f[i];j++){
				
				if(lazy[j]!=1){
					temp[j] = mul(temp[j],lazy[j]);
					lazy[j+1]=mul(lazy[j+1],lazy[j]);
					lazy[j]=1;
				}
				
				int hehe = comb(f[i],j);
				
				preSum= add(preSum, hehe );
				res[i][j] = mul(temp[j], hehe );
									
				temp[j]= mul(temp[j],preSum);
				
			}
			lazy[ f[i]+1 ] = mul( lazy[ f[i]+1 ], preSum);
			//for(int j=f[i]+1;j<=n;j++) temp[j]= mul(temp[j],preSum);
		}
				
		lazy.clear();
		temp.clear();
		lazy.resize(n+2,1);
		temp.resize(n+1,1);
		
		for(int i=1;i<=n;i++){
			int preSum=1;			
			for(int j=1;j<=f[i];j++){
				
				if(lazy[j-1]!=1){
					temp[j-1] = mul(temp[j-1],lazy[j-1]);
					lazy[j]=mul(lazy[j],lazy[j-1]);
					lazy[j-1]=1;
				}
				
				res[i][j]= mul(temp[j-1],res[i][j]);
			}
			for(int j=1;j<=f[i];j++){
				
				if(lazy[j]!=1){
					temp[j] = mul(temp[j],lazy[j]);
					lazy[j+1]=mul(lazy[j+1],lazy[j]);
					lazy[j]=1;
				}
				
				preSum= add(preSum, comb(f[i],j));
				temp[j]=mul(temp[j],preSum);
			}
			
			lazy[ f[i]+1 ] = mul( lazy[ f[i]+1 ], preSum);
			//for(int j=f[i]+1;j<=n;j++) temp[j]= mul(temp[j],preSum);
		}		

		for(int i=1;i<=n;i++){
			int cur=0;
			for(auto x:res[i]) cur=add(cur,x.yy);
			cout<<cur<<" ";
		}
		cout<<"\n";
		
	}
	
	return 0;
}


