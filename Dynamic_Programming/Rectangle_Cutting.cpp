#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a+1, vector<int>(b+1, INT_MAX));
    // function<int(int, int)> rec = [&](int x, int y){
    //     if(dp[x][y]!=-1)
    //         return dp[x][y];
    //     if(x==y)
    //         return dp[x][y] = 0ll;
    //     int ans = INT_MAX;
    //     for(int i=1; i<x; i++)
    //         ans = min(ans, rec(i, y) + rec(x - i, y) + 1);
    //     for(int j=1; j<y; j++)
    //         ans = min(ans, rec(x, j) + rec(x, y - j) + 1);
    //     return dp[x][y] = ans;
    // };
    for(int i=1; i<=a; i++){
        for(int j=1; j<=b; j++){
            if(i==j){
                dp[i][j] = 0;
                continue;
            }
            for(int k=1; k<j; k++)
                dp[i][j] = min(dp[i][j], 1 + dp[i][j-k] + dp[i][k]);
            for(int k=1; k<i; k++)
                dp[i][j] = min(dp[i][j], 1 + dp[i-k][j] + dp[k][j]);
        }
    }
    // cout << rec(a, b);
    cout << dp[a][b]<<endl;
}
