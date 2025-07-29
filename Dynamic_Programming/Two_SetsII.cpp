#include<bits/stdc++.h>
#define int long long 
using namespace std;

const int mod = 1e9+7;

int fastpow(int a, int b){
    int res = 1;
    while(b){
        if(b&1)
            res = (res*a)%mod;
        b /= 2;
        a = (a*a)%mod;
    }
    return res;
}

int32_t main(){
    int n;
    cin >> n;
    int s = n*(n+1)/2;
    if(s&1){
        cout << 0 <<endl;
        return 0;
    }
    s >>= 1;
    vector<int> dp(s+1);
    dp[0] = 1;
    for(int i=1; i<=n; i++)
        for(int sm = s; sm>=i; sm--)
            dp[sm] = (dp[sm] + dp[sm-i])%mod; 

    cout << (dp[s]*fastpow(2, mod-2))%mod <<endl;
    // cout << dp[s]/2 << endl;

}