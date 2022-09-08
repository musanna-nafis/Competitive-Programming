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
// for(auto i:v)
#define MAX_LIMIT 1000000
#define mem(a,b)        memset(a,b,sizeof(a))
#define pb              push_back
#define gcd(a, b)       __gcd(a, b)
#define vsorti(v)         sort(v.begin(),v.end())
#define vsortd(v)         sort(v.begin(), v.end(), greater<long long int>());
#define asortd(a,n)       sort(a+1,a+1+n, greater<long long int>());
#define asorti(a,n)       sort(a+1,a+1+n)
#define fo(n)             for(int i=1;i<=n;i++)
using namespace std;
string s,t,o;
int n,m,m1;
int dp[59][59][59];
int mydp(int i,int j,int k)
{
   if(i>=n or j>=m or k>=m1) return 0;

   if(dp[i][j][k]!=-1) return dp[i][j][k];

   if(s[i]==t[j] and o[k]==t[j])
   {
     return dp[i][j][k]=mydp(i+1,j+1,k+1)+1;
   }
   else
   {
     if(s[i]==t[j])
     {
        return dp[i][j][k]=max(mydp(i,j,k+1),mydp(i+1,j+1,k));
     }
     else if(s[i]==o[k])
     {
        return dp[i][j][k]=max(mydp(i,j+1,k),mydp(i+1,j,k+1));
     }
     else if(t[j]==o[k])
     {
        return dp[i][j][k]=max(mydp(i+1,j,k),mydp(i,j+1,k+1));
     }
     else
     {
        int v1=0;
        v1=max(v1,mydp(i+1,j+1,k));
        v1=max(v1,mydp(i+1,j,k+1));
        v1=max(v1,mydp(i,j+1,k+1));
        return dp[i][j][k]=v1;
     }
   }
}

int main()
{


        BOOST;
        int q,cc=0;
        cin>>q;
        while(q--)
        {
            mem(dp,-1);
            cc++;
            cout<<"Case "<<cc<<": ";
            cin>>s>>t>>o;
            n=s.size();
            m=t.size();
            m1=o.size();
            cout<<mydp(0,0,0);
            cout<<endl;

      }
     return 0;
}
