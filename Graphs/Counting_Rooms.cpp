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
 #define inf (1LL<<60)
 #define all(x) (x).begin(), (x).end()
 #define prDouble(x) cout << fixed << setprecision(10) << x
 #define triplet pair<ll,pair<ll,ll>>
 #define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
 using namespace std;
 #define int long long
 #define ll long long
 const int MOD = 1e9+7;

mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

template <typename ele_type> ostream& operator<<(ostream& os, const vector<ele_type>& v){
    for (auto itr : v)
        os << itr << " ";
    os << "\n";
    return os;
}

int fastpow(int a, int b){
    int ans = 1;
    while(b){
        if (b&1) ans = (ans*a) % MOD;
        b /= 2; a = (a*a) % MOD;
    }
    return ans;
}

//define the global variables here
const int N = 1007;
vector<string> v(N);
vvi vis(N, vi(N, 0));
int n, m;


string dfs(int i, int j, string s){
    if(i < 0 || j < 0 || i >= n || j >= m || v[i][j] == '#' || vis[i][j]) return "blah";
    if(v[i][j] == 'B') return s;
    vis[i][j] = 1;
    string ret = dfs(i+1, j, s+ "D");
    if(ret!="blah") return ret;
    string ret = dfs(i-1, j, s+ "U");
    if(ret!="blah") return ret;
    string ret = dfs(i, j+1, s+ "R");
    if(ret!="blah") return ret;
    string ret = dfs(i, j-1, s+ "L");
    if(ret!="blah") return ret;
}

void solve()
{
    cin >> n >>m;
    fr(0, n) cin >> v[i];
    int cnt=0;
    fr(0, n){
        rep(j, 0, m){
            if(!vis[i][j] && v[i][j] == 'A'){
                cout << dfs(i, j, "") << endl;
                return;
            }
        }
    }
    cout << cnt << endl;
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