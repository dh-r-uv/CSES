#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n;
    cin >> n;
    vector<int> vis(1e5+7);
    int s = 0;
    vis[0] = 1;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        set<int> have;
        for(int j=0; j<=s; j++){
            if(vis[j])
                have.insert(j + x);
        }
        s += x;
        for(auto y: have)
            vis[y] = 1;
    }
    vector<int> v;
    for(int i=1; i<=s; i++)
        if(vis[i])
            v.push_back(i);
    cout << v.size() <<endl;
    for(auto x: v)
        cout << x << " ";
    cout <<endl;
}