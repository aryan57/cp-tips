/**
 *    author:  Aryan Agarwal
 *    created: 23.07.2022 13:41:47 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
int n,k;
int a[20];
int ans=0;

void dp(int start,vector <int> &ava,int sum){
	if(start==n){
		ans=max(ans,sum);
		return;
	}

	for(int i=0;i<k;i++){
		if(ava[i]==0)continue;
		ava[i]--;
		dp(start+1,ava,sum+(a[start]&(i+1)));
		ava[i]++;
	}

}

void solve()
{
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	vector <int> val(k);
	vector <int> ava(k);

	for(int i=0;i<k;i++){
		ava[i]=2;
		val[i]=i+1;
	}

	ans=0;
	dp(0,ava,0);
	cout<<ans;
	cout<<"\n";
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
