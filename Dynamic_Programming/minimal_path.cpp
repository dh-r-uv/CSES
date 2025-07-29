#include<bits/stdc++.h>

using namespace std;

int32_t main(){
    int n;
    cin >> n;
    vector<string> v(n);
    for(auto &x: v)
        cin >> x;
    if(n==1){
        cout << v[0][0] <<endl;
        return 0;
    }
    vector<array<int, 2>> cur;
    cur.push_back({0, 0});
    vector<vector<array<int, 2>>> par(n, vector<array<int, 2>>(n, {-1, -1}));
    for(int l = 1; l<=2*n-2; l++){
        vector<vector<array<int, 2>>> t(26);
        for(auto [i, j]: cur){
            if(i+1 < n && par[i+1][j][0] == -1){
                t[v[i+1][j] - 'A'].push_back({i+1, j});
                par[i+1][j] = {i, j};
            }
            if(j+1 < n && par[i][j+1][0] == -1){
                t[v[i][j+1] - 'A'].push_back({i, j+1});
                par[i][j+1] = {i, j};
            }
        }
        for(int i=0; i<26; i++){
            if(t[i].empty()) continue;
            cur = t[i];
            break;
        }
    }
    array<int, 2> y = {n-1, n-1};
    string path;
    while(par[y[0]][y[1]][0] != -1){
        path.push_back(v[y[0]][y[1]]);
        y = par[y[0]][y[1]];
    }
    path.push_back(v[0][0]);
    reverse(path.begin(), path.end());
    cout << path << endl;
}