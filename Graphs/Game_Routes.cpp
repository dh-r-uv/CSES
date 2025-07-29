#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1e18
#define mod 1000000007ll


int32_t main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1];
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> order, vis(n+1);
    function<void(int)> dfs = [&](int u){
        vis[u] = 1;
        for(int v : adj[u])
            if(!vis[v]) 
                dfs(v);
        order.push_back(u);
    };
    for(int i=1; i<=n; i++)
        if(!vis[i])
            dfs(i);
    reverse(order.begin(), order.end());
    vector<int> dp(n+1);
    dp[1] = 1;
    for(auto u: order)
        for(auto v: adj[u])
            dp[v] = (dp[v] + dp[u]) % mod;
        
    cout << dp[n] << endl;

}