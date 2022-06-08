// JAI BAJARANG BALI

// manitianajay45

// give me some sunshine, give me some rain , give me another chance to grow up once again....

// sab moh maya hai....

/*
basically approach is:
1. find total sum of distance from node 1 to all other nodes.
2. now will count total node in a subtree for each node (child[i]=ith node has total no of childers+ 1);
3. now we can say for a par and a node u;
ans[u]=ans[par]-(child[i])+(n-child[i]);
we precalculate ans[1] so we can start traversal from there;
bcs if we move towards u then we can see its distance from its childern reduced by 1 and from other nodes increased by +1;

*/


#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long
#define mod 1000000007

vector<ll> graph[200005];
vector<bool> visited(200005, false);
vector<ll> ans(200005,0);
ll n;
ll sm=0;
ll mxx=0;
void dfs(ll v)
{
    visited[v] = true;
    
    for (auto u : graph[v])
    {
        if (!visited[u])
        {
            mxx++;
            sm+=mxx;
            dfs(u);
            mxx--;
        }
    }
}



vector<ll> child(200005,1);


void dfs1(ll v){
    visited[v]=true;
    for(auto u:graph[v]){
        if(!visited[u]){
            dfs1(u);
            child[v]+=child[u];
        }
    }
}


void ansdfs(ll v){
    visited[v]=true;
    for(auto u:graph[v]){
        if(!visited[u]){

            ans[u]=(ans[v]-2*child[u]+n);
            ansdfs(u);
        }
    }

}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // ll n;
    cin >> n;
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        
    }
    dfs(1);
    ans[1]=sm;
    visited.assign(n+1,false);
    dfs1(1);
    visited.assign(n+1,false);
    ansdfs(1);
    for(ll i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}
