#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n;
    cin >> n;
    vector<int> lis;
    int x;
    for(int i=0; i<n; i++){
        cin >> x;
        auto it = lower_bound(lis.begin(), lis.end(), x);
        if(it==lis.end())
            lis.push_back(x);
        else 
            lis[(it - lis.begin())] = x;
    }
    cout  << lis.size() <<endl;
}