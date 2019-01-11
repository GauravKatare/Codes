#include <bits/stdc++.h>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ass 100000000000000000
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);
#define debug(x) cout << #x << ": " << x << endl;
#define debug2(x,y) cout<<#x<<": "<< x<< ", "<< #y<< ": "<< y<< endl;
#define debug3(x,y,z) cout<<#x<<": "<< x<< ", "<< #y<< ": "<< y<<#z<<" : "<<z<< endl;
using namespace std;
using namespace __gnu_pbds;
typedef long long int ll;
#define ordered_set tree<int>,null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update>

ll power(ll a,ll b,ll m)
{
	if(b==0)
		return 1;
	else if(b==1)
		return a%m;
	ll dp=power(a,b/2,m)%m;
	if(b%2==0)			
		return (dp*dp)%m;
	else
		return (((dp*dp)%m)*a)%m;	
}

int main()
{
	return 0;
}