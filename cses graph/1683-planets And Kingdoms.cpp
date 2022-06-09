// JAI BAJARANG BALI

// manitianajay45

// give me some sunshine, give me some rain , give me another chance to grow up once again....

// sab moh maya hai....

// kosaraju algo



#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
ll n,m;

vector<bool> visited(200005,false);
vector<ll> graph[200005];
vector<ll> order;
vector<ll> graphr[200005];
ll an=0;
vector<ll> ans(200005,0);


void topo(ll v){
    visited[v]=true;
    for(auto u:graph[v]){
        if(!visited[u]){
            topo(u);
        }
    }
    order.push_back(v);
}

void dfs(ll v){
    visited[v]=true;
    ans[v]=an;
    for(auto u:graphr[v]){
        if(!visited[u]){
            dfs(u);
        }
    }

}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // ll n;
    cin >> n>>m;

    for (ll i = 0; i <m; i++)
    {
        ll u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graphr[v].push_back(u);
       
    }
    for(ll i=1;i<=n;i++){
        if(!visited[i]){
            topo(i);
        }
    }
    // cout<<"YES"<<endl;
    visited.assign(n+1,false);
    reverse(order.begin(),order.end());
    // for(auto i:order){
        // cout<<i<<" ";
    // }
    cout<<endl;
    for(auto i:order){
        // cout<<i<<" ";
        if(!visited[i]){
            an++;
            dfs(i);
        }
    }
    // cout<<endl;
    // cout<<"YES"<<endl;
    cout<<an<<endl;
    for(ll i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    

    return 0;
}
