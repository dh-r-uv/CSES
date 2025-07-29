#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n, w;
    cin >> n >> w;
    vector<int> a(n);
    for(auto &x: a)
        cin >> x;
    vector<array<int, 2>> dp(1<<n); //elv cnt and weightoflast
    dp[0] = {1, 0};
    for(int mask = 1; mask < (1<<n); mask++){
        dp[mask] = {21, 0};
        for(int i=0; i<n; i++){
            if(mask & (1<<i)){
                auto [r, wt] = dp[mask^(1<<i)];
                if(wt + a[i] > w){
                    r++;
                    wt = min(a[i], wt);
                }
                else    
                    wt += a[i];
                dp[mask] = min(dp[mask], {r, wt});
            }
        }
    }
    cout << dp[(1<<n) - 1][0] <<endl;
    
    
}