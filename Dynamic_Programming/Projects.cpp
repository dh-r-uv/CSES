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
//same as max set weighted interval scheduling
int log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

template<class T>
class SegTree {
private:
    const T id = 0;
    vector<T> segtree;
 
public:
    int len;
    SegTree(int l){
        int n = 1 << log2_floor(l);
        if (l != n) {
            n = 1 << (log2_floor(l) + 1);
        }
        len = n;
 
        segtree.resize(len * 2, id);
    }
 
    void update(int ind, T val) {
        ind += len;
        segtree[ind] = val;
        for (; ind > 1; ind /= 2) {
            segtree[ind / 2] = max(segtree[ind], segtree[ind ^ 1]);
        }
    }
    void display() {
        cout << len << segtree.size() << "\n";
    }
    T _query(int node, int nL, int nR, int l, int r) {
        if (l > r) return id;
        if (l == nL && r == nR) {
 
            return segtree[node];
        }
        int m = (nL + nR) / 2;
        return max(_query(node * 2, nL, m, l, min(r, m)), _query(node * 2 + 1, m + 1, nR, max(l, m + 1), r));
    }
    T query(int l, int r) {
        return _query(1, 0, len - 1, l, r);
    }
 
};


void solve()
{
    int n;
    cin>>n;
    vvi v(n,vi(3));
    fr(0,n){
        cin>>v[i][0]>>v[i][1]>>v[i][2];
    }
    //compressing the array
    vi temp;
    sort(all(v), [](vi &a, vi &b){
        return a[1] < b[1];
    });
    fr(0,n){
        temp.pb(v[i][0]);
        temp.pb(v[i][1]);
    }
    sort(all(temp));
    temp.resize(unique(all(temp)) - temp.begin());
    fr(0,n){
        v[i][0] = lower_bound(all(temp), v[i][0]) - temp.begin();
        v[i][1] = lower_bound(all(temp), v[i][1]) - temp.begin();
    }
    //end of compressing the array
    vi dp(n,0);
    
    SegTree<int> st(2*n+1);
    rep(i, 0, n){
        dp[i] = v[i][2] + st.query(0, v[i][0]-1);
        if(st.query(v[i][1], v[i][1])<dp[i]) st.update(v[i][1], dp[i]);
    }
    // fr(0, n) cout << v[i][0] << " "<<v[i][1] << " "<<v[i][2] << "\n";
    // fr(0, n) cout << dp[i] << " ";
    // cout <<endl;
    cout << *max_element(all(dp)) << "\n";
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