// JAI BAJARANG BALI

// manitianajay45

// give me some sunshine, give me some rain , give me another chance to grow up once again....

// sab moh maya hai....


/*
dijkastra.

*/


#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
ll n,m;


vector<pair<ll,ll>> graph[200005];
vector<bool> visited(200005, false);


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // ll n;
    cin >> n>>m;

    for (ll i = 0; i <m; i++)
    {
        ll u, v,c;
        cin >> u >> v>>c;
        graph[u].push_back({v,c});
        graph[v].push_back({u,c});
        
    }   
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,1});
    ll ans=0;
    while(!pq.empty()){
        pair<ll,ll> pr=pq.top();
        pq.pop();

        if(visited[pr.second]){
            continue;
        }
        visited[pr.second]=true;
        ans+=pr.first;

        for(auto i:graph[pr.second]){
            if(!visited[i.first]){
                pq.push({i.second,i.first});
            }
        }
    }
    for(ll i=1;i<=n;i++){
        if(!visited[i]){
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
    }
    cout<<ans<<endl;



    return 0;
}
