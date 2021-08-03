//https://codeforces.com/contest/1476/problem/C

/*
    author : Aryan Agarwal, IIT KGP
    created : 30-January-2021 10:02:57 IST
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mxn = 1e5;
const long long INF = 2e18;
const int32_t M = 1000000007; /*more than 1e9 */ /*7 + 1e9*/
// const int32_t M = 998244353; /*less than 1e9 */   /*1 + 7*17*(1<<23) */
const long double pie = acos(-1);

#define X first
#define Y second
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define F(i, a, b) for (int i = a; i <= b; i++)
#define RF(i, a, b) for (int i = a; i >= b; i--)

#define dbg(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}

void solve_LOL()
{
    int n;
    cin>>n;

    int c[n],a[n],b[n];

    F(i,0,n-1)cin>>c[i];
    F(i,0,n-1)cin>>a[i];
    F(i,0,n-1){cin>>b[i];if(a[i]>b[i])swap(a[i],b[i]);}

    int ar[n]={};

    F(i,0,n-2)
    {
        if(a[i+1]==b[i+1])
        {
            ar[i]=2;
            continue;
        }
        if(i==0)
        {
            ar[i]=2+b[i+1]-a[i+1];
            continue;
        }
        ar[i]=2+max(ar[i-1]+a[i+1]-1+c[i]-b[i+1],b[i+1]-a[i+1]);
    }

    // F(i,0,n-2)
    // {
    //     dbg(ar[i],i);
    // }

    int ans=-INF;

    F(i,1,n-1)
    {
        ans=max(ans,c[i]-1+ar[i-1]);
    }

    cout<<ans;
    cout<<"\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
// freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);
#endif
#ifdef ARYAN_SIEVE
    // defualt mxn_sieve = 1e5
    sieve();
#endif
#ifdef ARYAN_SEG_SIEVE
    // default [L,R] = [1,1e5]
    segmented_sieve();
#endif
#ifdef ARYAN_FACT
    // default mxn_fact = 1e5
    fact_init();
#endif
    // cout<<fixed<<setprecision(10);
    int _t=1;
    cin>>_t;
    for (int i=1;i<=_t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve_LOL();
    }
    return 0;
}