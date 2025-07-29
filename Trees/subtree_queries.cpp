#include<bits/stdc++.h>
#define int long long
using namespace std;
#define inf 1e18
#define mod 1000000007ll

int32_t main(){
    int n, q;
    cin >> n >> q;
    vector<int> adj[n];
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    for(int i=0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> st(n), en(n);
    int timer = 0;
    function<void(int, int)> dfs = [&](int u, int p){
        st[u] = timer++;
        for(int v : adj[u])
            if(v != p)
                dfs(v, u);
        en[u] = timer;
    };
    dfs(0, -1);
    vector<int> fen(n+1, 0);
    auto update = [&](int i, int x){
        for(; i <= n; i += i & -i)
            fen[i] += x;
    };
    auto qry = [&](int i){
        int s = 0;
        for(; i > 0; i -= i & -i)
            s += fen[i];
        return s;   
    };
    for(int i=0; i<n; i++)
        update(st[i]+1, a[i]);
    while(q--){
        int c;
        cin >> c;
        if(c==1){
            int s, x;
            cin >> s >> x;
            --s;
            update(st[s]+1, x - a[s]);
            a[s] = x;
        }
        else{
            int s;
            cin >> s;
            --s;
            int ans = qry(en[s]) - qry(st[s]);
            cout << ans << endl;
        }
    }


}