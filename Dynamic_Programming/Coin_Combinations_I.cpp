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
	int MOD = 1e9+7;
	ll int n, x;
	cin >> n >> x;
	vector<int> c(n);
	fr(0, n) cin >> c[i];
	ll int dp[x+1];
	fr(0, x+1) dp[i] = 0;
	dp[0] = 1;
	rep(i, 1, x+1){
		rep(j, 0, n){
			if(i>=c[j]){
				dp[i] += dp[i-c[j]];
				dp[i]%=MOD;
			}	
		}	
	}
	if(dp[x]!=0) cout << dp[x];
	else cout << 0;
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
