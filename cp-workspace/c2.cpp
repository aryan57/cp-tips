/**
 *    author:  Aryan Agarwal
 *    created: 23.07.2022 13:04:56 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
int n,m,k;

using pp = vector <int> ;

map<pp,int> dp;
int g[17][17];

int f(int x,int y,int rem){
	if(x==1 && y==1){
		if(g[x][y]%k==rem)return 1;
		return 0;
	}

	if(dp.count({x,y,rem}))return dp[{x,y,rem}];

	int org=rem;
	rem-=g[x][y];
	rem%=k;
	rem+=k;
	rem%=k;

	int ans=0;
	if(x>1)ans+=f(x-1,y,rem);
	if(y>1)ans+=f(x,y-1,rem);
	return dp[{x,y,org}]=ans;
}

void solve()
{
	cin>>n>>m;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>g[i][j];
		}
	}

	cin>>k;
	cout<<f(n,m,0);
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	cin>>_t;
	for (int i=1;i<=_t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}
