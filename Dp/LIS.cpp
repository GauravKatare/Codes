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

ll solve(ll l,ll h,ll temp[],ll arr[],ll x)
{
	ll mid,ans;
	while(l<=h)
	{
		mid=(l+h)/2;
		if(arr[temp[mid]]>=arr[x])
		{
			ans=mid;
			h=mid-1;
		}
		else
			l=mid+1;
	}
	return ans;
}

void print(ll x,ll arr[],ll res[])
{
	vector<ll>v;
	while(res[x]!=-1)
	{
		v.pb(arr[x]);
		x=res[x];
	}
	v.pb(arr[x]);
	sort(v.begin(),v.end());
	for(ll i=0;i<v.size();i++)
		cout<<v[i]<<" ";
	cout<<"\n";
}

ll lis(ll l,ll h,ll arr[])
{
	ll i,res[h-l],temp[h-l],len=0;
	memset(res,-1,sizeof(res));
	memset(temp,0,sizeof(temp));
	temp[l]=0;
	for(i=l+1;i<=h;i++)
	{
		if(arr[temp[l]]<arr[i]&&arr[temp[len]]>arr[i])
		{
			ll ans=solve(l,len,temp,arr,i);
			temp[ans]=i;
			res[i]=temp[ans-1];
		}
		else if(arr[i]>arr[temp[len]])
		{
			len++;
			temp[len]=i;
			res[i]=temp[len-1];
		}
		else if(arr[i]<arr[temp[0]])
			temp[0]=i;
	}
	//print(temp[len],arr,res);
	return len+1;
}

int main()
{
	boost
	ll i,n,t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		ll arr[n];
		for(i=0;i<n;i++)
			cin>>arr[i];
		cout<<lis(0,n-1,arr)<<"\n";	
	}
	return 0;
}