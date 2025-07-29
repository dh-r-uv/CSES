#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;

int32_t main(){
	int m, n;
	cin >> m >> n;
	vector<int> c(m);
	for(auto &x: c) 
		cin >> x;
	vector<int> dp(n+1);
	dp[0] = 1;
	for(int i=1; i<=n; i++)
		for(auto x: c)
			if(i - x >= 0)
				dp[i] = (dp[i] + dp[i - x]) % mod;
	cout << dp[n]<<endl;
}