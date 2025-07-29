#include<bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    int ans = 0;
    map<int, int> m;
    m[0]++;
    int s=0;
    for(auto x: a){
        s+=x;
        s%=n;
        s+=n;
        s%=n;
        ans+=m[s];
        m[s]++;
    }
    cout << ans << endl;
}