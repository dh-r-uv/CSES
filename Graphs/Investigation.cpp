#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf LLONG_MAX
#define mod 1000000007ll

int32_t main(){
    int n, m;
    cin >> n >> m;
    vector<array<int, 2>> adj[n+1];
    for(int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    // Topo cant work cuz edges have weights
    vector<int> dis(n+1, inf), way(n+1, 0), mx(n+1, 0), mn(n+1, inf);
    dis[1] = 0; way[1] = 1; mx[1] = 0; mn[1] = 0;
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
    pq.push({0, 1}); 
    while(!pq.empty()){
        auto [d, u] = pq.top(); pq.pop();
        if(d > dis[u]) continue; 
        for(auto [v, w] : adj[u]){
            if(dis[v] > d + w){
                dis[v] = d + w;
                way[v] = way[u];
                mx[v] = mx[u] + 1;
                mn[v] = mn[u] + 1;
                pq.push({dis[v], v});
            } else if(dis[v] == d + w) {
                way[v] += way[u];
                way[v] %= mod;
                mx[v] = max(mx[v], mx[u] + 1);
                mn[v] = min(mn[v], mn[u] + 1);
            }
        }
    }
    cout << dis[n] << " " << way[n] << " " << mn[n] << " " << mx[n] << endl;
}