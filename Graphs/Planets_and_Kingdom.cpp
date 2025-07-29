#include<bits/stdc++.h>
#define int long long
using namespace std;
#define inf 1e18
#define mod 1000000007ll


int32_t main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1], adj2[n+1];
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj2[v].push_back(u); 
    }
    vector<int> vis(n+1);
    vector<int> order;
    function<void(int)> dfs = [&](int u){
        vis[u] = 1;
        for(auto v: adj[u])
            if(!vis[v]) 
                dfs(v);
        order.push_back(u);
    };
    
    for(int i=1; i<=n; i++)
        if(!vis[i])
            dfs(i);
    reverse(order.begin(), order.end());
    vis.assign(n+1, 0);
    int col = 0;
    function<void(int, int)> dfs2 = [&](int u, int c){
        vis[u] = c;
        for(auto v: adj2[u])
            if(!vis[v]) 
                dfs2(v, c);
    };
    for(auto u: order)
        if(!vis[u])
            dfs2(u, ++col);
    cout << col << endl;
    for(int i=1; i<=n; i++)
        cout << vis[i] << " ";
    cout << endl;
}