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
ll int dp[1000][1000];
int n;
int MOD = 1e9+7;
 
void solve(){
	cin >> n;
	vector<string> g(n);
	fr(0, n) cin >> g[i];
	fr(0, n){
		rep(j, 0, n) dp[i][j] = 0;
	}
	if(g[0][0]=='.') dp[0][0] = 1;
	rep(i, 0, n){
		rep(j, 0, n){
			if(g[i][j]=='.'){
				if(i>0) dp[i][j]+=dp[i-1][j];
				if(j>0) dp[i][j]+=dp[i][j-1];
			}
			dp[i][j]%=MOD;
		}
	}
	cout << dp[n-1][n-1]%MOD;
}
 
int main(){
	
	fast_io;
	ll t=1;
	//cin >> t;
	while(t--)
	{
	   solve();
	}
	return 0;
}
