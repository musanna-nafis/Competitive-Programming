#include<bits/stdc++.h>
typedef long long int   ll;
typedef long int   l;
typedef long double     ld;

#define pii pair<long long int,long long int>
#define pii1 pair<char,long long int>
#define intmax  INT_MAX
#define endl        "\n"
#define Endl        "\n"
#define yes         cout<<"YES";
#define no          cout<<"NO";
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

/*
bool cmp ( pii A , pii B)
{
   return A.first < B.first;
}
 struct structure_name
 {
   int u,v,w;
   structure_name(int _u,int _v,int _w)
   {
      u=_u;
      v=_v;
      w=_w;
   }
 };
*/
///////////////////////////////////////////////////////////////////CODE///////////////////////////////////////////////////////////////////////////////
const ll N=2e5+100;
const ll lg=log2(N+2);
ll T[N][lg+1];
vector<ll>adj[N];
ll n,level[N],in[N],out[N],val[N],arr[2*N+3],tree[8*N];
ll tim=1;

void dfs(ll node)
{
    in[node]=tim;
    tim++;

    for(auto xx:adj[node])
    {
        if(T[xx][0]==-1 and xx!=1)
        {
            T[xx][0]=node;
            level[xx]=level[node]+1;
            dfs(xx);
        }
    }
    out[node]=tim;
    tim++;
}

void buildSparseTableAndArray()
{
  memset(T,-1,sizeof(T));
  level[1]=0;
  dfs(1);
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

  for(int i=1;i<=n;i++)
  {
    arr[in[i]]=val[i];
    arr[out[i]]=val[i]*-1;
  }


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

void build(ll node,ll l, ll r)
{
    if(l==r)
    {
        tree[node]=arr[l];
        return;
    }
 
    ll mid=(l+r)>>1;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    tree[node]=tree[node*2]+tree[node*2+1];
}
 
void update(ll node,ll l, ll r,ll i,ll value)
{
    if(l==r and l==i)
    {
        tree[node]=value;
        return;
    }
    if(l==r)
    {
        return;
    }
 
    ll mid=(l+r)>>1;
    if(i<=mid)
    {
        update(node*2,l,mid,i,value);
    }
    else
    {
        update(node*2+1,mid+1,r,i,value);
    }
    tree[node]=tree[node*2]+tree[node*2+1];
}
 
ll query(ll node,ll l, ll r,ll i,ll j)
{
    if(r<i or l>j)
    {
        return 0;
    }
    if(l>=i and r<=j)
    {
        return tree[node];
    }
    ll mid=(l+r)>>1;
    ll x=query(node*2,l,mid,i,j);
    ll y=query(node*2+1,mid+1,r,i,j);
    return x+y;
}
void solve()
{

    ll q,x,y;

    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>val[i];
    }
    for(int i=1;i<=n-1;i++)
    {
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    buildSparseTableAndArray();
    build(1,1,2*n);

    ll type,nodenum,u,v;
    for(int i=1;i<=q;i++)
    {
        cin>>type;
        if(type==1)
        {
            cin>>nodenum>>x;
            arr[in[nodenum]]=x;
            arr[out[nodenum]]=x*-1;
            update(1,1,2*n,in[nodenum],x);
            update(1,1,2*n,out[nodenum],x*-1);
        }
        else
        {
            cin>>u>>v;
            ll lcaNode=lca(u,v);
            ll distU=query(1,1,2*n,in[1],in[u]);
            ll distV=query(1,1,2*n,in[1],in[v]);
            ll distLcaNode=query(1,1,2*n,in[1],in[lcaNode]);
            ll res=((distU+distV)-2*distLcaNode)+arr[in[lcaNode]];
            cout<<res<<endl;
        }
    }


    
    
    
    cout<<endl;

}


int main()
{

        BOOST;
       //READ("in.txt");
       //WRITE("out.txt");
      
         int tt=1;
         //cin>>tt;
         fo(i,1,tt)
         {
           solve();
         }

        return 0;
}