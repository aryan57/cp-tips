//https://codeforces.com/contest/1476/problem/D

/*
    author : Aryan Agarwal, IIT KGP
    created : 29-January-2021 21:28:48 IST
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
void __f(const char *name, Arg1 &&arg1)
{
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
    const char *comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}

void solve_LOL()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    // s='#'+s;

    // s=s[0]+s+s[n-1];

    int l[n + 1] = {};
    int r[n + 1] = {};

    F(i, 1, n - 1)
    {
        if (s[i] == s[i - 1])
        {
            l[i] = 1;
        }
    }

    RF(i, n - 2, 0)
    {
        if (s[i] == s[i + 1])
        {
            r[i+1] = 1;
        }
    }

    int last;
    int le[n + 1] = {};
    int ri[n + 1] = {};

    last = n;

    RF(i, n, 0)
    {
        le[i] = last;
        if (l[i] == 1)
            last = i;
    }

    last = 0;

    F(i, 0, n)
    {
        ri[i] = last;
        if (r[i] == 1)
            last = i;
    }

    // F(i,0,n)
    // {
    //     cout<<ri[i]<<" "<<le[i];
    //     cout<<"\n";
    // }

    F(i, 0, n)
    {
        int p = ri[i], q = le[i];

        int x = 1;
        // int q, w;
        if (i > 0)
            if (s[i - 1] == 'L')
            {
                x += i - ri[i];
                // if(i==n)dbg(i - ri[i]);
            }
        if (i < n)
            if (s[i] == 'R')
            {
                x += -i + le[i];
                // if(i==n)dbg(le[i]-i);
            }

        cout << x << " ";
    }

    cout << "\n";
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
    int _t = 1;
    cin >> _t;
    for (int i = 1; i <= _t; i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve_LOL();
    }
    return 0;
}