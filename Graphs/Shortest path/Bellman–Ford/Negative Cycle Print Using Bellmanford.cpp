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



const int N = 3e3;
const int MOD = 1e9+7;
const int maxn = 105;
const int inf = 2000000000;
const ll infll = 9000000000000000;



struct Edge{
   ll u,v,w;
};

vector<Edge>ed;
vector<ll>vv;
ll dist[N],parent[N];
ll n,edge,ii=-1;
void init()
{
    vv.clear();
    ed.clear();
    fo1(N-3)
    {
        dist[i]=infll;
        parent[i]=-1;
    }
}

void BellmanFord(ll source)
{

    dist[source]=0;
    bool hobe=false;
    ll u,v,w;
    fo(n)
    {
        hobe=false;
        for(Edge e:ed)
        {
            u=e.u;
            v=e.v;
            w=e.w;
            if(dist[v]>dist[u]+w)
            {
                if(i==n)
                {
                    ii=v;
                }
                hobe=true;
                dist[v]=dist[u]+w;
                parent[v]=u;
            }

        }
        if(hobe==false) break;
    }

}

ll cycle_parent()
{
    map<ll,ll>mp;
    mp[ii]++;
    vv.pb(ii);
    while(1)
    {
        ii=parent[ii];
        mp[ii]++;
        vv.pb(ii);
        if(mp[ii]>1)
        {
           return ii;
        }
    }
}

void solve()
{
        ll u,v,w,source,x=-1,y=-1;
        cin>>n>>edge;
        fo(edge)
        {
            cin>>u>>v>>w;
            ed.pb({u,v,w});
        }
        BellmanFord(1);
        if(ii==-1)
        {
            cout<<"NO"<<endl;
            return;
        }
        cout<<"YES"<<endl;
        x=cycle_parent();
        vector<ll>vv1;
        fov(vv)
        {
            if(y!=-1)
            {
                vv1.pb(vv[i]);
            }
            else
            {
                if(vv[i]==x)
                {
                    vv1.pb(vv[i]);
                    y=1;
                }
            }
        }
        reverse(vv1.begin(),vv1.end());
        fov(vv1)
        {
            cout<<vv1[i]<<" ";
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
