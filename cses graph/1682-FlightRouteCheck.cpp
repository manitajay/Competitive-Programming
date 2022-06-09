// JAI BAJARANG BALI

// manitianajay45

// give me some sunshine, give me some rain , give me another chance to grow up once again....

// sab moh maya hai....



/*
kosaraju algorithm.

step:-
1 perform topo sort.
2 reverse all link of directed graph.
3. run dfs over graph from topo sort first node.
and the node which is not visited will not connect with first node of topo sort.
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
    topo(1);
    // cout<<"YES"<<endl;
    visited.assign(n+1,false);
    
    ll nd=order[n-1];
    // cout<<nd<<endl;

    dfs(nd);
    for(ll i=1;i<=n;i++){
        if(!visited[i]){
            cout<<"NO"<<endl;
            cout<<i<<" "<<nd<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;

    

    return 0;
}
