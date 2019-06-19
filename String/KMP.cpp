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

vector<ll> substring(string text,string pattern,vector<ll> &lpa)
{
	vector<ll> ans;
	ll i=0,j=0;
	while(i<text.size())
	{
		if(j==pattern.size())
		{
			ans.pb(i-j);
			j=lpa[j-1];
		}
		if(text[i]==pattern[j])
		{
			i++;
			j++;
		}
		else
		{
			if(j==0)
				i++;
			else
				j=lpa[j-1];
		}
	}
	if(j==pattern.size())
		ans.pb(i-j);
	return ans;
}

vector<ll> preprocessor(string pattern)
{
	ll i=1,j=0;
	vector<ll> lpa(pattern.size());
	lpa[0]=0;
	while(i<pattern.size())
	{	
		if(pattern[i]==pattern[j])
		{
			j++;
			lpa[i]=j;
			i++;
		}
		else
		{
			if(j!=0)
				j=lpa[j-1];
			else
			{
				lpa[i]=0;
				i++;
			}
		}
	}
	//for(i=0;i<lpa.size();i++)
	//	debug2(i,lpa[i]);
	return lpa;
}

int main()
{
	boost
	string text,pattern;
	cin>>text>>pattern;
	vector<ll> lpa=preprocessor(pattern);
	vector<ll> ans=substring(text,pattern,lpa);
	for(ll i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	return 0;
}