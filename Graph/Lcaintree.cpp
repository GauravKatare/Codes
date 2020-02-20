#include <bits/stdc++.h>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ass 1e18
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define fi first
#define se second
#define sz(x)	(ll)x.size()
#define present(c,x) ((c).find(x) != (c).end())
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
ll level[200005],dpp[200005][22],par[200005];
vector<ll>v[200005];

void bfs(ll x)
{
	memset(level,-1,sizeof(level));
	queue<ll>q;
	q.push(x);
	level[x]=1;
	while(!q.empty())
	{
		ll a=q.front();
		q.pop();
		for(ll i=0;i<sz(v[a]);i++)
		{
			if(level[v[a][i]]==-1)
			{
				q.push(v[a][i]);
				level[v[a][i]]=level[a]+1;
			}
		}
	}
}

ll computeparent(ll n)
{
	for(ll i=1;i<=n;i++)
		dpp[i][0]=par[i];
	for(ll j=1;j<=21;j++)
	{
		for(ll i=1;i<=n;i++)
			dpp[i][j]=dpp[dpp[i][j-1]][j-1];
	}
}

ll lca(ll a,ll b)
{
	if(level[b]>level[a])
		swap(a,b);
	ll diff=level[a]-level[b];
	for(ll i=20;i>=0;i--)
	{
		if(diff&(1LL<<i))
			a=dpp[a][i];
	}
	if(a==b)
		return a;
	for(ll i=20;i>=0;i--)
	{
		if(dpp[a][i]!=dpp[b][i])
		{
			a=dpp[a][i];
			b=dpp[b][i];
		}
	}
	return dpp[a][0];
}

void solve()
{
	ll n,a,b,q;
	cin>>n;
	memset(par,-1,sizeof(par));
	for(ll i=1;i<n;i++)
	{
		cin>>a>>b;
		par[b]=a;
		v[a].pb(b);
		v[b].pb(a);
	}
	bfs(1);
	computeparent(n);
	cin>>q;
	while(q--)
	{
		cin>>a>>b;
		debug(lca(a,b));
	}
}

int main()
{
	boost
	ll t=1;
	//cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
