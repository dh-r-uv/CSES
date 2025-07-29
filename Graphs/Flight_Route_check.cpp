#include <bits/stdc++.h>

#define int long long
#define inf 1e18
#define mod 1000000007ll
using namespace std;   

int32_t main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1], trans[n+1];
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        trans[v].push_back(u);
    }
    vector<int> vis1(n+1, 0), vis2(n+1, 0);
    function<void(int)> dfs1 = [&](int u){
        vis1[u] = 1;
        for(int v : adj[u])
            if(!vis1[v]) 
                dfs1(v);
    };
    dfs1(1);
    for(int i=1; i<=n; i++)
        if(!vis1[i]){
            cout << "NO"<<endl;
            cout << "1 " << i << endl;
            return 0;
        }
    function<void(int)> dfs2 = [&](int u){
        vis2[u] = 1;
        for(int v: trans[u])
            if(!vis2[v]) 
                dfs2(v);
    };
    dfs2(1);
    for(int i=1; i<=n; i++)
        if(!vis2[i]){
            cout << "NO"<<endl;
            cout << i << " 1" << endl;
            return 0;
        }
    cout << "YES" << endl;
}