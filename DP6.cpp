// codechef problem

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
const int N= 2e5+10, mod=1e9+7;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int tc; cin>>tc;
	while(tc--){
		int n,k;
		cin>>n>>k;
		int a[n], dp[n], ct[101];
		
		for(int i=0;i<n;i++) cin>>a[i];
		
		dp[0]=k;
		for(int i=1;i<n;i++){
			for(int j=0;j<101;j++)ct[j]=0;
			
			dp[i]=INF;
			ct[a[i]]++;
			int cost=k;
			
			for(int j=i-1;j>=0;j--){
				// table : j+1 ... i 
				dp[i] = min(dp[i],dp[j]+cost);
				
				if(ct[a[j]] == 1) cost++;
				if(ct[a[j]] != 0 ) cost++;	// if a[j] is already present in table
				ct[a[j]]++;
			}
			dp[i]=min(dp[i],cost);
		}		
		cout<<dp[n-1]<<"\n";
	}
	
	return 0;
}