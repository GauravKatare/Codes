void dijkstra(ll x)
{
	ll i;
	for(i=1;i<=n;i++)
		dp[i]=ass;
	priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > >q;
	q.push(mp(0,x));
	dp[x]=0; 
	while(!q.empty())
	{
		ll a=q.top().fi;
		ll b=q.top().se;
		q.pop();
		if(a!=dp[b])
			continue;
		for(i=0;i<v[b].size();i++)
		{
			if(dp[b]+v[b][i].fi<dp[v[b][i].se])
			{
				dp[v[b][i].se]=dp[b]+v[b][i].fi;
				q.push(mp(dp[v[b][i].se],v[b][i].se));	
			}
		}
	}
}
