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
const ll N=1e5+5;
const ll lg=log2(N+2);
ll T[N][lg+1];
vector<ll>adj[N];
ll n,root,level[N];

void dfs(ll node)
{
    for(auto xx:adj[node])
    {
        if(T[xx][0]==-1)
        {
            T[xx][0]=node;
            level[xx]=level[node]+1;
            dfs(xx);
        }
    }
}

void build()
{
  memset(T,-1,sizeof(T));
  level[root]=0;
  dfs(root);
  ll lg1=log2(n+2);
  for(int j=1;j<=lg1;j++)
  {
    for(ll i=1;i<=n;i++)
    {
        ll xx=T[i][j-1];
        if(xx!=-1)
        {
            T[i][j]=T[xx][j-1];
        }
    }
  }

}

ll kthParent(ll u,ll k)
{
    if(k>n) return -1;
    ll lg1=log2(k)+1;
    for(ll i=lg1;i>=0;i--)
    {
        if(u==-1)
        {
            return -1;
        }
        if((1<<i)<=k)
        {
            k-=(1<<i);
            u=T[u][i];
        }
    }

    return u; 
}

ll lca(ll u,ll v)
{
    if(level[u]<level[v]) swap(u,v);
    ll lg1=log2(level[u]+2);
    for(ll i=lg1;i>=0;i--)
    {
       if(T[u][i]!=-1 and (level[u]-(1<<i))>=level[v])
       {
         u=T[u][i];
       }
    }

    if(u==v) return u;

    lg1=log2(n+2);
    for(int i=lg1;i>=0;i--)
    {
         if(T[u][i]!=-1 and T[u][i]!=T[v][i])
         {
            u=T[u][i];
            v=T[v][i]; 
         }
    }


    return T[u][0];
 
}

void solve(int cas)
{
    cin>>n>>root;
    build();
   
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