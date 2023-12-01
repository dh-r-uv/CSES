 #include<bits/stdc++.h>
 #define pb push_back
 #define popb pop_back
 #define popf pop_front
 #define fr(a,b) for(int i = a; i < b; i++)
 #define rep(i,a,b) for(int i = a; i < b; i++)
 #define rev(i,a,b) for(int i = a; i > b; i--)
 #define setpr(x) cout << setprecision(x) fixed
 #define F first
 #define S second
 #define pii pair<int, int>
 #define vii vector<pii>
 #define sz size()
 #define seearr(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
 #define seevec(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
 #define seeset(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}
 #define mod 1e9+7
 #define inf (1LL<<60)
 #define all(x) (x).begin(), (x).end()
 #define prDouble(x) cout << fixed << setprecision(10) << x
 #define triplet pair<ll,pair<ll,ll>>
 #define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
 using namespace std;
 #define ll long long

//define the global variables here

void solve()
{
ll int n;
    cin >> n;
    if(n==1){
        cout << 1;
        return;
    }
    if(n==2||n==3){
        cout << "NO SOLUTION";
        return;
    }
    if(n%2){
        for(int i=n-1; i>0; i-=2) cout << i << " ";
        for(int i=n; i>0; i-=2) cout << i << " ";
    }//2 4 1 3
    else{
        for(int i=2; i<=n; i+=2) cout << i << " ";
        for(int i=1; i<n; i+=2) cout << i << " ";
    }

}
 
int main() {
    fast_io;
    ll t=1;
    //cin >> t;
    while(t--)
    {
       solve();
    }
    return 0;
}