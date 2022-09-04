#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
typedef long long int LL;
typedef long double LD;
#define nl '\n'
#define ff first
#define ss second
#define inf INT_MAX
#define pb push_back
#define GCD(a, b) __gcd(a, b)
#define PI 2.0 * acos(0.0)
#define pii pair<int, int>
#define pll pair<long long, long long>
#define LCM(a, b) (a * b) / GCD(a, b)
#define mem(a, b) memset(a, b, sizeof(a))
#define srtv(v) sort(v.begin(), v.end())
#define Rep(i, a, b) for (int i = a; i <= b; i++)
#define rep(i, a, b) for (int i = a; i >= b; i--)
#define FOR(i, a) for (int i = 0; i < a; i++)
// #pragma                 GCC optimize("Ofast,no-stack-protector")
// #pragma                 GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma                 GCC optimize("unroll-loops")
#define boost                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define inout                         \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
#define si(x) scanf("%d", &x)
#define pi(x) printf("%d", x)
#define sss(str) scanf("%s", str)
#define pl(x) printf("%lld", x)
#define sl(x) scanf("%lld", &x)
#define sii(x, y) scanf("%d %d", &x, &y)
#define sll(x, y) scanf("%lld %lld", &x, &y)
#define siii(x, y, z) scanf("%d %d %d", &x, &y, &z)
#define slll(x, y, z) scanf("%lld %lld %lld", &x, &y, &z)
//using    namespace __gnu_pbds;
using namespace std;
//Graph direction array[4]
//int dx[]={0,0,-1,1};
//int dy[]={1,-1,0,0};
//Graph direction array[8]
//dx[]={0,0,1,-1,-1,1,1,-1};
//dy[]={1,-1,0,0,-1,-1,1,1};
//Bishop direction array[8]
//dx[]={0,0,1,-1,-1,1,1,-1};
//dy[]={1,-1,0,0,-1,-1,1,1};
//Knight Direction array[8]
//dx[]={1,1,2,2,-1,-1,-2,-2};
//dy[]={2,-2,1,-1,2,-2,1,-1};
inline long long int MOD(long long int a, long long int m){a=a%m;if(a<0)a+=m; return a;}
#define popcountL __builtin_popcountll
#define popcount __builtin_popcount
inline bool checkBit(int N, int pos){return (bool)(N & (1 << pos));}
inline int setBit(int N, int pos) { return N = N | (1 << pos); }
inline int unsetBit(int N, int pos) { return N = (N & (~(1 << pos))); }
inline int toggleBit(int N, int pos) { return N = (N ^ (1 << pos)); }
long long powerMod(long long number, long long power, long long mod)
{
    LL ret = 0;
    if (power == 0)
        return 1LL % mod;
    if (power == 1)
        return number % mod;
    if (power % 2 == 0)
    {
        ret = powerMod(number, power / 2, mod);
        ret = (ret % mod * ret % mod) % mod;
        return ret % mod;
    }
    else
    {
        ret = powerMod(number, power / 2, mod);
        ret = (((ret % mod) * (ret % mod))%mod * (number % mod)) % mod;
        return ret % mod;
    }
}
// ******Do not use + for adding something to the string always use push_back**********

//typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
//--------------------------code starts here---------------------------------------
const int maxn = 5e5 + 5;
int weight[100],value[100];
int n,tot,dp[100][100];
int fun(int pos,int baki)
{
    if(baki<0)
    {
        return -1e5;
    }
    if(pos>n || baki==0)
    {
        return 0;
    }
    if(dp[pos][baki]!=-1)
        return dp[pos][baki];
    int res=0;
    res=max(res,value[pos]+fun(pos+1,baki-weight[pos]));
    res=max(res,fun(pos+1,baki));
    return dp[pos][baki]=res;
}

void print(int pos,int baki)
{
    if(baki<0)
    {
        return;
    }
    if(pos>n || baki==0)
    {
        return;
    }
    int res=0;
    res=max(res,fun(pos+1,baki));
    if(res==dp[pos][baki])
    {
        print(pos+1,baki);
        return;
    }
    res=max(res,value[pos]+fun(pos+1,baki-weight[pos]));
    if(res==dp[pos][baki])
    {
        cout<<pos<<" ";
        print(pos+1,baki-weight[pos]);
        return;
    }
}

void solve(int test)
{
    cin>>n>>tot;
    for(int i=1;i<=n;i++)
    {
        cin>>weight[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>value[i];
    }
    mem(dp,-1);
    int res=fun(1,tot);
    print(1,tot);
}
int main()
{
    boost;
    int ttt = 1;
    //si(ttt);
    Rep(test, 1, ttt)
    {
        solve(test);
    }
    return 0;
}

