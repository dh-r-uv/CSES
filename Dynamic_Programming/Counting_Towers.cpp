#include<bits/stdc++.h>
#define int long long 
using namespace std;

const int mod = 1e9+7;
const int mxN = 1e6+7;
int32_t main(){
	int t;
	cin >> t;
	vector<array<int, 2>> dp(mxN+1);
	// d[0] = 2*d[0] + d[1]
	// d[1] = 4*d[1] + d[0]
	dp[1][0] = dp[1][1] = 1;
	for(int i=2; i<=mxN; i++){
		dp[i][0] = 2*dp[i-1][0] + dp[i-1][1];
		dp[i][1] = 4*dp[i-1][1] + dp[i-1][0];
		dp[i][0] %= mod;
		dp[i][1] %= mod;
	}
	while(t--){
		int n;
		cin >> n;
		cout << (dp[n][0] + dp[n][1])%mod <<endl;
	}



}
