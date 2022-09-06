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
#define fo1(n)             for(int i=n;i>=1;i--)
#define foo(n)             for(int i=0;i<n.size();i++)

using namespace std;
ll dp[103][103];
ll n,m;
string s,t,str="";
ll mydp(int i,int j)
{
  if(i>n or j>m) return 0;
  if(dp[i][j]!=-1) return dp[i][j];

  if(s[i]==t[j])
  {
     return dp[i][j]=1+mydp(i+1,j+1);
  }
  else
  {
     return dp[i][j]=max(mydp(i+1,j),mydp(i,j+1));
  }

}
void print(int pos1,int pos2,int res)
{
  if(pos1>n or pos2>m or res<=0) return ;

  char xo='z'+1;
  int p1=n+1,p2=m+1;
  for(int i=pos1;i<=n;i++)
  {
     for(int j=pos2;j<=m;j++)
     {
       if(s[i]==t[j] and dp[i][j]==res and s[i]<xo)
       {
         p1=i;
         p2=j;
         xo=s[i];
       }
     }
  }

str.pb(xo);
print(p1+1,p2+1,res-1);


}
int main()
{
     BOOST;
     int q,ca=0;
     cin>>q;

     while(q--)
     {
         int i,j,x,c=0,y,z,l,k,op=0,c1=0,sum=0,x1,y1,po=0;
         ca++;
         cout<<"Case "<<ca<<": ";
         mem(dp,-1);
         cin>>s>>t;
         n=s.size();
         m=t.size();
         n--;
         m--;
         int res=mydp(0,0);
         if(res<=0)
         {
            cout<<":(";
         }
         else
         {
           string kk="";
           int pos1=0,pos2=0;
           char zz='z'+1;
           for(i=0;i<=n;i++)
           {
             for(j=0;j<=m;j++)
             {
               if(dp[i][j]==res and s[i]==t[j] and s[i]<zz)
               {
                 zz=s[i];
                 pos1=i;
                 pos2=j;
               }
             }
           }

           kk.pb(zz);
           str="";
           print(pos1+1,pos2+1,res-1);
           kk=kk+str;
           cout<<kk;

         }

       cout<<endl;


     }



      return 0;
}
