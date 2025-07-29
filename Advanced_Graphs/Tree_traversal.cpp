#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n;
    cin >> n;
    vector<int> pre(n+1), in(n+1), post(n+1);
    for(int i=1; i<=n; i++)
        cin >> pre[i];
    for(int i=1; i<=n; i++)
        cin >> in[i];
    
    //find post order from pre and in order
    function<void(int, int, int, int)> dfs = [&](int pre_l, int in_l, int in_r, int post_l){
        if(pre_l > n || in_l > in_r) return;
        post[post_l] = pre[pre_l];
        int root = pre[pre_l];
        int root_in = find(in.begin() + in_l, in.begin() + in_r + 1, root) - in.begin();
        int left_size = root_in - in_l;
        dfs(pre_l + 1, in_l, root_in - 1, post_l + 1);
        dfs(pre_l + left_size + 1, root_in + 1, in_r, post_l + left_size + 1);
    };
    dfs(1, 1, n, 1);
    for(int i=1; i<=n; i++)
        cout << post[i] << ' ';
    cout << '\n';
}