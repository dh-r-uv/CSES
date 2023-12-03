#include<bits/stdc++.h>
#define pb push_back
#define popb pop_back
#define popf pop_front
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define rev(i,a,b) for(int i = a; i > b; i--)
#define setpr(x) cout << setprecision(x) fixed
#define X first
#define Y second
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
#define ll long long int

//define the global variables here
void solve()
{
    ll n;
    vector<pair<ll, ll>> v;
    cin >> n;
    fr(0, n){
        ll x, y;
        cin >> x >> y;
        v.pb({x, y});
    }
    //shoelace approach
    ll ans =0;
    for (int i = 0; i < n; i ++) {
        ans += (v[i].X*v[(i+1)%n].Y - v[(i+1)%n].X*v[i].Y);
    }
    cout << abs(ans)<<endl;
}

int main() {
    fast_io;
    int t=1;
    //cin >> t;
    while(t--)
    {
    solve();
    }
    return 0;
}
