#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
	int n, m;
	cin >> m >> n;
	vector<int> c(m);
	for(auto &x: c) 
		cin >> x;
	vector<int> dp(n+1, INT_MAX);
	dp[0] = 0;
	for(int i = 1; i<=n; i++)
		for(auto x: c)
			if(i - x >= 0)
				dp[i] = min(dp[i], dp[i - x] + 1);
	
	cout << (dp[n]==INT_MAX?-1:dp[n])<<endl;
}
