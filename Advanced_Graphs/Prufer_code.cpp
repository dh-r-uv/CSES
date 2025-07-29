#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n;
    cin >> n;
    vector<int> prufer(n-2);
    for(int i=0; i<n-2; i++)
        cin >> prufer[i];
    vector<int> deg(n+1, 1);
    for(auto x: prufer)
        deg[x]++;
    set<int> leafs;
    for(int i=1; i<=n; i++)
        if(deg[i]==1)
            leafs.insert(i);
    vector<array<int, 2>> edges;
    for(auto x: prufer){
        int u = *leafs.begin();
        leafs.erase(leafs.begin());
        edges.push_back({u, x});
        deg[x]--;
        if(deg[x]==1)
            leafs.insert(x);
    }
    edges.push_back({*leafs.begin(), n});
    for(auto [u, v]: edges)
        cout << u << ' ' << v << '\n';
}