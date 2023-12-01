 #include<bits/stdc++.h>
 #define pb push_back
 #define popb pop_back
 #define popf pop_front
 #define fr(a,b) for(int i = a; i < b; i++)
 #define rep(i,a,b) for(int i = a; i < b; i++)
 #define rev(i,a,b) for(int i = a; i > b; i--)
 #define setpr(x) cout << setprecision(x) fixed
 #define F first
 #define S second
 #define pii pair<int, int>
 #define vii <vector<pii>>
 #define sz size()
 #define seearr(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
 #define seevec(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
 #define seeset(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}
 #define mod 1e9+7
 #define inf (1LL<<60)
 #define all(x) (x).begin(), (x).end()
 #define prDouble(x) cout << fixed << setprecision(10) << x
 #define triplet pair<ll,pair<ll,ll>>
 #define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
 using namespace std;
 #define ll long long
 
//define the global variables here
 
void solve()
{
    int n, x;
    cin >> n>>x;
    vector<int> h(n), s(n);
    fr(0, n) cin >> h[i];
    fr(0, n) cin >> s[i];
    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
    // int dp[n+1][x+1];
    // fr(0, n+1){
    //     rep(j, 0, x+1) dp[i][j] = 0;
    // }
 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            dp[i][j]=dp[i-1][j];
            if(j-h[i-1]>=0)
                dp[i][j]=max(dp[i][j],dp[i-1][j-h[i-1]]+s[i-1]);
        }
    }
 
    cout << dp[n][x]<<endl;
}
 
int main() {
    fast_io;
    ll t=1;
    //cin >> t;
    while(t--)
    {
       solve();
    }
    return 0;
}