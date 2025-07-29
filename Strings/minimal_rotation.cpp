#include<bits/stdc++.h>

using namespace std;

vector<int> z_func(string s){
    int n = s.size();
    int l = 0, r = 0;
    vector<int> z(n);
    z[0] = n;
    for(int i=1; i<n; i++){
        z[i] = max(0, min(z[i] + i, r - i + 1));
        while(i + z[i] < n && s[z[i]] >= s[i + z[i]]){
            l = i;
            r = i + z[i];
            z[i]++;
        }
    }
    return z;
}

int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> z = z_func(s);
    for(auto x: z)
        cout << x << ' ';
    cout <<endl;

}