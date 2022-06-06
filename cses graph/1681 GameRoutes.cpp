// JAI BAJARANG BALI
 
// manitianajay45
 
// give me some sunshine, give me some rain, give me another chance to grow up once again....
 
// sab moh maya hai....
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007
ll n, m;
 
vector<ll> graph[100005];
vector<bool> visited(100005,false);
bool flag=false;
vector<ll> par(100005,-1);
vector<ll> d(100005,0);
 
ll ans=0;
void dfs(ll v){
    
    if(v==n){
        flag=true;
        d[v]=1;
        return ;
    }
 
    
    visited[v]=true;
    ll ans=0;
    for(auto u:graph[v]){
        if(!visited[u]){
            dfs(u);
        }
        
        ans=ans%mod + (d[u]%mod);
        ans%=mod;
 
    }
    d[v]=ans;
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
    cout<<d[1]<<endl;
 
   
    
    return 0;
}
