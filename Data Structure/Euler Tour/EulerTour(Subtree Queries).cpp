#include<bits/stdc++.h>
typedef long long int   ll;
typedef long int   l;
typedef long double     ld;
 
#define pii pair<long long int,long long int>
#define intmax  INT_MAX
#define endl        "\n"
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
 
 
#define fo(n)               for(int i=1;i<=n;i++)
#define fov(v)              for(int i=0;i<v.size();i++)
#define fos(s)              for(int i=0;i<s.size();i++)
using namespace std;
 
const int N=2e5+100;
bool visited[N];
vector<ll>adj[N];
ll in[N],out[N],val[N],arr[N*4];
ll tree[N*4];
ll n,tim=1;
 
void clear()
{
	for(int i=1;i<=N-10;i++)
	{
		adj[i].clear();
		visited[i]=false;
		out[i]=-1;
		in[i]=-1;
	}
}
 
void dfs(ll node)
{
	in[node]=tim;
	visited[node]=true;
	for(auto xx:adj[node])
	{
	    if(visited[xx]==false)
	  	{
	  		tim++;
	  		dfs(xx);
	  	}
	}
 
	out[node]=tim;
}
 
void add()
{
	for(int i=1;i<=n;i++)
	{
		arr[in[i]]=val[i];
	}
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
 
void solve(int cas)
{
	ll x,y,q,z,nodenum;
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
	dfs(1);
	add();
    build(1,1,n);
 
    for(int i=1;i<=q;i++)
    {
    	cin>>x;
    	if(x==1)
    	{
           cin>>nodenum>>z;
           update(1,1,n,in[nodenum],z);
    	}
    	else
    	{
          cin>>nodenum;
          cout<<query(1,1,n,in[nodenum],out[nodenum])<<endl;
    	}
    }
}
 
int main()
{
	BOOST;
	ll test=1;
	//cin>>test;
	for(int i=1;i<=test;i++)
	{
		clear();
		solve(i);
	}
 
}