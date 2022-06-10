// JAI BAJARANG BALI

// manitianajay45

// give me some sunshine, give me some rain , give me another chance to grow up once again....

// sab moh maya hai....

/*
steps:-

firstly merge all the strongly connected componenets and now graph is DAG .
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
ll n,m;

vector<bool> visited(200005,false);
vector<ll> graph[200005];
vector<ll> order;
vector<ll> graphr[200005];
set<ll> gph[200005];
vector<ll> vis(200005,0);
vector<ll> vec(200005,0);

ll an=0;
ll weight[200005];
ll val=0;

vector<ll> ans(200005,-1);


void topo(ll v){
    visited[v]=true;
    for(auto u:graph[v]){
        if(!visited[u]){
            topo(u);
        }
    }
    order.push_back(v);
}
bool flag=true;

void dfs(ll v){
//    cout<<v<<" ";
    vis[v]=an;
    val+=weight[v];
    for(auto u:graphr[v]){
        if(vis[u]==0){
            dfs(u);
        }else if(vis[u]!=an){
            gph[vis[u]].insert(an);
        }
        
    }

}


ll mx=0;

ll ansfunc(ll v){
    if(ans[v]!=-1){
        return ans[v];
    }
    visited[v]=true;
    ans[v]=vec[v];
    for(auto u:gph[v]){
        // if(!visited[u]){
            ans[v]=max(ans[v],vec[v]+ansfunc(u));
        // }
    }
    return ans[v];
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // ll n;
    cin >> n>>m;

    for(ll i=1;i<=n;i++){
        cin>>weight[i];
    }

    vector<pair<ll,ll>> edges;

    for (ll i = 0; i < m; i++)
    {
        ll u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graphr[v].push_back(u);
        edges.push_back({u,v});
       
    }
    for(ll i=1;i<=n;i++){
        if(!visited[i]){
            topo(i);
        }
    }

    reverse(order.begin(),order.end());

    // vec.push_back(0);
    for(auto i:order){
        if(vis[i]==0){
            an++;
            val=0;
            dfs(i);
            vec[an]=val;
        
        }
    }
    
    for(ll i=1;i<=an;i++){
        if(ans[i]==-1){
            // cout<<i<<" ";
            mx=max(mx,ansfunc(i));
            // cout<<ansfunc(i)<<endl;````````````````````
        }
    }
    cout<<mx<<endl;
    

    return 0;
}
