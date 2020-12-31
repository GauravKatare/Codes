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
ll arr[100005],lazy[400005],n,tree[400005];

void build(ll node,ll start,ll end)
{
	if(start==end){
		tree[node]=arr[start];
		return;
	}
	ll mid=(start+end)/2;
    build(2*node+1,mid+1,end);
    build(2*node,start,mid);
	tree[node]=tree[2*node]+tree[2*node+1];
	return st[node];
}

void update(ll node,ll start,ll end,ll l,ll r,ll val)
{
    if(lazy[node]!=0)
    { 
        tree[node]+=(end-start+1)*lazy[node];
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
        tree[node]+=(end-start+1)*val;
        if(start!=end){
            lazy[node*2]+=val;
            lazy[node*2+1]+=val;
        }
        return;
    }
    ll mid =(start+end)/2;
    updateRange(node*2,start,mid,l,r,val);        
    updateRange(node*2+1,mid+1,end,l,r,val);  
    tree[node]=tree[node*2]+tree[node*2+1];        
}

ll getans(ll node,ll start,ll end,ll l,ll r)
{
    if(start>end||start>r||end<l)
        return 0;         
    if(lazy[node]!=0)
    {
        tree[node]+=(end-start+1)*lazy[node];
        if(start!=end){
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node] = 0;                
    }
    if(start>=l&&end<=r)        
        return tree[node];
    ll mid=(start+end)/2;
    ll p1=queryRange(node*2,start,mid,l,r);
    ll p2=queryRange(node*2+1,mid+1,end,l,r); 
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
