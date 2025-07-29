#include<bits/stdc++.h>

using namespace std;
#define int long long
#define inf 1e18
#define mod 1000000007ll


int32_t main(){
    int n, m;
    cin >> n >> m;
    vector<array<int, 2>> ed(m);
    for(auto &x: ed){
        cin >> x[0] >> x[1];
        x[0]--; x[1]--;
    }
    vector<int> par(n, -1), sz(n, 1);
    for(int i=0; i<n; i++)
        par[i] = i;
    function<int(int)> find = [&](int u){
        if(par[u]==u) return u;
        return par[u] = find(par[u]);
    };
    int comp = n, mx  = 1;
    function<void(int, int)> merge = [&](int u, int v){
        u = find(u), v = find(v);
        if(u == v) return;
        if(sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        comp--;
        mx = max(mx, sz[u]);
    };
    for(auto [u, v] : ed){
        merge(u, v);
        cout << comp << " " << mx << endl;
    }

}