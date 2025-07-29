#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++)
        cin >> a[i];
    vector<int> bit(n+1, 0);
    auto upd = [&](int i, int val){
        for(; i<=n; i+=(i&-i))
            bit[i] ^= val;
    };
    auto qryxor = [&](int i){
        int res = 0;
        for(; i>0; i-=(i&-i))
            res ^= bit[i];
        return res;
    };  
    auto qry = [&](int l, int r){
        return qryxor(r) ^ qryxor(l-1);
    };
    for(int i=1; i<=n; i++)
        upd(i, a[i]);
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << qry(l, r) << endl;
    }
}
