#include<bits/stdc++.h>
#define int long long

using namespace std;



int32_t main(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++)
        cin >> a[i];
    vector<int> adj[n+1];
    for(int i=0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // euler path
    int timer = 1;
    vector<int> st(n+1), en(n+1);
    function<void(int, int)> dfs = [&](int u, int p){
        st[u] = timer++;
        for(auto v: adj[u]){
            if(v == p) continue;
            dfs(v, u);
        }
        en[u] = timer-1;
    };
    dfs(1, 0);
    //bit
    vector<int> bit(timer+3);
    auto update = [&](int i, int x) {
        for(; i <= timer; i += i & -i)
            bit[i] += x;
    };
    auto qry = [&](int i){
        int sm = 0;
        for(; i > 0; i -= i & -i)
            sm += bit[i];
        return sm;
    };
    //bit
    for(int i=1; i<=n; i++){
        update(st[i], a[i]);
        update(en[i]+1, -a[i]);
    }
    // for(auto x: st)
    //     cout << x << ' ';
    // cout << '\n';
    // for(auto x: en)
    //     cout << x << ' ';
    // cout << '\n';
    while(q--){
        int c, s, x;
        cin >> c >> s;
        if(c==1){
            int x;
            cin >> x;
            // update st and en of s
            update(st[s], x - a[s]);
            update(en[s]+1, -x + a[s]);
            a[s] = x;
        }
        else
            cout << qry(st[s]) << '\n';
    }
}