#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define pb push_back
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
using namespace std;

int32_t main(){
    // fast io
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    vector<array<int, 2>> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i][0];
        a[i][1] = i+1;
    }
    sort(all(a));
    for(int i=0; i<n; i++){
        int l = 0, r = n-1, cur = x - a[i][0];
        while(l<r){
            if(l==i) l++;
            else if(r==i) r--;
            else{
                if(a[l][0] + a[r][0] == cur){
                    cout << a[i][1] << " " << a[l][1] << " " << a[r][1]<<endl;
                    return 0;
                }
                else if(a[l][0] + a[r][0] < cur) l++;
                else r--;
            }
        }
    }  
    cout << "IMPOSSIBLE"<<endl;
}