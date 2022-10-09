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



vector<ll>adj[10009];
ll indegree[10009];
queue<ll>q;
vector<ll>order;

void topSort()
{
    ll parent,child;
    while(!q.empty())
    {
       parent=q.front();
       q.pop();
       for(ll i=0;i<adj[parent].size();i++)
       {
          child=adj[parent][i];
          indegree[child]--;
          if(indegree[child]==0)
          {
             q.push(child);
             order.pb(child);
          }
       }
    }
}
   
void init()
{
    fo(10009)
    {
      adj[i].clear();
      indegree[i]=0;
    }
    order.clear();
}
void solve(int cas)
{
        ll node,edge,x,y;
        cin>>node>>edge;
        fo(edge)
        {
            cin>>x>>y;
            adj[x].pb(y);
            indegree[y]++;
        }
        fo(node)
        {
            if(indegree[i]==0)
            {
                q.push(i);
                order.pb(i);
            }
        }
        
        topSort();
  


        cout<<"Topological Order Using Bfs: ";
        fov(order)
        {
            cout<<order[i]<<" ";
        }
        cout<<endl;
}



int main()
{

        BOOST;
       //READ("in.txt");
       //WRITE("out.txt");


        int test;
        cin>>test;
        fo(test)
        {
           init();
           solve(i);
        }

        return 0;
}
