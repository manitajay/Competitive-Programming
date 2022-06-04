// JAI BAJARANG BALI

// manitianajay45

// give me some sunshine, give me some rain, give me another chance to grow up once again....

// sab moh maya hai....

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n, m;

void dijkastra(vector<vector<pair<ll, ll>>> graph, vector<ll> &shortest,ll nd)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, nd});

    while (!pq.empty())
    {
        pair<ll, ll> p = pq.top();
        pq.pop();
        if (shortest[p.second] == -1)
        {
            shortest[p.second] = p.first;
            for (auto i : graph[p.second])
            {
                if (shortest[i.first] == -1)
                {
                    pq.push({i.second + p.first, i.first});
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;

    vector<vector<pair<ll, ll>>> graphf(n+1);
    vector<vector<pair<ll, ll>>> graphr(n+1);
    vector<ll> shortestf(n+1, -1);
    vector<ll> shortestr(n+1, -1);
    vector<pair<pair<ll,ll>,ll>> edges;
    for (ll i = 0; i < m; i++)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        graphf[u].push_back({v, c});
        graphr[v].push_back({u, c});
        edges.push_back({{u,v},c});
    }
    dijkastra(graphf,shortestf,1);
    dijkastra(graphr,shortestr,n);

    // for(ll i=1;i<=n;i++){
    //     cout<<shortestf[i]<<" ";
    // }
    // cout<<endl;

    
    // for(ll i=1;i<=n;i++){
    //     cout<<shortestr[i]<<" ";
    // }
    // cout<<endl;
    ll ans=shortestf[n];
    for(auto i:edges){
        if(shortestf[i.first.first]!=-1 && shortestr[i.first.second]!=-1){
        ll val=shortestf[i.first.first]+shortestr[i.first.second]+(i.second)/2;
        
        ans=min(ans,val);}
    }
    cout<<ans<<endl;

    return 0;
}
