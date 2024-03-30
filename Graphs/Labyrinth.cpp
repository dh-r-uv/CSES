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
 #define seevec(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
 #define inf (1LL<<60)
 #define all(x) (x).begin(), (x).end()
 #define prDouble(x) cout << fixed << setprecision(10) << x
 #define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 using namespace std;
 #define int long long
 #define ll long long
 #define endl '\n'
 const int MOD = 1e9+7;

mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

/*debug start*/
 void __print32_t(int32_t x) {cerr << x;}
void __print32_t(long x) {cerr << x;}
void __print32_t(long long x) {cerr << x;}
void __print32_t(unsigned x) {cerr << x;}
void __print32_t(unsigned long x) {cerr << x;}
void __print32_t(unsigned long long x) {cerr << x;}
void __print32_t(float x) {cerr << x;}
void __print32_t(double x) {cerr << x;}
void __print32_t(long double x) {cerr << x;}
void __print32_t(char x) {cerr << '\'' << x << '\'';}
void __print32_t(const char *x) {cerr << '\"' << x << '\"';}
void __print32_t(const string &x) {cerr << '\"' << x << '\"';}
void __print32_t(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print32_t(const pair<T, V> &x) {cerr << '{'; __print32_t(x.first); cerr << ','; __print32_t(x.second); cerr << '}';}
template<typename T>
void __print32_t(const T &x) {int32_t f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print32_t(i); cerr << "}";}
void _print32_t() {cerr << "]\n";}
template <typename T, typename... V>
void _print32_t(T t, V... v) {__print32_t(t); if (sizeof...(v)) cerr << ", "; _print32_t(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print32_t(x)
#else
#define debug(x...)
#endif
 /*debug end*/

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

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for(auto &x: a) cin >> x;
    vvi vis(n, vi(m, 0));
    pii st, en;
    rep(i, 0, n){
        rep(j, 0, m){
            char c = a[i][j];
            if(c == '#') vis[i][j] = 1;
            if(c == 'A') st = {i, j};
            if(c == 'B') en = {i, j};
        }
    }
    vector<vii> p(n, vii(m, {-1, -1}));
    queue<pair<pii, int>> q;
    q.push({st, 0});
    vis[st.F][st.S] = 1;
    while(!q.empty()){
        auto [cur, d] = q.front();
        q.pop();

        if(cur == en){  //backtrack the string
            cout << "YES" << endl;
            string ans;
            while(cur != st){
                auto [x, y] = p[cur.F][cur.S];
                if(x == cur.F){
                    if(y == cur.S+1) ans += 'L';
                    else ans += 'R';
                }
                else{
                    if(x == cur.F+1) ans += 'U';
                    else ans += 'D';
                }
                cur = {x, y};
            }
            reverse(all(ans));
            cout << ans.size() << endl;
            cout << ans << endl;
            return;
        }
        
        int x = cur.F, y = cur.S;
        if(x > 0 && !vis[x-1][y]){
            vis[x-1][y] = 1;
            p[x-1][y] = {x, y};
            q.push({{x-1, y}, d+1});
        }
        if(x < n-1 && !vis[x+1][y]){
            vis[x+1][y] = 1;
            p[x+1][y] = {x, y};
            q.push({{x+1, y}, d+1});
        }
        if(y > 0 && !vis[x][y-1]){
            vis[x][y-1] = 1;
            p[x][y-1] = {x, y};
            q.push({{x, y-1}, d+1});
        }
        if(y < m-1 && !vis[x][y+1]){
            vis[x][y+1] = 1;
            p[x][y+1] = {x, y};
            q.push({{x, y+1}, d+1});
        }
    }
    cout << "NO"<<endl;
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