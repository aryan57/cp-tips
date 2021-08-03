//https://codeforces.com/contest/1511/problem/E

/*
    credits: @nishant403
    // sol used : https://codeforces.com/contest/1511/submission/112835332
    author : Aryan Agarwal, IIT Kharagpur
    created : 13-April-2021 00:02:03 IST
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
// const int32_t M = 1000000007;
const int32_t M = 998244353;
const long double pie = acos(-1);

/*
    Binary Exponentiation
    // (a^b)%m
    // O(logb)
    // modInverse(a) = binpow(a, phi(n)-1, n)
    // If n is prime, phi(n)=n-1
*/
int binpow(int a, int b=M-2, int m=M) {
    a %= m;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

// https://oeis.org/A045883
int val(int n)
{
    int t=3*n-2;
    t*=binpow(2,n-1);
    t%=M;
    int k=1;
    if(n%2)k=-1;

    t+=k;
    t%=M;
    t+=M;
    t%=M;

    t*=binpow(9);
    t%=M;

    return t;

}

int ways(int rem,int cnt)
{
    if(cnt<=1)return 0;

    int ans=binpow(2,rem);
    ans*=val(cnt);
    ans%=M;

    return ans;
}

void solve_LOG()
{
    int n,m;
    cin>>n>>m;

    int g[n+1][m+1]={};

    int tot=0;

    F(i,0,n-1)
    {
        F(j,0,m-1)
        {
            char x;
            cin>>x;
            g[i][j]=x=='o';
            tot+=x=='o';
        }
    }

    int ans=0;

    F(i,0,n-1)
    {
        int cnt=0;
        F(j,0,m)
        {
            if(g[i][j]==0)
            {
                ans+=ways(tot-cnt,cnt);
                ans%=M;
                cnt=0;
                continue;
            }
            cnt++;
        }
    }
    F(j,0,m-1)
    {
        int cnt=0;
        F(i,0,n)
        {
            if(g[i][j]==0)
            {
                ans+=ways(tot-cnt,cnt);
                ans%=M;
                cnt=0;
                continue;
            }
            cnt++;
        }
    }

    cout<<ans;

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
    // cin>>_t;
    for (int i=1;i<=_t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve_LOG();
    }
    return 0;
}