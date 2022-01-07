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
#define mem(a,b)        memset(a,b,sizeof(a))
#define pb              push_back
#define gcd(a, b)       __gcd(a, b)
#define vsorti(v)         sort(v.begin(),v.end())
#define vsortd(v)         sort(v.begin(), v.end(), greater<int>());
using namespace std;

bool cmp ( pii A , pii B)
{
   return A.first < B.first;

}

/*
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


int main()
{

BOOST;
       //READ("in.txt");
       //WRITE("out.txt");

        ll q;
        cin>>q;
        while(q--)
        {
            ll n,k,i,cou=0,x,y,j,z,sum=intmax,amar=intmax,tar=0;
            cin>>n;
            vector<pii>v1,v;
            for(i=1;i<=n;i++)
            {
                cin>>x;
               v.pb(pii(x,i-1));
            }
            for(i=1;i<=n;i++)
            {
                cin>>y;
                v1.pb(pii(y,i-1));
            }
             sort(v.begin(),v.end(),cmp);
             sort(v1.begin(),v1.end(),cmp);

            for(i=0;i<v.size();i++)
            {
               amar=min(amar,v[i].second);
               //cout<<amar<<" "<<v[i].second<<endl;
               sum=min(sum,((v1[i].second)+amar));
            }

            cout<<sum<<endl;


        }


    return 0;
}


