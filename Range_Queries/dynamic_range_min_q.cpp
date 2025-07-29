#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(auto &x: a)
        cin >> x;
    vector<int> seg(2*n + 2, INT_MAX);
    auto upd = [&](int i, int val){
        i += n;
        seg[i] = val;
        i >>= 1;
        while(i>=1){
            seg[i] = min(seg[2*i], seg[2*i + 1]);
            i >>= 1;
        }
    };

    auto qry = [&](int l, int r){
        l += n, r += n;
        int mn = INT_MAX;
        while(l <= r){
            if(l&1) 
                mn = min(mn, seg[l++]);
            if(~r&1)
                mn = min(mn, seg[r--]);
            l >>= 1, r >>= 1;
        }
        return mn;
    };

    for(int i=0; i<n; i++)
        upd(i, a[i]);
    
    while(q--){
        int c;
        cin >> c;
        if(c==1){
            int k, u;
            cin >> k >> u;
            --k;
            upd(k, u);
        }
        else{
            int l, r;
            cin >> l >> r;
            --l, --r;
            cout << qry(l, r) << endl;
        }
    }    
}