#include<bits/stdc++.h>
using namespace std;
//import oredered set
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define int long long
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(auto &i : a) cin >> i;
    int s = 0;
    map<int, int> m;
    m[0]++;
    int ans = 0;
    for(int i = 0; i < n; i++){
        s += a[i];
        if(m.find(s - x) != m.end()){
            ans += m[s - x];
        }
        m[s]++;   
    }
    cout << ans << endl;
}