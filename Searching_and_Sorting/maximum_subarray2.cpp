#include<bits/stdc++.h>

using namespace std;
#define int long long
#define inf 1e18

int32_t main(){
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> v(n);
    for(auto &x: v) cin >> x;
    vector<int> pre(n+1);
    for(int i=1; i<=n; i++)
        pre[i] = pre[i-1] + v[i-1];
    // ans = pre[i] - (pre[j]) j>=i-b && j<i-a
    multiset<int> s;
    int ans = -inf;
    for(int i=a; i<=n; i++){
        if(i>b) s.erase(s.find(pre[i-b-1]));
        s.insert(pre[i-a]);
        ans = max(ans, pre[i] - *s.begin());
        // cout << ans << " ";
    }
    // cout << endl;
    cout << ans << endl;
}