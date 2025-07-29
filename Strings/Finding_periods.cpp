#include<bits/stdc++.h>
#define int long long
using namespace std;


vector<int> z_func(string s){
    int n = s.size();
    vector<int> z(n, 0);
    z[0] = n;
    // made Zl = r-l+1 then if i + z[i-l] < r then zi = z[l-i], otherwise expand
    int l = 0, r = 0;
    for(int i=1; i<n; i++){
        z[i] = max(0ll, min(z[i-l], r-i+1));
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]){
            l = i;
            r = i + z[i];
            z[i]++;
        }
    }
    return z;
}


int32_t main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> z = z_func(s);
    for(int i=1; i<n; i++)
        if(z[i] + i == n)
            cout << i << " ";
    cout << n << endl;
}