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
    int n;
    cin >> n;
    vector<array<int, 3>> a;
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        a.pb({x, -1, i});
        a.pb({y, 1, i});
    }
    sort(all(a));
    vi ans(n);
    int c=0, k=0;
    for(auto [x, y, i]: a){
        if(y == -1) c++;
        else c--;
        k = max(k, c);
    }
    set<int> rooms;
    for(int i=1; i<=k; i++){
        rooms.insert(i);
    }
    for(auto [x, y, i]: a){
        if(y == -1) ans[i] = *rooms.begin(), rooms.erase(rooms.begin());
        else rooms.insert(ans[i]);
    }
    cout << k << endl;
    for(int i=0; i<n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}