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


ll dx[]={-1, 1, 0, 0, -1, -1, 1, 1};
ll dy[]={0, 0, -1, 1, -1, 1, -1, 1};

const int N = 309;
const int MOD = 1e9+7;
const int maxn = 105;
const int inf = 2000000000;
const ll infll = 900000000000000;

ll hobe=infll;
struct Node
{
    ll row,column,cost;
    Node(ll _row,ll _column,ll _cost)
    {
        row=_row;
        column=_column;
        cost=_cost;
    }
};


bool operator<(Node A,Node B)
{
    return A.cost>B.cost;
}

priority_queue<Node>pq;
ll dist1[N][N];
ll row,column;
char val[N][N];
void init()
{
    for(int i=1;i<N-3;i++)
    {
        for(int j=1;j<N-3;j++)
        {
            dist1[i][j]=infll;
        }
    }
}


void dijkstra(ll x,ll y)
{

    dist1[x][y]=0;
    pq.push(Node(x,y,0));

    while(!pq.empty())
    {
        Node u=pq.top();
        pq.pop();

        if(u.cost != dist1[u.row][u.column])
        {
            continue;
        }
        for(int i=0;i<4;i++)
        {
            ll newx=u.row+dx[i];
            ll newy=u.column+dy[i];
            if(newx>=1 and newx<=row and newy>=1 and newy<=column and val[newx][newy]=='.')
            {
                if(dist1[newx][newy]>u.cost+1)
                {
                    dist1[newx][newy]=u.cost+1;
                    if(newx==1 or newx==row or newy==1 or newy==column)
                    {
                        hobe=min(hobe,dist1[newx][newy]);
                    }
                    pq.push(Node(newx,newy,dist1[newx][newy]));
                }
            }
        }

    }
}


void dijkstra1()
{

    while(!pq.empty())
    {
        Node u=pq.top();
        pq.pop();

        if(u.cost != dist1[u.row][u.column])
        {
            continue;
        }
        for(int i=0;i<4;i++)
        {
            ll newx=u.row+dx[i];
            ll newy=u.column+dy[i];
            if(newx>=1 and newx<=row and newy>=1 and newy<=column and val[newx][newy]=='.')
            {
                if(dist1[newx][newy]>u.cost+1)
                {
                    dist1[newx][newy]=u.cost+1;
                    pq.push(Node(newx,newy,dist1[newx][newy]));
                }
            }
        }
    }
}

void solve(int cas)
{
        cout<<"Case "<<cas<<": ";
        hobe=infll;
        ll u,v;
        cin>>row>>column;
        for(int i=1;i<=row;i++)
        {
            for(int j=1;j<=column;j++)
            {
                cin>>val[i][j];
                if(val[i][j]=='J')
                {
                    u=i;
                    v=j;
                }
                else if(val[i][j]=='F')
                {
                    pq.push(Node({i,j,0}));
                    dist1[i][j]=0;
                }
            }
        }
        dijkstra1();
        dijkstra(u,v);
        if(hobe==infll) cout<<"IMPOSSIBLE"<<endl;
        else cout<<hobe+1<<endl;
        //cout<<endl;

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
