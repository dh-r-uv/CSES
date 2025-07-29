#include<bits/stdc++.h>
#define int long long
#define inf 1e18
using namespace std;

int32_t main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1], order, vis(n+1);
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    // finding the longest path from 1 to n

    function<void(int)> dfs = [&](int u)->void {
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
    vector<int> dis(n+1, -1), par(n+1, -1);
    par[1] = 0; // starting point
    dis[1] = 0; 
    for(auto u : order)
        for(int v : adj[u])
            // dis[v] = max(dis[v], {dis[u][0] + 1, u});
            if(dis[u]!=-1 && dis[v] < dis[u] + 1){
                dis[v] = dis[u] + 1;
                par[v] = u;
            }
    if(dis[n]== -1)
        cout << "IMPOSSIBLE\n";
    else{
        vector<int> path;
        for(int u = n; u != 0; u = par[u])
            path.push_back(u);
        reverse(path.begin(), path.end());
        cout << path.size() << endl;
        for(int x : path)
            cout << x << " ";
        cout << endl;
    }

}