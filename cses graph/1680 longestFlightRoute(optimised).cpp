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
vector<ll> par(100005,-1);
vector<ll> d(100005,-1);
 
 
void dfs(ll v){
    
    if(v==n){
        flag=true;
        d[v]=0;
        return ;
    }
 
    
    visited[v]=true;
    for(auto u:graph[v]){
      
 
        
        if(!visited[u]){
            dfs(u);
        }
        if(d[u]==-1){
            continue;
        }
        if(d[v]< d[u]+1){
            d[v]=d[u]+1;
            par[v]=u;
        }
 
        
 
 
    }
 
 
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
    d[1]=0;
    
 
    dfs(1);
    // cout<<"-1"<<endl;
 
    if(!flag){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
 
    vector<ll> ans;
    ll nd=1;
    while(nd!=-1){
        ans.push_back(nd);
        nd=par[nd];
    }
    // reverse(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
 
   
    
    return 0;
}
