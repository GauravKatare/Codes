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
stack<ll>s;
vector<ll>v[100005],r[100005],p[100005];
ll vis[100005],k,cnt;

void dfs(ll x)
{
    cnt++;
    vis[x]=1;
    ll i;
    for(i=0;i<v[x].size();i++)
    {
        if(vis[v[x][i]]==0)
            dfs(v[x][i]);
    }
    s.push(x);
}

void dfs2(ll x)
{
    p[k].pb(x);
    vis[x]=1;
    ll i;
    for(i=0;i<r[x].size();i++)
    {
        if(vis[r[x][i]]==0)
            dfs2(r[x][i]);
    }
}

int main()
{
    ll n,m,sum,ans,a,b,t,i;
    cin>>t;
    while(t--)
    {
        k=0;
        cin>>n>>m;
        for(i=0;i<=n;i++)
        {
            v[i].clear();
            r[i].clear();
            p[i].clear();
        }
        for(i=0;i<m;i++)
        {
            cin>>a>>b;
            v[b].pb(a);
            r[a].pb(b);
        }
        memset(vis,0,sizeof(vis));
        for(i=1;i<=n;i++)
        {
            if(vis[i]==0)
                dfs(i);
        }
        memset(vis,0,sizeof(vis));
        while(!s.empty())
        {
            if(vis[s.top()]==0)
            {
                dfs2(s.top());
                k++;
            }
            s.pop();
        }
        memset(vis,0,sizeof(vis));
        i=0;
        ans=0;
        cnt=0;
        while(cnt<n)
        {
            if(vis[p[i][0]]==0)
            {
                dfs(p[i][0]);
                p[k].pb(p[i][0]);
                ans++;
            }
            i++;
        }
        sort(p[k].begin(),p[k].end());
        cout<<ans<<"\n";
        for(ll j=0;j<ans;j++)
            cout<<p[k][j]<<" ";
        cout<<"\n";
    }
    return 0;
}