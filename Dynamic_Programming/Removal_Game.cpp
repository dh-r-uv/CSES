#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++)
        cin >> a[i];
    int s = accumulate(a.begin(), a.end(), 0ll);
    vector<vector<int>> dp(n+1, vector<int>(n+1, -INT_MAX));
    //dp[i][j] = max(v[i] - dp[i+1][j], v[j] - dp[i][j-1]);
    function<int(int, int)> rec = [&](int i, int j){
        if(dp[i][j]!=-INT_MAX)
            return dp[i][j];
        if(i==j)
            return dp[i][j] = a[i];
        return dp[i][j] = max(a[i] - rec(i+1, j), a[j] - rec(i, j-1));   
    };
    cout << (s + rec(1, n))/2 <<endl;
}