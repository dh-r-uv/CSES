#include<bits/stdc++.h>
#define int long long 
using namespace std;

int32_t main(){
    int n, x;
    cin >> n >> x;
    vector<int> h(n+1), s(n+1);
    for(int i=1; i<=n; i++)
        cin >> h[i];
    for(int i=1; i<=n; i++)
        cin >> s[i];
    vector<int> dp(x+1);
    for(int i=1; i<=n; i++)
        for(int k=x; k>0; k--)
            if(k - h[i]>=0)
                dp[k] = max(dp[k], dp[k - h[i]] + s[i]);     
    
    cout << *max_element(dp.begin(), dp.end());
}
