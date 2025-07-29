#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++)
        cin >> a[i];
    vector<int> bit(n+1);
    auto upd = [&](int i, int val){
        for(; i <= n; i += i & -i)
            bit[i] += val;
    };
    auto qrysm = [&](int i){
        int sm = 0;
        for(; i > 0; i -= i & -i)
            sm += bit[i];
        return sm;
    };
    auto qry = [&](int l, int r){
        return qrysm(r) - qrysm(l-1);
    };
    for(int i=1; i<=n; i++)
        upd(i, a[i]);
    while(q--){
        int c;
        cin >> c;
        if(c==1){
            int k, u;
            cin >> k >> u;
            upd(k, u - a[k]);
            a[k] = u;
        }
        else{
            int l, r;
            cin >> l >> r;
            cout << qry(l, r) << endl;
        }
    }
}