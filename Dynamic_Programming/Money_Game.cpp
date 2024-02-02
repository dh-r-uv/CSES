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
    int n;
    cin >> n;
    vi a;
    seevec(a, n);
    //atmost 1e7
    vi vis(1e5+7, 0);
    
    int s = 0;
    int cnt=0;
    set<int> x;
    fr(0, n){
        x.insert(a[i]);
        rep(j, 1, s+1){
            if(vis[j]){
                x.insert(a[i]+j);
            }
        }
        for(auto it:x) vis[it] = 1;
        s+=a[i];
    }
    cout << x.size()<<endl;
    for(auto it:x) cout << it << " ";
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