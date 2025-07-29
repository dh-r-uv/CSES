#include<bits/stdc++.h>
using namespace std;

vector<int> prefix(string s){
  int n = s.size();
  vector<int> p(n, 0);
  for(int i = 1; i < n; i++){
    int j = p[i-1];
    while(j > 0 && s[i] != s[j]) j = p[j-1];
    if(s[i] == s[j]) j++;
    p[i] = j;
  }
  return p;
}

int32_t main()
{
  string s, t;
  cin >> s >> t;
  string ss = t + "#" + s;
  vector<int> p = prefix(ss);
  int ans = 0;
  for(int i = t.size() + 1; i < ss.size(); i++){
    if(p[i] == t.size())
      ans++;
  }
  cout << ans << endl;
}
 