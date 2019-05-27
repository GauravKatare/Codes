#include <bits/stdc++.h>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ass 1e18
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);
#define debug(x) cout << #x << ": " << x << endl;
#define debug2(x,y) cout<<#x<<": "<< x<< ", "<< #y<< ": "<< y<< endl;
#define debug3(x,y,z) cout<<#x<<": "<< x<< ", "<< #y<< ": "<< y<<" "<<#z<<" : "<<z<< endl;
using namespace std;
typedef long long int ll;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;   
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
ll n,d,p,dp[100005][105][2];
string arr;

ll dfs(ll x,ll sum,ll f)
{
	ll ans=0,i,l;
	if(x==arr.size())
	{
		if(sum%d==0) 
			return 1;
		return 0;
	}
	if(dp[x][sum][f]!=-1)
		return dp[x][sum][f];
	if(f==1)
	{
		ans=dfs(x+1,(sum+(arr[x]-48))%d,1);
		for(i=0;i<arr[x]-48;i++)
			ans=(ans+dfs(x+1,(sum+i)%d,0))%MOD;
	}
	else
	{
		for(i=0;i<=9;i++)
			ans=(ans+dfs(x+1,(sum+i)%d,0))%MOD;		
	}	
	dp[x][sum][f]=ans%MOD;
	return dp[x][sum][f];
}

int main()
{
	boost
	memset(dp,-1,sizeof(dp));
	cin>>arr>>d;
	dp[0][0][0]=dfs(0,0,1)%MOD;
	cout<<(dp[0][0][0]-1+MOD)%MOD;
	return 0;
}