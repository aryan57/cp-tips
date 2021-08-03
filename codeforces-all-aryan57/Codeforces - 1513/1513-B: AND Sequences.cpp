//https://codeforces.com/contest/1513/problem/B

/*
    tut used
    author : Aryan Agarwal, IIT Kharagpur
    created : 12-April-2021 08:52:06 IST
*/

#include <bits/stdc++.h>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif

#define int long long
#define X first
#define Y second
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define F(i, a, b) for (int i = a; i <= b; i++)
#define RF(i, a, b) for (int i = a; i >= b; i--)

const int mxn = 1e5;
const long long INF = 2e18;
const int32_t M = 1000000007;
// const int32_t M = 998244353;
const long double pie = acos(-1);

#define ARYAN_FACT
const int mxn_fact = 2e5+5;

int fact[mxn_fact + 1];
int invfact[mxn_fact + 1];

void fact_init()
{
    int p = M;

    fact[0] = 1;
    for (int i = 1; i <= mxn_fact; i++)
        fact[i] = (i * fact[i - 1]) % p;

    // res will be binpow(fact[mxn_fact],p-2,p)
    // binpow algo starts....
    int res = 1;
    int x = fact[mxn_fact], y = p - 2;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    // binpow algo ends....

    invfact[mxn_fact] = res;
    for (int i = mxn_fact - 1; i >= 0; i--)
        invfact[i] = (invfact[i + 1] * (i + 1)) % p;
}

void solve_LOL()
{
    int n;
    cin>>n;

    vector <int> v(n);

    F(i,0,n-1)
    {
        cin>>v[i];
    }

    int mn=*min_element(all(v));
    bool ok = true;

    int cnt=0;

    int tt=(int)pow(2,32)-1;

    F(i,0,n-1)
    {
        if(v[i]==mn)cnt++;
        tt&=v[i];
    }

    if(tt!=mn || cnt<2)
    {
        cout<<0;
        cout<<"\n";
        return;
    }

    int ans=1;
    ans*=cnt;
    ans%=M;
    ans*=cnt-1;
    ans%=M;
    ans*=fact[n-2];
    ans%=M;
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