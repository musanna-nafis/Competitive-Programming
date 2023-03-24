// https://lightoj.com/problem/substring-frequency


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
const int N=1e6;
int failure[N+12];
string s,t;
int n,m;
void buildFailureFun()
{
    failure[1]=0;
    for(int i=2;i<=m;i++)
    {
        int j=failure[i-1];
        while(true)
        {
            if(t[j]==t[i-1])
            {
                failure[i]=j+1;
                break;
            }
            else
            {
                if(j==0)
                {
                    failure[i]=0;
                    break;
                }
                else
                {
                    j=failure[j];
                }
            }
        }
    }
}

int kmp()
{
    buildFailureFun();
    int i=0;
    int j=0;
    int cou=0;
    while(true)
    {
        if(i==n) return cou;

        if(s[i]==t[j])
        {
            i++;
            j++;
            if(j==m)
            {
                cou++;
                j=failure[j];
            }
        }
        else
        {
            if(j==0)
            {
                i++;
            }
            else
            {
                j=failure[j];
            }
        }
    }


    return cou;
}

void solve(int cas)
{
    cin>>s>>t;
    n=s.size();
    m=t.size();
    cout<<"Case "<<cas<<": "<<kmp()<<endl;

}

int main()
{

       BOOST;
       //READ("in.txt");
       //WRITE("out.txt");


        int T;
        cin>>T;
        for(int i=1;i<=T;i++)
        {
            solve(i);
        }

        return 0;
}

