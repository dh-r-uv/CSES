#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
int cnt = 0;
 
bool check(int x,int y, bool visit[8][8]){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(visit[i][j]){
                if(abs(i - x) == abs(j - y)) return false;
                if(i == x || j == y) return false;
            }
        }
    }
    return true;
}
 
void solve(int m, bool board[8][8], bool visit[8][8]){
    if(m == 8){
        cnt++;
        return;
    }
    for(int i=0;i<8;i++){
        if(check(m,i, visit) && board[m][i]){
            visit[m][i] = true;
            solve(m+1, board, visit);
            visit[m][i] = false;
        }
    }
}
 
int main(){
    bool board[8][8], visit[8][8];
    for(int i=0;i<8;i++){
        string s;
        cin >> s;
        for(int j=0;j<8;j++){
            visit[i][j] = false;
            if(s[j] == '.') board[i][j] = true;
            else board[i][j] = false;
        }
    }
    solve(0, board, visit);
    cout<<cnt<<endl;
}