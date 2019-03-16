#include <bits/stdc++.h>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ass 100000000000000000
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);
#define debug(x) cout << #x << ": " << x << endl;
#define debug2(x,y) cout<<#x<<": "<< x<< ", "<< #y<< ": "<< y<< endl;
#define debug3(x,y,z) cout<<#x<<": "<< x<< ", "<< #y<< ": "<< y<<#z<<" : "<<z<< endl;
using namespace std;
using namespace __gnu_pbds;
typedef long long int ll;
#define ordered_set tree<int>,null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update>
ll n,vis[1000005],parent[1000005],flag;
vector<ll>v[1000005],ans;

ll cmp(ll a,ll b)
{
	if(a>=b)
		return 1;
	return 0;
}

void dfs(ll x)
{
	if(vis[x]==0)
	{
		vis[x]=1;
		sort(v[x].begin(),v[x].end(),cmp);
		for(ll i=0;i<v[x].size();i++)
			dfs(v[x][i]);
		vis[x]=2;
		ans.pb(x);
	}
	else if(vis[x]==1)
		flag=1;
}	

int main()
{
	boost
	ll i,m,n,a,b;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		parent[i]=i;
	for(i=0;i<m;i++)
	{
		cin>>a>>b;
		v[a].pb(b);	
	}
	for(i=n;i>=1;i--)
	{
		if(vis[i]==0)
			dfs(i);
	}	
	reverse(ans.begin(),ans.end());
	if(flag==0)
	{
		for(i=0;i<ans.size();i++)
			cout<<ans[i]<<" ";
	}
	else
		cout<<"Sandro fails.";	
	return 0;
}