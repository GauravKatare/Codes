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
ll arr[100005],lazy[400005],n,st[400005];

ll build(ll q,ll l,ll h)
{
	if(l==h)
	{
		st[q]=arr[l];
		return st[q];
	}
	ll mid=(l+h)/2;
	st[q]=build(2*q,l,mid)+build(2*q+1,mid+1,h);
	return st[q];
}

ll getans(ll q,ll o,ll e,ll l,ll h)
{
	ll ans=0;
	if(lazy[q]!=-1)
	{
		st[q]=max(st[q],1ll)*lazy[q];
		if(l!=h)
		{
			lazy[2*q]=max(lazy[2*q],1ll)*lazy[q];
			lazy[2*q+1]=max(lazy[2*q+1],1ll)*lazy[q];
		}
		lazy[q]=-1;
	}
	if(l>=o&&h<=e)
		return st[q];
	if(e<l||o>h)
		return ans;
	if(l!=h)
	{
		ll mid=(l+h)/2;
		ans=getans(2*q,o,e,l,mid)+getans(2*q+1,o,e,mid+1,h);
		return ans;
	}
}

ll update(ll q,ll o,ll e,ll l,ll h,ll diff)
{
	if(lazy[q]!=-1)
	{
		st[q]=max(st[q],1ll)*lazy[q];
		if(l!=h)
		{
			lazy[2*q]=max(lazy[2*q],1ll)*lazy[q];
			lazy[2*q+1]=max(lazy[2*q+1],1ll)*lazy[q];
		}
		lazy[q]=-1;
	}
	if(l>=o&&h<=e)
	{
		st[q]=max(st[q],1ll)*diff;
		if(l!=h)
		{
			lazy[2*q]=max(lazy[2*q],1ll)*diff;
			lazy[2*q+1]=max(lazy[2*q+1],1ll)*diff;
		}
		lazy[q]=-1;
		return st[q];
	}
	if(e<l||o>h)
		return st[q];
	ll mid=(l+h)/2;
	st[q]=update(2*q,o,e,l,mid,diff)+update(2*q+1,o,e,mid+1,h,diff);
	return st[q];
}

void solve()
{
	build(1,1,n);
}

int main()
{
	boost
	ll i,t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
