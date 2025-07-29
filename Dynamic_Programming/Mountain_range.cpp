#include<bits/stdc++.h>
#define int long long
using namespace std;


int32_t main(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++)
        cin >> a[i];
    vector<int> nxg(n+2, n+1),prevg(n+2, 0);
    stack<int> st;
    for(int i=0; i<n; i++){
        while(!st.empty() && a[st.top()] < a[i]){
            nxg[st.top()] = i;
            st.pop();
        }
    }
    stack<int> st;
    for(int i=1; i<=n; i++){
        while(!st.empty() && a[st.top()] < a[i]){
            nxg[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        nxg[st.top()] = n+1;
        st.pop();
    }
    for(int i=n; i>=1; i--){
        while(!st.empty() && a[st.top()] < a[i]){
            prevg[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        prevg[st.top()] = 0;
        st.pop();
    }
    vector<int> dp(n+2, 0);
    vector<array<int, 2>> v;
    for(int i=1; i<=n; i++){
        v.push_back({a[i], i});
    }
    sort(v.begin(), v.end(), greater<array<int, 2>>());
    for(auto [x, i]: v){
        int l = prevg[i], r = nxg[i];
        dp[i] = max(dp[l] + 1, dp[r] + 1);
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
}