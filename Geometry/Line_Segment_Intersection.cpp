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
    pair<ll, ll> p1, p2, p3, p4;
    cin >> p1.F >> p1.S;
    cin >> p2.F >> p2.S;
    cin >> p3.F >> p3.S ;
    cin >> p4.F >> p4.S;
    //if the lines are parallel
    if((p2.S-p1.S)*(p4.F-p3.F)==(p4.S-p3.S)*(p2.F-p1.F)){
        //coincidental
        if((p2.S-p1.S)*(p3.F-p2.F)==(p3.S-p2.S)*(p2.F-p1.F)){
            ll x_min1 = min(p1.F, p2.F);
            ll x_max1 = max(p1.F, p2.F);
            ll x_min2 = min(p3.F, p4.F);
            ll x_max2 = max(p3.F, p4.F);

            ll y_min1 = min(p1.S, p2.S);
            ll y_max1 = max(p1.S, p2.S);
            ll y_min2 = min(p3.S, p4.S);
            ll y_max2 = max(p3.S, p4.S);

            if(x_min1>x_max2 || x_min2>x_max1) cout << "NO"<<endl;
            
            else if(y_min1>y_max2 || y_min2>y_max1) cout << "NO"<<endl;

            else cout << "YES" <<endl;
        }
        //not coincidental
        else cout << "NO"<<endl;
    }
    //not parallel
    else{

        ll s1 = (p1.S-p2.S)*(p1.F-p3.F) - (p1.F-p2.F)*(p1.S-p3.S);
        ll s2 = (p1.S-p2.S)*(p1.F-p4.F) - (p1.F-p2.F)*(p1.S-p4.S);
        if((s1>0 && s2>0) || (s1<0 && s2<0)){
            cout << "NO"<<endl;
            return;
        }

        s1 = (p3.S-p4.S)*(p3.F-p1.F) - (p3.F-p4.F)*(p3.S-p1.S);
        s2 = (p3.S-p4.S)*(p3.F-p2.F) - (p3.F-p4.F)*(p3.S-p2.S);
        if((s1>0 && s2>0) || (s1<0 && s2<0)){
            cout << "NO"<<endl;
            return;
        }

        cout << "YES"<<endl;    

    }
}
 
int main(){
    fast_io;
    ll t;
    cin >> t;
    while(t--)
    {
       solve();
    }
    return 0;
}