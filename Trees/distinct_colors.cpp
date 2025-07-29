#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++)
        cin >> a[i];
    vector<int> adj[n+1];
    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<set<int>> color(n+1);
    for(int i=1; i<=n; i++)
        color[i].insert(a[i]);
    vector<int> ans(n+1);
    function<void(int, int)> dfs = [&](int u, int p){
        for(auto v: adj[u]){
            if(v == p) continue;
            dfs(v, u);
            if(color[v].size() > color[u].size())
                swap(color[u], color[v]);
            for(auto x: color[v])
                color[u].insert(x);
        }
        ans[u] = color[u].size();
    };
    dfs(1, 0);
    for(int i=1; i<=n; i++)
        cout << ans[i] << ' ';
    cout << '\n';
}