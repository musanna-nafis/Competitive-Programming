#include<bits/stdc++.h>
typedef long long int   ll;
typedef long int   l;
typedef long double     ld;

#define pii pair<string,long long int>
#define pii1 pair<char,long long int>
#define intmax  INT_MAX
#define endl        "\n"
#define Endl        "\n"
#define no          cout<<"NO"<<endl;
#define yes         cout<<"YES"<<endl;
#define READ(x)     freopen(x,"r",stdin)
#define WRITE(x)    freopen(x,"w",stdout)
#define sl(x) scanf("%lld", &x)
#define pl(x) printf("%lld", x)
#define BOOST       ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fraction() cout.unsetf(ios::floatfield);cout.precision(10);cout.setf(ios::fixed,ios::floatfield);
// for(auto i:v)
#define mem(a,b)            memset(a,b,sizeof(a))
#define pb                  push_back
#define gcd(a, b)           __gcd(a, b)
#define lcm(a, b)           ((a*b)/(gcd(a,b)))
#define pow(a, b)           (ll)(pow(a,b)+1e-9)
#define vsorti(v)           sort(v.begin(),v.end())
#define vsortd(v)           sort(v.begin(), v.end(), greater<ll>());
#define asorti(a,n)         sort(a+1,a+1+n);
#define asortd(a,n)         sort(a+1,a+1+n, greater<ll>());


#define fo(i,aa,n)          for(ll i=aa;i<=n;i++)
#define foo(i,aa,bb)        for(ll i=aa;i>=bb;i--)
#define fo1(n)              for(int i=0;i<n;i++)
#define fov(v)              for(int i=0;i<v.size();i++)
#define fos(s)              for(int i=0;i<s.size();i++)


using namespace std;


///////////////////////////////////////////////////////////////////CODE///////////////////////////////////////////////////////////////////////////////
const int N=2e5+10;
const int lg=log2(N+2)+2;
ll sparce[N][lg];
ll a[N+1];
ll n;

void build()
{
    memset(sparce,0,sizeof(sparce));
    fo(i,1,n-1)
    {
      sparce[i][0]=a[i]+a[i+1];
    }

    ll lg1=log2(n+2);
    
    fo(j,1,lg1)
    {
        fo(i,1,n)
        {
            ll xx=i+(1<<j-1);
            if(xx<n)
            {
                sparce[i][j]=(sparce[i][j-1]+sparce[xx][j-1])-a[xx];
            }
        }
    }

}
ll query(ll u,ll lagbe,ll v)
{
    ll lg1=log2(lagbe+2);
    ll sum=0;
    for(ll i=lg1;i>=0;i--)
    {
      if((u+(1<<i))<=v)
      {
        sum+=sparce[u][i];
        u=u+(1<<i);
        lagbe-=(1<<i);
        if(lagbe>0)
        {
            sum-=a[u];
        }
      }
    }

    return sum;
}
void solve(int cas)
{
    ll q,x,y;
    cin>>n>>q;
    fo(i,1,n)
    {
        cin>>a[i];
    }
    build();
    while(q--)
    {
        cin>>x>>y;
        if(x==y) cout<<a[x]<<endl;
        else
        {
          ll lagbe=y-x;
          cout<<query(x,lagbe,y)<<endl;
        }
    }
   
}


int main()
{


    int tt=1;
    fo(i,1,tt)
    {
       solve(i);
    }

    return 0;
}
