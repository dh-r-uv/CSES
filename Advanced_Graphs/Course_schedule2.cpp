# include<bits/stdc++.h>
using namespace std;

int32_t main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1];
    vector<int> indeg(n+1);
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
    }
    function<void(int)> dfs = 
}
