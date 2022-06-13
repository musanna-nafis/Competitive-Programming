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

using namespace std;

int lowestPrime[500009];
void Prime_factor(int n)
{
   lowestPrime[1]=1;
  for(int i=3;i<=n;i+=2)
  {
    for(int k=i;k<=n;k+=i+i)
    {
        if(lowestPrime[k]==0)
        {
          lowestPrime[k]=i;
        }
    }  
  }

}
int main()
{

     
     BOOST;
     Prime_factor(500009);
     //query for find out a number prime factor
     int q;
     cin>>q;
     while(q--)
     {
       int number;
       cin>>number;
       map<int,int>prime_factors;
       while(1)
       {
         if(number<=1)
         {
           prime_factors[1]++;
           break;
         }
         if(number%2==0)
         {
            prime_factors[2]++;
            number/=2;
         }
         else
         {
           prime_factors[lowestPrime[number]]++;
           number/=lowestPrime[number];
         }
         
       }
       int x,y;
       ll po;
       ll z=1;
       for(auto ok: prime_factors)
       {
         x=ok.first;
         y=ok.second;
         
         if(x!=1)
         {

            po=(ll)(pow(x,y+1)+1e-9);
            z=z*((po-1)/(x-1));

         }
         
       }
      
       cout<<z<<endl;
     }
   
     
      return 0;
}