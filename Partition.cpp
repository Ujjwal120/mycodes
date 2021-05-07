#include <bits/stdc++.h>
using namespace std;
 
bool checker(int n, int k, int goal, string& s){
	function<__int128(int)> power = [&](int x){
		__int128 res = 1;
		for(int i = 0; i < k; ++i){
			res *= x;
		}
		return res;
	};
 
	__int128 is = 0;
	for(int i = 0; i < n; ++i){
		is += s[i] == '1' ? power(i + 1) : -power(i + 1);
	}
	
	return is == goal;
}
 
const int S = 20 * 1000 * 1000;
vector<bitset<S + S>> dp;
vector<int> answer, cost;
vector<vector<int>> belong; 
 
void calculate_dp(int n, int k){
	function<int(int)> power = [&](int x){
		int res = 1;
		for(int i = 0; i < k; ++i){
			res *= x;
		}
		return res;
	};
 
	dp.resize(n);
	answer.resize(n);
	cost.resize(n);
	belong.resize(n);
	dp[0][S] = 1;
	for(int i = 1; i < n; ++i){
		cost[i] = power(i);
		dp[i] = (dp[i - 1] << cost[i]) | (dp[i - 1] >> cost[i]);		
	}
 
	for(int i = 1; i < n; ++i){
		for(int j = S; ; ++j) if (dp[i][j]){
			answer[i] = j - S;
			vector<int>& res = belong[i];
			for(int l = i; l >= 1; --l){
				if (j - cost[l] >= 0 && dp[l - 1][j - cost[l]]){
					res.push_back(l);
					j -= cost[l];
				}else{
					assert(j + cost[l] < S + S);
					assert(dp[l - 1][j + cost[l]]);
					j += cost[l];
				}
			}
 
			reverse(res.begin(), res.end());
			assert(j == S);
			break;
		}
	}
}
 
int main(){
	int k; cin >> k;	
	calculate_dp(1 << (k + 2), k);
	int tc; cin >> tc;
	while(tc--){
		int n; cin >> n;
		string result(n, '0');
		while(n >= 1 << (k + 2)){
			for(int i = 0; i < 1 << (k + 1); ++i){
				if (__builtin_popcount(i) & 1){
					result[n - 1 - i] = '1';
				}
			}
 
			n -= 1 << (k + 1);
		}
 
		for(auto i: belong[n]){
			result[i - 1] = '1';
		}
 
		cout << answer[n] << endl;
		cout << result << endl;		
		assert(checker(n, k, answer[n], result));
	}
	
	cerr << "Time elapsed: " << clock() / (double) CLOCKS_PER_SEC << endl;
	return 0;
}