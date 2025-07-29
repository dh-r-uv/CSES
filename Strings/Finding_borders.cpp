#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<int> prefix(string s, int n){
    vector<int> pi(n, 0);
    for(int i=1; i<n; i++){
        int j = pi[i-1];
        while(j>0 && s[i] != s[j])
            j = pi[j-1];
        if(s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int32_t main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> pi = prefix(s, n);
    vector<int> ans;
    int x = pi[n-1];
    while(x > 0){
        ans.push_back(x);
        x = pi[x-1];
    }
    sort(ans.begin(), ans.end());
    for(auto x: ans)
        cout << x << ' ';
    cout << '\n';
}