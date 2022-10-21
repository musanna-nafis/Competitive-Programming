#include<bits/stdc++.h>
typedef long long int   ll;
typedef long int   l;
typedef long double     ld;

#define pii pair<long long int,long long int>
#define pii1 pair<char,long long int>
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
//////////////////////////////////////////////////////////////////CODE/////////////////////////////////////////////////////////////////////////////////



const int N = 1e5+5;
const int MOD = 1e9+7;
const int maxn = 105;
const int inf = 2000000000;
const ll infll = 9000000000000000000;


struct Node
{
    ll node,cost;
    Node(ll _node,ll _cost)
    {
        node=_node;
        cost=_cost;
    }
};

struct Edge
{
    ll v,w;
};

bool operator<(Node A,Node B)
{
    return A.cost>B.cost;
}

vector<Edge>adj[N];
priority_queue<Node>pq;
ll dist[N];
ll parent[N];
ll n,edge;

void init()
{
    fo(N-3)
    {
        dist[i]=infll;
        adj[i].clear();
        parent[i]=-1;
    }
}
void dijkstra(ll source)
{
    dist[source]=0;
    pq.push(Node(source,0));
    while(!pq.empty())
    {
        Node u=pq.top();
        pq.pop();
        if(u.cost!=dist[u.node]) continue;
        for(auto x:adj[u.node])
        {
            if(u.cost+x.w<dist[x.v])
            {
                dist[x.v]=u.cost+x.w;
                pq.push(Node(x.v,dist[x.v]));
                parent[x.v]=u.node;
            }
        }
    }
}

void solve()
{
        ll u,v,w,source;
        cin>>n>>edge;
        fo(edge)
        {
            cin>>u>>v>>w;
            adj[u].pb({v,w});
        }
        parent[1]=1;
        dijkstra(1);
        if(parent[n]==-1) cout<<-1;
        else
        {
            vector<ll>v;
            ll at=n;
            v.pb(at);
            while(parent[at]!=1)
            {
                v.pb(parent[at]);
                at=parent[at];
            }
            if(n!=1) v.pb(1);
            reverse(v.begin(),v.end());
            fov(v)
            {
               cout<<v[i]<<" ";
            }

        }
        

       
        cout<<endl;

}


int main()
{

        BOOST;
       //READ("in.txt");
       //WRITE("out.txt");
      

           init();
           solve();

        return 0;
}