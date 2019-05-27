#include<bits/stdc++.h>
using namespace std;
typedef long long int ll ;
#define m 1000000007
ll n,ans;
vector<ll>v[105];
ll dp[1500][105];

ll solve(ll bit,ll l)
{
	if(bit==ans)
		return 1;
	if(l>100)
		return 0;
	if(dp[bit][l]!=-1)
		return dp[bit][l];
	ll sum,tmp,j;
	sum=solve(bit,l+1)%m;
	for(j=0;j<v[l].size();j++)
	{
		tmp=1<<v[l][j];
		if(!(tmp&bit))
			sum=(sum+solve(tmp|bit,l+1)%m)%m;
	}	
	dp[bit][l]=sum%m;
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t,i,max,j;
	cin>>t;
	string str,ss;
	i=0;
	while(t--)
	{
		memset(dp,-1,sizeof(dp));
		for(i=0;i<105;i++)
			v[i].clear();
		cin>>n;
		ans=(1<<n)-1;
		getline(cin,str);
		for(j=0;j<n;j++)
		{
			getline(cin,str);
			stringstream s(str);
			while (s>>ss)
      			v[stoi(ss)].push_back(j);
		}
		cout<<solve(0,1)<<"\n";
	}	
	return 0;
}