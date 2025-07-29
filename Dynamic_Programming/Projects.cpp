#include<bits/stdc++.h>
#define int long long 
using namespace std;

int32_t main(){
    int n;
    cin >> n;
    vector<array<int, 3>> proj(n);
    for(auto &[en, st, rew]: proj)
        cin >> st >> en >> rew;
    sort(proj.begin(), proj.end());
    vector<int> dp(n+1);
    // for(auto [en, st, rew]: proj){
    //     cout << st <<" "<<en << " "<<rew <<endl;
    // }
    for(int i=1; i<=n; i++){
        auto [en, st, rew] = proj[i-1];
        array<int, 3> m = {st, 0, 0};
        int l = lower_bound(proj.begin(), proj.end(), m) - proj.begin();
        dp[i] = max(dp[i-1], rew + dp[l]);
    }
    cout << dp[n] <<endl;
}
