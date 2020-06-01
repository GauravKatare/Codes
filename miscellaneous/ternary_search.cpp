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
double h,c,t;

double sol(double x)
{
	double a=h*x;
	double b=c*(x-1);
	return abs(t-(a+b)/(2*x-1));
}

ll ternary_search(ll l,ll h) 
{
	double ans=1e6;
	ll ind=h;
	while(h-l>=3)
	{
		ll mid1=l+(h-l)/3;
		ll mid2=h-(h-l)/3;
		if(sol(mid1)>sol(mid2))
			l=mid1;
		else
			h=mid2;
	}
	// check for range l to h
	for(ll i=l;i<=h;i++)
	{
		if(ans>sol(i))
		{
			ans=min(ans,sol(i));
			ind=2*i-1;
		}
	}
	return ind;
}

void solve()
{
	cin>>h>>c>>t;
	cout<<ternary_search(1,1e6)<<"\n";
}

int main()
{
	boost
	ll t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}