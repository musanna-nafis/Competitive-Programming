#include<bits/stdc++.h>
#define mem(a,b)        memset(a,b,sizeof(a))
using namespace std;

vector<int> adj[100];
bool visited[100];

void dfs(int k)
{

    if(visited[k]==true)
    {
        return;
    }

    visited[k]=true;

    for(int i=0;i<adj[k].size();i++)
    {
        dfs(adj[k][i]);
    }

}
int main()
{
    mem(visited,false);

    for(int i=0;i<100;i++)
    {
        adj[i].clear();
    }

    long long int  n,c=0,sum=0,count=0,sum1=0,x,y,m;
    cin>>n>>m;

    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);

    }
    for(int i=1;i<=n;i++)
    {

        if(visited[i]==false)
        {
            dfs(i);
            count++;
        }
    }
    cout<<count<<endl;

    return 0;
}
