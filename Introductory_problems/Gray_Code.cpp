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
void binaryarray(int a[], int k, int n){
    if(k==0) return;
    for(int i=0;k>0;i++){    
        a[i]=k%2;    
        k=k/2;    
    }
    reverse(a, a+n);  
}


void solve()
{
    ll int n;
    cin >> n;
    for(ll int i=0; i<pow(2,n); i++){
        int a[n]={0};
        binaryarray(a, i, n);
        cout << a[0];
        for(int j=1; j<n; j++){
            cout << (a[j]^a[j-1]);
        }
        cout <<endl;
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