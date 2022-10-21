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



const int N = 5009;
const int MOD = 1e9+7;
const int maxn = 105;
const int inf = 2000000000;
const ll infll = 900000000000000000;


struct Node
{
    ll node,cost;
    Node(ll _node,ll _cost)
    {
        node=_node;
        cost=_cost;
    }
};

struct Edge{
    ll v;
    ll w;
};

struct Edgev{
    ll u,v,w;
};

bool operator<(Node A,Node B)
{
    return A.cost>B.cost;
}

vector<Edge>adj[N];
priority_queue<Node>pq;
ll dist[N],dist1[N];
ll n,edge;

void init()
{
    fo(N-3)
    {
        dist[i]=infll;
        dist1[i]=infll;
        adj[i].clear();
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

        if(u.cost != dist[u.node])
        {
            continue;
        }

        for(Edge e: adj[u.node])
        {
            if(dist[e.v]>u.cost+e.w)
            {
                dist[e.v]=u.cost+e.w;
                pq.push(Node(e.v,dist[e.v]));
            }
        }

    }
}
void dijkstra1(ll source)
{

    dist1[source]=0;
    pq.push(Node(source,0));

    while(!pq.empty())
    {
        Node u=pq.top();
        pq.pop();

        if(u.cost != dist1[u.node])
        {
            continue;
        }

        for(Edge e: adj[u.node])
        {
            if(dist1[e.v]>u.cost+e.w)
            {
                dist1[e.v]=u.cost+e.w;
                pq.push(Node(e.v,dist1[e.v]));
            }
        }

    }
}

void solve(int cas)
{
        ll u,v,w,source;
        cin>>n>>edge;
        vector<Edgev>ed;
        cout<<"Case "<<cas<<": ";
        fo(edge)
        {
            cin>>u>>v>>w;
            adj[u].pb({v,w});
            adj[v].pb({u,w});
            ed.pb({u,v,w});
        }
       dijkstra(1);
       dijkstra1(n);
       ll maxi=infll;

       fov(ed)
       {
          u=ed[i].u;
          v=ed[i].v;
          w=ed[i].w;

          if(dist[u]+dist1[v]+w>=dist[n])
          {
                if(dist[u]+dist1[v]+w==dist[n])
                {
                   maxi=min(maxi,dist[u]+dist1[v]+(3*w));
                } 
                else 
                {
                    maxi=min(maxi,dist[u]+dist1[v]+w);
                }
          }
          if(dist[v]+dist1[u]+w>=dist[n])
          {
                if(dist[v]+dist1[u]+w==dist[n])
                {
                  maxi=min(maxi,dist[v]+dist1[u]+(3*w));
                }

                else{
                    maxi=min(maxi,dist[v]+dist1[u]+w);
                }
          }
       }

       
        cout<<maxi<<endl;

}


int main()
{

        BOOST;
       //READ("in.txt");
       //WRITE("out.txt");
      

         int q;
         cin>>q;
         fo(q)
         {
           init();
           solve(i);
         }

        return 0;
}