#include <bits/stdc++.h>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ass 1e18
#define MOD 998244353
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

ll modpower(ll a,ll b,ll c)
{
	ll res=1;
	while(b)
	{
		if(b&1LL)
			res=(res*a)%c;
		a=(a*a)%c;
		b>>=1;
	}
	return res;
}

struct matrix
{
#define SZ 2 // change here for matrix size
	ll ar[SZ][SZ];
	void reset()
	{
		memset(ar,0,sizeof(ar));
	}
	void makeidentity()
	{
		for(int i=0;i<SZ;i++)
		{
			for(int j=0;j<SZ;j++)
			{
				if(i==j)
					ar[i][j]=1;
				else
					ar[i][j]=0;
			}
		}
	}
	matrix operator +(const matrix &o)// operator overloading of +
	{
		matrix res;
		for(int i=0;i<SZ;i++)
		{
			for(int j=0;j<SZ;j++)
			{
				res.ar[i][j] = (ar[i][j] +o.ar[i][j])%MOD;
			}
		}
		return res;
	}
	matrix operator *(const matrix &o)// operator overloading of *
	{
		matrix res;
		res.reset();
		for(int i=0;i<SZ;i++)
		{
			for(int j=0;j<SZ;j++)
			{
				for(int k=0;k<SZ;k++)
				{
					res.ar[i][j]=(res.ar[i][j]+(ar[i][k]*o.ar[k][j])%MOD)%MOD;
				}
			}
		}
		return res;
	}
	matrix power(matrix a,ll b)
	{
		matrix res;
		res.makeidentity();
		while(b)
		{
			if(b&1)
			{
				res=res*a;
			}
			a=a*a;
			b>>=1;
		}
		return res;
	}
};

void solve()
{
	ll n,a,b,c,d,e,f;
	cin>>n>>a>>b>>c>>d>>e>>f;
	matrix m;
	b=b%MOD;a=a%MOD;
	m.ar[0][0]=e%MOD,m.ar[0][1]=f%MOD;
	m.ar[1][0]=1,m.ar[1][1]=0;	
	m=m.power(m,n-1);
	ll ans1=(((b*m.ar[0][0])%MOD)+((a*m.ar[0][1])%MOD))%MOD,ans2=c^d;
}

int main()
{
	boost
	ll t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}

