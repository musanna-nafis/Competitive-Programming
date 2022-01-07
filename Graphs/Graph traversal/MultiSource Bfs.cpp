#include<bits/stdc++.h>
#define mem(a,b)        memset(a,b,sizeof(a))
using namespace std;


vector<int> adj[100];
bool visited[100];
int level[100];
queue<int>q;
int n,m,sourceNode;

void  multisource_bfs()
{
    while(!q.empty())
    {
     int node=q.front();
     q.pop();

   for(int i=0;i<adj[node].size();i++)
   {
       if(visited[adj[node][i]]==false)
       {
         level[adj[node][i]]=level[node]+1;
         q.push(adj[node][i]);
         visited[adj[node][i]]=true;
       }
   }
    }

}
int main()
{
    mem(visited,false);

    for(int i=0;i<100;i++)
    {
        adj[i].clear();
    }

    long long int  c=0,sum=0,count=0,sum1=0,x,y,source;
    cin>>n>>m>>sourceNode;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=1;i<=sourceNode;i++)
    {
        cin>>source;
        q.push(source);
        level[source]=0;
        visited[source]=true;

    }
    multisource_bfs();
    for(int i=1;i<=n;i++)
    {
        cout<<level[i]<<" ";
    }

    return 0;
}
