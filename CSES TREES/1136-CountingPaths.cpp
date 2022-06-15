// JAI BAJARANG BALI
 
// manitianajay45
 
// give me some sunshine, give me some rain , give me another chance to grow up once again....
 
// sab moh maya hai....
 
// LCA 


/*
    How to Approach?
    basically we know there is only one path in a tree to one node to other node if we can traverse a node once....
    
    how many nodes will affected by their path?
    node from LCA(u,v) to u and LCA(u,v) to v;
    
    increase the value of node u and v each by 1
    and decrease the value of lca by 2;
    
    now will store sum of nodes's subtree by using dfs;
    after it remeber to increase all lca values by 1;
    

      

*/
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007
ll n,q;
 
 
vector<ll> graph[200005];
vector<ll> par(200005,-1);
vector<ll> ans(200005,0);
vector<bool> visited(200005,false);
 
ll lvl=1;
vector<ll> level(200005,0);
 
ll dp[200005][21];

vector<ll> check(200005,0);
 
void dfs(ll v){
    level[v]=lvl;
    // cout<<v<<endl;
 
    for(auto u:graph[v]){
        if(level[u]==0){
            dp[u][0]=v;
            lvl++;
            dfs(u);
            lvl--;
        }
    }
    
 
}


void dfs1(ll v){
    visited[v]=true;
    for(auto u:graph[v]){
        if(!visited[u]){
            dfs1(u);

            ans[v]+=ans[u];
        }
    }


}
 
 
ll lca(ll tempu,ll tempv){
    ll u=tempu,v=tempv;
    ll an=abs(level[u]-level[v]);
    if(level[u]<level[v]){
        ll k=level[v]-level[u];
        for(ll i=20;i>=0;i--){
            if(((k>>i)&1)){
                v=dp[v][i];
            }
            
        }
 
    }else if(level[u]>level[v]){
        ll k=level[u]-level[v];
        for(ll i=20;i>=0;i--){
            if(((k>>i)&1)){
                u=dp[u][i];
            }
            
        }
    }

    if(u==v){
        return u;
    }
    ll ans=0;
    ll pre=0;
    ll anss=INT_MAX;
    for(ll i=20;i>=0;i--){
        if(dp[u][i]==dp[v][i]){
            // ans=dp[u][i];
            ans=dp[u][i];
        }else{
            u=dp[u][i];
            v=dp[v][i];
        }
    }
    return ans;
}
 
 
void binlift(){
    for(ll i=1;i<=20;i++){
        for(ll j=1;j<=n;j++){
            dp[j][i]=dp[dp[j][i-1]][i-1];
        }
    }  
     
}
 
 
 
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>q;
    // dp[1][0]=-1;
    memset(dp,0,sizeof(dp));
    for(ll i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v;
        // dp[v][0]=u;
        // dp[u][0]=v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
 
 
    dfs(1);
    binlift();
 
    while(q--){
        ll u,v;
        cin>>u>>v;
        ll val=lca(u,v);
        // cout<<u<<" "<<v<<endl;
        // cout<<val<<endl;
        ans[val]-=2;
        // check[val]=true;
        check[val]++;
        ans[u]++;
        ans[v]++;
    }
    // for(ll i=1;i<=n;i++){
    //     cout<<ans[i]<<" ";
    // }
    // cout<<endl;
    dfs1(1);


    for(ll i=1;i<=n;i++){
        cout<<ans[i]+check[i]<<" ";
    }
    cout<<endl;
 
 
 
    return 0;
}
