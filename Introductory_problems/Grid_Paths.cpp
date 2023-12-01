#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
 
bool visited[7][7];
string path;
int answer = 0;
 
bool check(int i, int j) {
 
    if (i < 7 && j < 7 && i >= 0 && j >= 0 && ! visited[i][j]) {
        return true;
    }
    return false;
}
 
 
//backtracking
void dfs(int x, int y, int a) {
 
    if (x == 6 && y == 0) {
        if (a == 48) {
            answer++;
        }
        return;
    }
 
    visited[x][y] = true;
 
    // go up
    if ((path[a] == 'U' || path[a] == '?')) {   //moving up or no position is given
        if (x > 0 && check(x - 1, y)) {
            if (!(!check(x - 2, y) && check(x - 1, y - 1) && check(x - 1, y + 1)) || (x - 1 == 6 && y == 0)) {
                dfs(x - 1, y, a + 1);
            }
        }
    }
 
    if (path[a] == 'D' || path[a] == '?') {    //moving down or no position is given
        if (x < 6 && check(x + 1, y)) {
            if (!(!check(x + 2, y) && check(x + 1, y - 1) && check(x + 1, y + 1))) {
                dfs(x + 1, y, a + 1);
            }
        }
    }
 
    if (path[a] == 'L' || path[a] == '?') {     //moving left or no position is given
        if (y > 0 && check(x, y - 1)) {
            if (!(!check(x, y - 2) && check(x - 1, y - 1) && check(x + 1, y - 1))) {
                dfs(x, y - 1, a + 1);
            }
        }
    }
 
    if (path[a] == 'R' || path[a] == '?') {     //moving right or no position is given
        if (y < 6 && check(x, y + 1)) {
            if (!(!check(x, y + 2)  && check(x - 1, y + 1) && check(x + 1, y + 1))) {
                dfs(x, y + 1, a + 1);
            }
        }
    }
 
    visited[x][y] = false;  //setting the visited back to not visited
 
    return;
}
 
int main() {
    cin >> path;
    dfs(0, 0, 0);
    cout << answer;
}