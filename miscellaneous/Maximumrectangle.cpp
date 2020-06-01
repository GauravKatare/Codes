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
ll large(ll arr[],ll n)
{
	ll i=0,temp,sum=0,maxi=0;
	stack<ll>s;
	while(i<n)
	{
		if(s.empty()||arr[s.top()]<=arr[i])
		{
			s.push(i);
			i++;
		}
		else
		{
			temp=s.top();
			s.pop();
			if(!s.empty())
				sum=arr[temp]*(i-s.top()-1);
			else
				sum=arr[temp]*(i);	
			maxi=max(maxi,sum);
		}
	}
	while(!s.empty())
	{
		temp=s.top();
		s.pop();
		if(!s.empty())
			sum=arr[temp]*(i-s.top()-1);
		else
			sum=arr[temp]*(i);	
		maxi=max(maxi,sum);
	}
	return maxi;
}

int main()
{
	ll t,n,i;
	cin>>t;
	while(t--)
	{
		cin>>n;
		ll arr[n+1];
		memset(arr,0,sizeof(arr));
		for(i=0;i<n;i++)
			cin>>arr[i];
		cout<<large(arr,n)<<"\n";
	}
	return 0;
}