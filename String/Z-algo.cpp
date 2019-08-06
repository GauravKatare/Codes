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
ll arr[1000005];

void getZarr(string str)
{
	ll i,l,k,h,n=str.size();
	reverse(str.begin(),str.end());
	arr[0]=n;
	h=0;
	l=0;
	for(i=1;i<n;i++)
	{
		if(i>h)
		{
			l=i;h=i;
			while(h<n&&str[h]==str[h-i])
			{
				h++;
			}
			arr[l]=h-l;
			h--;
		}
		else
		{
			k=i-l;
			if(arr[k]<h-i+1)
				arr[i]=arr[k];
			else
			{
				l=i;
				while(h<n&&str[h-l]==str[h])
				{
					h++;
				}
				arr[i]=h-l;
				h--;
			}
		}
	}
}

int main()
{
	boost
	ll t,n,q;
	string str;
	cin>>t;
	while(t--)
	{
		cin>>str;
		getZarr(str);
		cin>>q;
		while(q--)
		{
			cin>>n;
			cout<<arr[str.size()-n]<<"\n";
		}
	}
	return 0;
}	
