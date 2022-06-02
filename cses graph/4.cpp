// JAI BAJARANG BALI
 
// manitianajay45
 
// give me some sunshine, give me some rain ,give me another chance to grow up once again....
 
// sab moh maya hai....
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll int
 
ll n, m;
 
vector<ll> graph[100005];
 
vector<bool> visited(100005, false);
 
int main()
{
    cin >> n >> m;
 
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
 
    queue<ll> q;
    q.push(1);
    vector<ll> par(n + 1, -1);
 
    while (!q.empty())
    {
        ll u = q.front();
 
        q.pop();
        if(u==n){
            break;
        }
        
        visited[u] = true;
 
        for (auto i : graph[u])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i]=true;
                par[i] = u;
            }
        }
    }
 
    if(par[n]==-1){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
 
    ll val=n;
    vector<ll> vec;
    while(val!=1){
        vec.push_back(val);
        val=par[val];
    }
    vec.push_back(1);
    reverse(vec.begin(),vec.end());
    cout<<vec.size()<<endl;
 
    for(auto i:vec){
        cout<<i<<" ";
    
    }
    
 
    
 
    return 0;
}
