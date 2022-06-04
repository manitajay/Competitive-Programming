// JAI BAJARANG BALI
 
// manitianajay45
 
// give me some sunshine, give me some rain, give me another chance to grow up once again....
 
// sab moh maya hai....
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INF 1e15
ll n,m;
 
struct ed
{
    ll u,v,c;
};
 
vector<ll> graphf[2505];
vector<ll> graphr[2505];
vector<bool> vis1(2505,false);
vector<bool> visn(2505,false);
 
void dfs(ll v){
    vis1[v]=true;
    for(auto u:graphf[v]){
        if(!vis1[u]){
            dfs(u);
        }
    }
}
void dfs1(ll v){
    visn[v]=true;
    for(auto u:graphr[v]){
        if(!visn[u]){
            dfs1(u);
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
 
    vector<ed> edges;
    for (ll i = 0; i < m; i++)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        graphf[u].push_back(v);
        graphr[v].push_back(u);
        edges.push_back({u,v,c});
    }
    // cout<<"YES"<<endl;
 
    dfs(1);
    dfs1(n);
    vector<ll> d(n+1,INT_MIN);
    d[1]=0;
    ll ans=-1;
    bool flag=false;
    for(ll j=0;j<n;j++){
        flag=false;
        for(ll i=0;i<m;i++){
            ed nd=edges[i];
            if(d[nd.u]>INT_MIN){
                if(vis1[nd.v] && visn[nd.v] && d[nd.v]< d[nd.u]+nd.c){
                    d[nd.v]= d[nd.u]+nd.c;
                    flag=true;
                }
            }
        }
        if(j==n-1){
            ans=d[n];
        }
 
    }
    if(flag || d[n]==INT_MIN){
        cout<<"-1"<<endl;
        return 0;
    }
    cout<<d[n]<<endl;
 
 
 
    return 0;
}
