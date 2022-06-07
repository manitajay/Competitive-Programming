// JAI BAJARANG BALI
 
// manitianajay45
 
// give me some sunshine, give me some rain, give me another chance to grow up once again....
 
// sab moh maya hai....
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

vector<ll> graph[200005];

vector<ll> ans(200005,0);

vector<bool> visited(200005,false);


void dfs(ll v){
    visited[v]=true;
    ll an=0;
    for(auto u:graph[v]){
        if(!visited[u]){
            dfs(u);
        }
        an+=(ans[u]+1);
    }
    ans[v]=an;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll arr[n+1];
    arr[1]=-1;
    for(ll i=2;i<=n;i++){
        cin>>arr[i];
    }
    // cout<<"YES"<<endl;


    for(ll i=2;i<=n;i++){
        graph[arr[i]].push_back(i);
    }

    dfs(1);
    for(ll i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;






   
    
    return 0;
}
