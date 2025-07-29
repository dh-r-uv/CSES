#include<bits/stdc++.h>
#define int long long
using namespace std;
#define inf 1e18
#define mod 1000000007ll


int32_t main(){
    int n, m;
    cin >> n >> m;
    vector<array<int, 2>> adj[n+1];
    for(int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); 
    }
    //mst using prims
    vector<int> vis(n+1, 0);
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
    pq.push({0, 1}); // {weight, node}
    int ans = 0;
    int c = 0;
    while(!pq.empty()){
        auto [d, u] = pq.top(); pq.pop();
        if(vis[u]) continue; 
        vis[u] = 1; 
        ans += d; 
        c++;
        for(auto [v, w] : adj[u]){
            if(!vis[v]) 
                pq.push({w, v});
        }
    }
    if(c < n-1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout << ans << endl;
}