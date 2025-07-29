#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1), b(m+1);
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int j=1; j<=m; j++) cin >> b[j];
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0)); // length of LCS
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
            dp[i][j] = max(dp[i][j], dp[i-1][j-1] + (a[i] == b[j])); 
        }
    }
    // backtrack to find the lcs
    vector<int> lcs;
    int i = n, j = m;
    while(i>0 && j>0){
        if(a[i]==b[j]){
            lcs.push_back(a[i]);
            --i; --j;
        }
        else if(dp[i-1][j] > dp[i][j-1]) --i;
        else --j;
    }
    reverse(lcs.begin(), lcs.end());
    cout << lcs.size() << endl;
    for(int x : lcs) cout << x << " ";
    cout << endl;

}