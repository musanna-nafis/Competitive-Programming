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

string s,t;
int dp[2009][2009];
int n=0,m=0;

int mydp(int i,int j)
{
     if(i>n or j>m)
     {
         if(i>n)
         {
            if(j<=m)
            {
               return (m-j)+1;
            }
            else return 0;
         }
         else if(j>m)
         {
            if(i<=n)
            {
               return (n-i)+1;
            }
            else return 0;
         }
     }
     if(dp[i][j]!=-1) return dp[i][j];

     int x=m+n+m+n+4;

     if(s[i]==t[j])
     {
        x=min(x,mydp(i+1,j+1));
     }
     else
     {
         //update
          x=min(x,mydp(i+1,j+1)+1);
         //delete
          x=min(x,mydp(i+1,j)+1);
          x=min(x,mydp(i,j+1)+1);
          //insert
          x=min(x,mydp(i+1,j)+1);
          x=min(x,mydp(i,j+1)+1);
     }


     return dp[i][j]=x;
}

int main()
{


        ll q;
        cin>>q;
        while(q--)
        {
            int k,i,cou=0,x,y,j,z,sum=intmax,amar=intmax,tar=0;
            mem(dp,-1);
            cin>>s>>t;
            n=s.size()-1;
            m=t.size()-1;
            cout<<mydp(0,0);


            cout<<endl;


        }


    return 0;
}
