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
 
int n;
int MOD = 1e9+7;
const int MAXN = 1000007;
ll int dp[MAXN][2];
 
void solve(){
	cin >> n; 
	cout <<  (dp[n][0] + dp[n][1])%MOD <<endl;
}
 
int main(){
	
	fast_io;
	ll t=1;
	cin >> t;
	dp[0][0] = 0;
	dp[0][1] = 0;
	dp[1][0] = 1;
	dp[1][1] = 1;
	fr(2, MAXN){
		dp[i][0] = (4*dp[i-1][0]% MOD + dp[i-1][1])%MOD;
		dp[i][1] = (dp[i-1][0] + 2*dp[i-1][1]%MOD)%MOD;
	} 
	while(t--)
	{
	   solve();
	}
	return 0;
}