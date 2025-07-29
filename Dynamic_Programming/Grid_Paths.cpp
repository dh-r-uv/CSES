#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int mod = 1e9 + 7;

int32_t main(){
	int n;
	cin >> n;
	vector<string> v(n);
	for(auto &x: v)
		cin >> x;
	vector<vector<int>> dp(n, vector<int>(n));
	dp[0][0] = v[0][0]=='.';
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(v[i][j]!='.')
				continue;
			if(i-1>=0)
				dp[i][j] += dp[i-1][j];
			if(j-1>=0)
				dp[i][j] += dp[i][j-1];
			dp[i][j] %= mod;
		}
	}
	cout << dp[n-1][n-1]<<endl;
}