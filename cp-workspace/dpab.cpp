/**
 *    author:  Aryan Agarwal
 *    created: 23.07.2022 12:27:35 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,m;
	cin>>n>>m;

	vector<pair<int,int> > v(n+1);
	for(int i=1;i<=n;i++){
		cin>>v[i].first>>v[i].second;
	}

	int dp[n+2][m+1][2]={};
	int par[n+2][m+1][2]={};

	dp[n+1][0][0]=1;
	dp[n+1][0][1]=1;

	for(int i=n;i>=1;i--){
		for(int j=0;j<=m;j++){
			if(j-v[i].first>=0 && dp[i+1][j-v[i].first][0]==1){
				dp[i][j][0]=1;
				par[i][j][0]=0;
			}
			else if(j-v[i].first>=0 && dp[i+1][j-v[i].first][1]==1){
				dp[i][j][0]=1;
				par[i][j][0]=1;
			}
			if(j-v[i].second>=0 && dp[i+1][j-v[i].second][0]==1){
				dp[i][j][1]=1;
				par[i][j][1]=0;
			}
			else if(j-v[i].second>=0 && dp[i+1][j-v[i].second][1]==1){
				dp[i][j][1]=1;
				par[i][j][1]=1;
			}
		}
	}

	if(dp[1][m][0]==0 && dp[1][m][1]==0){
		cout<<"NO\n";
		return;
	}

	int id=0;
	string ans(n,'0');

	if(dp[1][m][0]==0)id=1;

	int pos=1;
	while (pos<=n)
	{
		ans[pos-1]='0'+id;

		int next = par[pos][m][id];

		int use=v[pos].first;
		if(id==1)use=v[pos].second;

		m-=use;
		pos++;
		id=next;
	}

	cout<<"YES\n";
	cout<<ans<<"\n";

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