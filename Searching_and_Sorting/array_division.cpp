#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    auto check = [&](int x){
        int c = 0, s = 0;
        for(auto &y: a){
            if(s + y > x){
                c++;
                s=0;
            }
            s += y;
        }
        ++c;
        return c <= k;
    };
    int l = *max_element(a.begin(), a.end()), r = 1e15;
    int ans = r;
    while(l <= r){
        int m = (l+r)/2;
        if(check(m)){
            r=m-1;
            ans = m;
        }   
        else {
            l = m + 1;
        }
    }
    cout << ans << endl;
}