#include<bits/stdc++.h>
#define int long long
using namespace std;

int MOD = 1e9 + 7;

int32_t main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x: a)
        cin >> x;
    // compress the values
    vector<int> b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    for(int i=0; i<n; i++)
        a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
    
    //bit
    vector<int> bit(n+1, 0);
    auto update = [&](int i, int x) {
        for(; i <= n; i += i & -i)
            bit[i] = (bit[i] + x + MOD) % MOD;
    };
    auto qry = [&](int i){
        int sm = 0;
        for(; i > 0; i -= i & -i)
            sm = (sm + bit[i] + MOD) % MOD;
        return sm;
    };
    //bit
    int ans = 0;
    for(int i=0; i<n; i++){
        int val = qry(a[i]-1)+1;
        update(a[i], val);
        ans += val;
        ans %= MOD;
    }
    cout << ans << endl;
}