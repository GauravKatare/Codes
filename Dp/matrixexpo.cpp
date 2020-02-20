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
ll n,m;
ll arr[2][2],mul[2][2];
//m-1 m-1
//1 0

void multiply(ll mat1[][2],ll mat2[][2]) 
{ 
    ll i,j,k;
    ll res[2][2]; 
    for(i=0;i<=1;i++) 
    { 
        for(j=0;j<=1;j++) 
        { 
            res[i][j]=0; 
            for(k=0;k<=1;k++) 
                res[i][j]=(res[i][j]+(mat1[i][k]*mat2[k][j])%MOD)%MOD; 
        } 
    } 
    for(i=0;i<=1;i++)
    {
    	for(j=0;j<=1;j++)
    		mul[i][j]=res[i][j];
    }	
} 

void power(ll x)
{
	if(x==1)
		return;
	power(x/2);
	multiply(mul,mul);
	if(x%2==1)
		multiply(mul,arr);
}	

void solve()
{
	cin>>n>>m;
	ll a=(m-1+MOD)%MOD;
	arr[0][0]=a;arr[0][1]=a;
	arr[1][0]=1;arr[1][1]=0;
	mul[0][0]=a;mul[0][1]=a;
	mul[1][0]=1;mul[1][1]=0;	
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
