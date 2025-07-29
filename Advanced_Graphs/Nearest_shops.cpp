#include<bits/stdc++.h>
#define int long long
#define inf LLONG_MAX
using namespace std;
 
 
int32_t main(){
    int n, m, k;
    cin >> n >> m >> k;
    queue<array<int, 2>> q;
    vector<array<int, 2>> shop(n+1, {inf, inf}), dp(n+1, {inf, inf});
    set<int> shops;
    for(int i=0; i<k; i++){
        int x;
        cin >> x;
        shops.insert(x);
        shop[x] = {x, 0};
        dp[x][0] = 0;
        q.push({x, 1});
    }
    vector<int> adj[n+1];
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    while(!q.empty()){
        auto [u, d] = q.front();
        q.pop();
        if(d==1){
            for(auto v: adj[u]){
                if(dp[v][0]==inf){
                    dp[v][0] = dp[u][0] + 1;
                    shop[v][0] = shop[u][0];
                    q.push({v, 1});
                }
                else if(dp[v][1]==inf && shop[v][0]!=shop[u][0]){
                    dp[v][1] = dp[u][0] + 1;
                    shop[v][1] = shop[u][1];
                    q.push({v, 2});
                }
            }
        }
        else{
            for(auto v: adj[u]){
                if(dp[v][1]==inf){
                    dp[v][1] = dp[u][1] + 1;
                    shop[v][1] = shop[u][1];
                    q.push({v, 2});
                }
            }
        }
    }
    for(int i=1; i<=n; i++){
        if(shop[i][0]==i)
            cout << (dp[i][1]==inf?-1:dp[i][1]) << ' ';
        else
            cout << (dp[i][0]==inf?-1:dp[i][0]) << ' ';
    }   
    cout << '\n';
}