
#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long
#define mod 1000000007

vector<ll> graph[200005];
vector<bool> visited(200005, false);
ll ans=0;
ll mxx=0;
ll prv=0;
ll v1,v2;

vector<pair<ll,ll>> vec;
void dfs(ll v)
{
    visited[v] = true;
    ll x=0;

    bool flag=false;
    for (auto u : graph[v])
    {
        if (!visited[u])
        {
            mxx++;

            vec.push_back({mxx,u});

            dfs(u);
            mxx--;
        }
    }
}

bool flag=false;

void dfss(ll v){
    if(flag){
        return ;
    }
    visited[v]=true;
    for(auto u:graph[v]){
        if(!visited[u]){
            mxx++;
            ans=max(ans,mxx);
            dfss(u);
            mxx--;
        }
    }
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
        graph[v].push_back(u);
        
    }
    
    dfs(1);
    vec.push_back({1,0});
    sort(vec.begin(),vec.end());
    auto it=vec.end();
    it--;
    v1=it->second;
    
    mxx=0;
    visited.assign(n+1,false);
    // cout<<v1<<" "<<v2<<endl;
    dfss(v1);
    
    cout << ans << endl;

    return 0;
}
