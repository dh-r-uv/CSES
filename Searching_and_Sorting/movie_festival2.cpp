#include<bits/stdc++.h>
 
using namespace std;
#define int long long
 
int32_t main(){
    int n, k;
    cin >> n >> k;
    vector<array<int, 2>> a(n);
    for(auto &x: a) cin >> x[1] >> x[0];
    multiset<int> s;
    sort(a.begin(), a.end());
    int ans = 0;
    for(int i=0; i<k; i++) s.insert(0);
    for(int i=0; i<n; i++){
        auto it = s.upper_bound(a[i][1]);
        if(it==s.begin()) continue;
        -- it;
        ans++;
        s.erase(it);
        s.insert(a[i][0]);
    }
    cout << ans << endl;
}