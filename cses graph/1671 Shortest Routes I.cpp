// JAI BAJARANG BALI
 
// manitianajay45
 
// give me some sunshine, give me some rain, give me another chance to grow up once again....
 
// sab moh maya hai....

// just standard dijkastra algorithms
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
ll n, m;

vector<pair<ll,ll>> graph[100005];
vector<ll> shortest(100005,-1);
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        ll u,v,c;
        cin>>u>>v>>c;
        graph[u].push_back({v,c});

    }
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,1});
 
    while (!pq.empty())
    {
        pair<ll,ll> p = pq.top();
        pq.pop();
        if(shortest[p.second]==-1){
            shortest[p.second]=p.first;
            for(auto i:graph[p.second]){
                if(shortest[i.first]==-1){
                    pq.push({i.second+p.first,i.first});
                }
            }
        }
        
    }

    for(ll i=1;i<=n;i++){
        cout<<shortest[i]<<" ";
    }
    cout<<endl;
 
    return 0;
}


