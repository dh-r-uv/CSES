#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n;
    cin >> n;
    vector<array<int, 2>> a(n);
    for(auto &x: a) cin >> x[0] >> x[1];
    int c = 0, ans = 0;
    sort(a.begin(), a.end());
    for(int i=0; i<n; i++){
        c += a[i][0];
        ans += a[i][1] - c;
    }
    cout << ans << endl;

}