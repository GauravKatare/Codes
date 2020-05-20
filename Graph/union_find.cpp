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
pair<ll,ll> parent[200005];
vector<pair<ll,pair<ll,ll> > >v;
vector<ll>vv[200005];

ll finds(ll a)
{
	while(a!=parent[a])
	{
		a=parent[a];
	}
	return a;	
}	

void unions(ll x,ll y)
{
	if(parent[x].se>parent[y].se)
		parent[y].fi=x;
	else if(parent[x].se<parent[y].se)
		parent[x].fi=y;
	else
	{
		parent[x].fi=y;
		parent[x].se++;
	}
}
	
void solve()
{
	ll sum=0,n,m,i,a,b,c;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		parent[i].fi=i;
		parent[i].se=0;
	}
	for(i=0;i<m;i++)
	{
		cin>>a>>b>>c;
		v.pb(mp(c,mp(a,b)));
	}
	sort(v.begin(),v.end());
	for(i=0;i<sz(v);i++)
	{
		ll a=v[i].se.fi,b=v[i].se.se;
		if(finds(a)!=finds(b))
		{
			vv[a].pb(b);
			vv[b].pb(a);
			unions(finds(a),finds(b));
			sum+=v[i].fi;
		}
	}
	cout<<sum<<"\n";
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
