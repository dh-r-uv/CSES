#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9+7;

int32_t main(){
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for(auto &x: v)
        cin >> x;
    vector<int> dp(m+1), ndp(m+1);
    if(v[0])
        dp[v[0]] = 1;
    else
        for(int k=1; k<=m; k++)
            dp[k] = 1;
    for(int i=1; i<n; i++){
        ndp.clear();
        ndp.resize(m+1);
        if(v[i]!=0){
            ndp[v[i]] = dp[v[i]];
            if(v[i] - 1>=1)
                ndp[v[i]] += dp[v[i] - 1];
            if(v[i] + 1<=m) 
                ndp[v[i]] += dp[v[i] + 1];
            ndp[v[i]] %= mod;
        }
        else{
            for(int k=1; k<=m; k++){
                ndp[k] = dp[k];
                if(k-1>=0)
                    ndp[k] += dp[k-1];
                if(k+1<=m)
                    ndp[k] += dp[k+1];
                ndp[k] %= mod;
            }
        }
        dp = ndp;
    }
    if(v[n-1])
        cout << dp[v[n-1]] << endl;
    else{
        int s = 0;
        for(int k=1; k<=m; k++)
            s = (s + dp[k])%mod;
        cout << s <<endl;
    }

}