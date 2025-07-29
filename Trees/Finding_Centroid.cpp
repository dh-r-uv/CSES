#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n;
    cin >> n;
    vector<int> adj[n+1];
    for(int i=0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> sub(n+1);
    function<void(int, int)> dfs = [&](int u, int p){
        sub[u] = 1;
        for(auto v: adj[u]){
            if(v == p) continue;
            dfs(v, u);
            sub[u] += sub[v];
        }
    };
    function<int(int, int)> find_centroid = [&](int u, int p=-1){
        for(auto v: adj[u]){
            if(v == p) continue;
            if(sub[v]*2 > n)
                return find_centroid(v, u);
        }
        return u;
    };
    dfs(1, 0);
    int centroid = find_centroid(1, -1);
    cout << centroid << '\n';
}