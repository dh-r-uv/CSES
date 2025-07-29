#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
	int n;
	cin >> n;
	vector<int> adj[n+1];
	for(int i=1; i<n; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	function<pair<int, int>(int, int)> dfs = [&](int u, int p) ->pair<int, int>{
		pair<int, int> mx = {0, u};
		for(auto v: adj[u]){
			if(v==p)
				continue;
			auto [d, x] = dfs(v, u);
			mx = max(mx, {d+1, x});
		}
		return mx;
	};
	auto [d, x] = dfs(1, 0);
	auto [d2, x2] = dfs(x, 0);
	cout << d2 <<endl;
}