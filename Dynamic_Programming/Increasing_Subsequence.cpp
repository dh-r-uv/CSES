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
//max segtree
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

//solution differs from the solution on cp algorithms
//for reference
int lis(vector<int> const& a) {
    int n = a.size();
    const int INF = 1e9;
    vector<int> d(n+1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++) {
        int l = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[l-1] < a[i] && a[i] < d[l])
            d[l] = a[i];
    }

    int ans = 0;
    for (int l = 0; l <= n; l++) {
        if (d[l] < INF)
            ans = l;
    }
    return ans;
}
//just used a compressed seg tree 
void solve()
{
    int n;
    vi a;
    cin >> n;
    seevec(a,n);
    vi dp(n,1);
    //compressing the array a;
    vi b = a;
    sort(all(b));
    b.resize(unique(all(b)) - b.begin());
    rep(i, 0, n){
        a[i] = lower_bound(all(b), a[i]) - b.begin();
    }
    SegTree<int> st(n+1);
    rep(i, 0, n)
    {
        dp[i] = st.query(0, a[i]-1) + 1;
        st.update(a[i], dp[i]);
    }
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