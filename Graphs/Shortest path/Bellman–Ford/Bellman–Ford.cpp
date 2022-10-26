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



const int N = 1e2+5;
const int MOD = 1e9+7;
const int maxn = 105;
const int inf = 2000000000;
const ll infll = 90000000000000;



struct Edge{
   ll u,v,w;
};

vector<Edge>ed;
ll dist[N];
ll n,edge;
bool cycle=false;
void init()
{
    fo1(N-3)
    {
        ed.clear();
        dist[i]=infll;
    }
}

void BellmanFord(ll source)
{

    dist[source]=0;
    bool hobe=false;
    ll u,v,w;
    fo(n)
    {
        cycle=false;
        hobe=false;
        for(Edge e:ed)
        {
            u=e.u;
            v=e.v;
            w=e.w;
            if(dist[v]>dist[u]+w)
            {
                cycle=true;
                hobe=true;
                dist[v]=dist[u]+w;
            }

            if(dist[u]>dist[v]+w)
            {
                cycle=true;
                hobe=true;
                dist[u]=dist[v]+w;
            }
        }
        //check in this iteration any update happened, if not then break remining iterations.
        if(hobe==false) break;
    }

}

void solve(int cas)
{
        cout<<"Case "<<cas<<": ";
        ll u,v,w,source;
        cin>>n>>edge;
        fo(edge)
        {
            cin>>u>>v>>w;
            ed.pb({u,v,w});
        }
        BellmanFord(1);
        if(cycle==true)
        {
            cout<<"Negative Cycle"<<endl;
            return;
        }
        if(dist[n]==infll) cout<<"Impossible"<<endl;
        else cout<<dist[n]<<endl;

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
