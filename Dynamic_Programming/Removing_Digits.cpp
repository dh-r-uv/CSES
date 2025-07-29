#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
	int n;
	cin >> n;
	vector<int> dp(n+1, -1);
	dp[0] = 0;
	function<int(int)> rec = [&](int num)->int{
		if(dp[num]!=-1)
			return dp[num];
		if(num == 0)
			return 0;
		int x = num;
		int ans = INT_MAX;
		while(x>0){
			int d = x%10;
			x /= 10;
			if(d)
				ans = min(ans, 1 + rec(num - d));			
		}
		return dp[num] = ans;
	};
	cout << rec(n) <<endl;

}