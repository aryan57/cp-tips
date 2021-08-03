//https://codeforces.com/contest/1513/problem/A

/*
    author : Aryan Agarwal, IIT Kharagpur
    created : 11-April-2021 20:06:09 IST
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

void solve_LOG()
{
    int n,k;
    cin>>n>>k;

    int p[n]={};
    if(!k)
    {
        iota(p,p+n,1);
        for(int x : p)cout<<x<<" ";
        cout<<"\n";
        return;
    }


    if(n<3)
    {
        cout<<"-1\n";
        return;
    }


    set<int> s;
    F(i,1,n)
    {
        s.insert(i);
    }

    vector <int> vec;
    vec.pb(1);
    s.erase(1);
    vec.pb(n);
    s.erase(2);
    vec.pb(2);
    s.erase(n);

    k--;


    while(k>0)
    {
        if(sz(s)<2)
        {
            // dbg(s);
            cout<<"-1\n";
            return;
        }

        auto it=s.end();
        it--;
        vec.pb(*it);
        s.erase(it);
        vec.pb(*s.begin());
        s.erase(s.begin());
        k--;
    }

    int ind=0;

    for(int num : vec)
    {
        p[ind++]=num;
    }

    F(i,0,n-1)
    {
        if(p[i])continue;

        if(s.empty())
        {
            cout<<"-1\n";
            return;
        }

        p[i]=*s.begin();
        s.erase(s.begin());
    }

    for(int x : p)cout<<x<<" ";
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
        solve_LOG();
    }
    return 0;
}