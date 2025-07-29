#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1e18
#define mod 1000000007ll

using namespace std;

int32_t main(){
    int n, m;
    cin >> m >> n;
    vector<int> adj[2*n+1];
    //2 sat solve
    for(int i=0; i<m; i++){
        char c1, c2;
        int x1, x2;
        cin >> c1 >> x1;
        if(c1=='-') x1 += n;
        cin >> c2 >> x2;
        if(c2=='-') x2 += n; 

    }
}