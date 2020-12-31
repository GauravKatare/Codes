#include <bits/stdc++.h>
#include <algorithm>
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
#define ordered_set st<ll, null_type,less<ll>, rb_st_tag,st_order_statistics_node_update>
ll arr[100005],lazy[400005],n,st[400005];

void build(ll node,ll start,ll end)
{
	if(start==end){
		st[node]=arr[start];
		return;
	}
	ll mid=(start+end)/2;
    build(2*node+1,mid+1,end);
    build(2*node,start,mid);
	st[node]=st[2*node]+st[2*node+1];
	return;
}

void update(ll node,ll start,ll end,ll l,ll r,ll val)
{
    if(lazy[node]!=0)
    { 
        st[node]+=(end-start+1)*lazy[node];
        if(start != end){
            lazy[node*2]+=lazy[node];                  
            lazy[node*2+1]+=lazy[node];                
        }
        lazy[node] = 0;                                 
    }
    if(start>end||start>r||end<l)          
        return;
    if(start>=l&&end<=r)
    {
        st[node]+=(end-start+1)*val;
        if(start!=end){
            lazy[node*2]+=val;
            lazy[node*2+1]+=val;
        }
        return;
    }
    ll mid =(start+end)/2;
    update(node*2,start,mid,l,r,val);        
    update(node*2+1,mid+1,end,l,r,val);  
    st[node]=st[node*2]+st[node*2+1];        
}

ll getans(ll node,ll start,ll end,ll l,ll r)
{
    if(start>end||start>r||end<l)
        return 0;         
    if(lazy[node]!=0)
    {
        st[node]+=(end-start+1)*lazy[node];
        if(start!=end){
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node] = 0;                
    }
    if(start>=l&&end<=r)        
        return st[node];
    ll mid=(start+end)/2;
    ll p1=getans(node*2,start,mid,l,r);
    ll p2=getans(node*2+1,mid+1,end,l,r); 
    return (p1+p2);
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
