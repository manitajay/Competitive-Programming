// JAI BAJARANG BALI
 
// manitianajay45
 
// give me some sunshine, give me some rain ,give me another chance to grow up once again....
 
// sab moh maya hai....
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll int
 
ll n,m;
 
vector<ll> graph[100005];
 
vector<bool> visited(100005,false);
 
 
void dfs(ll u){
    visited[u]=true;
    for(auto i:graph[u]){
        if(!visited[i]){
            dfs(i);
        }
    }
}
 
 
int main(){
    cin>>n>>m;
 
    for(ll i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<ll> vec;
    for(ll i=1;i<=n;i++){
        if(!visited[i]){
            vec.push_back(i);
            dfs(i);
            
        }
    }
 
    cout<<vec.size()-1<<endl;
    for(ll i=1;i<(ll)vec.size();i++){
        cout<<vec[i-1]<<" "<<vec[i]<<endl;
    }
 
    return 0;
}
