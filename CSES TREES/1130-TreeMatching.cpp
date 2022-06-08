
#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long
#define mod 1000000007

vector<ll> graph[200005];
vector<bool> visited(200005, false);
ll dp[200005][2];
vector<ll> vec;
ll ans=0;

void dfs(ll v,ll par)
{
    visited[v] = true;
    ll x=0;

    bool flag=false;
    for (auto u : graph[v])
    {
        if (!visited[u])
        {
            dfs(u,v);
            // dp[v]=dp[u];
            x+=max(dp[u][0],dp[u][1]); 
            if(dp[u][0]+1>dp[u][1] && !flag){
                flag=true;
                x++;
            } 
        }
    }
    if(flag){
        dp[v][1]=x;
        dp[v][0]=x-1;
    }else{
        dp[v][0]=x;
    }
    ans=max(ans,dp[v][0]);
    ans=max(ans,dp[v][1]);

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        // graph[u].push_back(v);
        graph[v].push_back(u);
        
    }
    
    dfs(1,0);

    
    cout << ans << endl;

    return 0;
}
