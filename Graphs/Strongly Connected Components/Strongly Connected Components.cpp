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


////////////////CODE/////////////////////////////////

vector<ll>adj[1009];
vector<ll>adj1[1009];
stack<ll>s;
ll decit[1009];

void dfs(ll node)
{
    decit[node]=1;
    for(int j=0;j<adj[node].size();j++)
    {
        if(decit[adj[node][j]]==0)
        {
            dfs(adj[node][j]);
        }
    }
    s.push(node);
    decit[node]=2;
}

void connectedcompo(ll node)
{
    decit[node]=1;
    for(int j=0;j<adj1[node].size();j++)
    {
        if(decit[adj1[node][j]]==0)
        {
           connectedcompo(adj1[node][j]);
        }
    }
    decit[node]=2;
}

void init()
{
    fo(1008)
    {
      adj[i].clear();
      adj1[i].clear();
      decit[i]=0;
    }
}
void solve()
{
        ll n,k,c=0,x=0,y=0,j,z;
        ll node,edge;
        cin>>node>>edge;
        fo(edge)
        {
            cin>>x>>y;
            adj[x].pb(y);
            adj1[y].pb(x);
        }
        fo(node)
        {
            if(decit[i]==0)
            {
                dfs(i);
            }
        }
        mem(decit,0);
        
        while(!s.empty())
        {
            x=s.top();
            if(decit[x]==0)
            {
                c++;
                connectedcompo(x);
            }
            s.pop();
        }
    
        cout<<"Connected Components : ";
        cout<<c<<endl;

}



int main()
{

        BOOST;
       //READ("in.txt");
       //WRITE("out.txt");


        int t;
        cin>>t;
        fo(t)
        {
           init();
           solve();
        }

        return 0;
}

