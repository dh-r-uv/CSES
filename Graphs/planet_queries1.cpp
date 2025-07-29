#include <bits/stdc++.h>
#define int long long
#define inf LLONG_MAX
using namespace std;

const int mxN = 2e5 + 5, mxD = 30;
int_fast16_t par[mxN][mxD];


int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
       cin >> par[i][0]; 
    for(int d = 1; d < mxD; d++)
        for(int i = 1; i <= n; i++)
            par[i][d] = par[par[i][d-1]][d-1];

    auto getKth = [&](int u, int k) -> int {
        for(int d = 0; d < mxD; d++)
            if(k & (1 << d))
                u = par[u][d];
        return u;
    };
    while(q--){
        int u, k;
        cin >> u >> k;
        cout << getKth(u, k) << "\n";
    }

}