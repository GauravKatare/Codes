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
ll rev[100005];

void solve()
{
	string str;
	cin>>str;
	ll i,n=str.size(),cnt=0;
	ll pre[n+5];
	pre[0]=0;
	for(i=1;i<=n;i++)
		pre[i]=(pre[i-1]+(rev[i]*(str[i-1]-'a'+1))%MOD)%MOD;
	for(i=1;i<d;i++)
	{
		ll sum=(pre[2*i]-pre[i]+MOD)%MOD; // hash of range i to 2*i
		ll p=(pre[i]*rev[i])%MOD;// hash of range i to 2*i
	}
	cout<<cnt<<"\n";
}

int main()
{
	boost
	ll t=1;
	rev[0]=1;
	for(ll i=1;i<=100005;i++)
		rev[i]=(rev[i-1]*33)%MOD;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
