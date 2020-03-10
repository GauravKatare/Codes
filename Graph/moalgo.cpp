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
ll arr[200005],ans[200005],rev[200005],hass[200005],l,h,n,maxi=100005;
 
bool compare(pair< pair<ll,ll>, ll> q1,pair< pair<ll,ll>, ll> q2) 
{ 
	int block=sqrt(n);
    if (q1.fi.fi/block != q2.fi.fi/block) 
        return q1.fi.fi/block < q2.fi.fi/block; 
    return q1.fi.se <q2.fi.se; 
}  

ll sol(ll a,ll b)
{
	while(l<a) 
    { 
    	hass[rev[arr[l]]]--;
        rev[arr[l]]--;
        hass[rev[arr[l]]]++;
        if(!hass[maxi])
        	maxi--;
        l++; 
    } 
	while(l>a) 
    { 
    	hass[rev[arr[l-1]]]--;
        rev[arr[l-1]]++;
        hass[rev[arr[l-1]]]++;
        if(hass[maxi+1])
        	maxi++;
        l--; 
    }
    while(h<=b) 
    { 
    	hass[rev[arr[h]]]--;
    	rev[arr[h]]++; 
        hass[rev[arr[h]]]++;
        if(hass[maxi+1])
        	maxi++;
        h++; 
    } 
	while(h>b+1) 
    { 
        hass[rev[arr[h-1]]]--;
        rev[arr[h-1]]--;
        hass[rev[arr[h-1]]]++;
        if(!hass[maxi])
        	maxi--; 
        h--; 
    }
    return maxi-100005;
}



int main()
{
	boost
	ll q,i,a,b;
	cin>>n>>q;
	vector<pair< pair<ll,ll>, ll> > v;
	for(i=0;i<n;i++)
		cin>>arr[i];
	for(i=1;i<=q;i++)
	{
		cin>>a>>b;
		v.pb(mp(mp(a,b),i));
	}
	for(i=0;i<=100000;i++)
		rev[i]=100005;
	sort(v.begin(),v.end(),compare);
	for(i=0;i<v.size();i++)
		ans[v[i].se]=sol(v[i].fi.fi,v[i].fi.se);
	for(i=1;i<=q;i++)
		cout<<ans[i]<<"\n";
	return 0;
} 