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
ll bittree[50005],arr[50005],n;

ll getSum(ll index) 
{ 
	ll sum=0;
	index=index+1; 
	while(index>0) 
	{ 
		sum+=bittree[index]; 
		index-=index&(-index);// ancestor
	} 
	return sum; 
} 

void updateBIT(ll n,ll index,ll val) 
{  
	index=index+1;//index in bittree[] is 1 more than the index in arr[]
	while(index<=n) 
	{ 
		bittree[index]+=val; 
		index+=index&(-index);//next element
	} 
} 

void build(ll n) 
{ 
	for(ll i=0;i<n;i++) 
		updateBIT(n, i, arr[i]); 
	return; 
} 

void solve()
{
	ll q,a,b,c;
	cin>>n>>q;
	for(ll i=0;i<n;i++)
		cin>>arr[i];
	build(n);
	while(q--)
	{
		cin>>a>>b>>c;
		if(a==2)
			updateBIT(n,b,c);//Update BIT for change in arr[3] 
		else
			cout<<getSum(c)-getSum(b-1)<<"\n";//sum of element from arr[0..5]
	}	
}

int main() 
{ 
	boost
	ll t=1;
	while(t--)
	{
		solve();
	}
	return 0;
} 
