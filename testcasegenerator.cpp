#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long int ll;
#define ass 1e18
#define MOD 1000007
#define mp make_pair
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define fi first
#define se second
#define sz(x)	(ll)x.size()
#define present(c,x) ((c).find(x) != (c).end())
#define debug(x) cout << #x << ": " << x << endl;
#define debug2(x,y) cout<<#x<<": "<< x<< ", "<< #y<< ": "<< y<< endl;
#define debug3(x,y,z) cout<<#x<<": "<< x<< ", "<< #y<< ": "<< y<<" "<<#z<<" : "<<z<< endl;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;   
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>

ll cal()
{
	ll a=rand()%MOD+1;
	ll b=rand()%MOD+1;
	//debug(a*b);
	return a*b;
}

void solve()
{
	ll q=100000; 
	cout<<q<<"\n"; 
	srand(time(0));                      
	for(int i=1;i<=q;i++)
	{
		ll n,a=1,b=1;
		while(a==b)
		{
			n=cal()+1;
			a=cal()%10+1;
			b=cal()%10+1;
		}
		cout<<n<<" "<<a<<" "<<b<<"\n";
	}
}

int main()
{
	boost
	freopen("input.txt", "w", stdout);
	ll t=1;
	while(t--)
	{
		solve();
	}
	return 0;
}