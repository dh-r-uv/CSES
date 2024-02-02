 #include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <functional>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>  ordered_set;

 #define okk order_of_key 

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
 #define vii vector<pii>
 #define vi vector<int>
 #define vvi vector<vi>
 #define vii vector<pii>
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
 #define int long long

template <typename ele_type> ostream& operator<<(ostream& os, const vector<ele_type>& v){
    for (auto itr : v)
        os << itr << " ";
    os << "\n";
    return os;
}

//define the global variables here

void solve()
{
    int n, m;
    cin >> n >> m;
    vi a;
    seevec(a, n);
    int MOD = 1000000007;

    vvi dp(n, vi(m+1, 0));
    if(a[0]==0){
       fr(1, m+1){
        dp[0][i] = 1;
       } 
    }
    else dp[0][a[0]] = 1;

    fr(1, n){
        if(a[i]==0){
            rep(j, 1, m+1){
                dp[i][j]+=dp[i-1][j];
                if(j<m) dp[i][j] += dp[i-1][j+1];
                if(j>1) dp[i][j] += dp[i-1][j-1];
                dp[i][j]%=MOD;
            }
        }
        else{
            dp[i][a[i]] += dp[i-1][a[i]];
            if(a[i]>1)dp[i][a[i]] += dp[i-1][a[i]-1];
            if(a[i]<m) dp[i][a[i]] += dp[i-1][a[i]+1];
            dp[i][a[i]]%=MOD;
        }
    }
    int ans=0;
    if(a[n-1]==0){
        fr(1, m+1) ans= (ans+dp[n-1][i])%MOD;
        cout << ans <<endl;
    }
    else cout << dp[n-1][a[n-1]]%MOD;

}
 
int32_t main() {
    fast_io;
    int t=1;
    //cin >> t;
    while(t--)
    {
       solve();
    }
    return 0;
}