// JAI BAJARANG BALI

// manitianajay45

// give me some sunshine, give me some rain, give me another chance to grow up once again....

// sab moh maya hai....

#include <bits/stdc++.h>
using namespace std;

#define ll int

ll n, m;

vector<ll> graph[100005];
vector<bool> visited(100005,false);
bool flag=false;
vector<ll> order;
vector<ll> ans;
vector<ll> visited1(100005,0);
ll x=-1;
void dfs1(ll v){
    if(flag){
 
        return ;
    }
    visited1[v]=1;
    // cout<<v<<" "<<endl;
    for(auto u:graph[v]){
        if(visited1[u]==1){
            flag=true;
            return ;
        }
        if(visited1[u]==0){
            dfs1(u);
        }
        
    }
    visited1[v]=2;
}
void dfs(ll v){
    
    visited[v]=true;
    // cout<<v<<" ";
    for(auto u:graph[v]){
       
        if(!visited[u]){
            dfs(u);
        }
    }
    order.push_back(v);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(ll i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;
        graph[u].push_back(v);
    }

    for(ll i=1;i<=n;i++){
        if(visited1[i]==0){
            dfs1(i);
        }
        if(flag){
            break;
        }
    }
    if(flag){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }

    for(ll i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    reverse(order.begin(),order.end());
    visited.assign(n+1,false);

    for(auto i:order){
        cout<<i<<" ";
    }
    cout<<endl;
    
    return 0;
}
