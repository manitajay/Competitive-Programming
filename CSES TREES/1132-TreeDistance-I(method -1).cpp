// JAI BAJARANG BALI

// manitianajay45

// give me some sunshine, give me some rain , give me another chance to grow up once again....

// sab moh maya hai....


/*
Basically approach is about finding two end points of diameter of tree and then finding distance of every node
from both end points and from which endpoint ditance is max that will be considered.


ans[i]=max(dis(end1,i),dis(end2,i));
*/


#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long
#define mod 1000000007

vector<ll> graph[200005];
vector<bool> visited(200005, false);
ll mxx=0;

ll prv=0;
ll v1,v2;

vector<pair<ll,ll>> vec;
void dfs(ll v)
{
    visited[v] = true;
    

    bool flag=false;
    for (auto u : graph[v])
    {
        if (!visited[u])
        {
            mxx++;
            if(mxx>prv){
                prv=mxx;
                v1=u;
            }
            dfs(u);
            mxx--;
        }
    }
}



vector<ll> ans(200005,0);






void dfss(ll v){
    visited[v]=true;
    for(auto u:graph[v]){
        if(!visited[u]){
            mxx++;
            ans[u]=max(ans[u],mxx);
            dfss(u);
            mxx--;
        }
    }
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        
    }
    
    dfs(1);
    ll stp=v1;
    mxx=0;
    prv=0;
    visited.assign(n+1,false);
    dfs(stp);
    ll endp=v1;
    visited.assign(n+1,false);
    dfss(stp);
    visited.assign(n+1,false);
    // cout<<stp<<" "<<endp<<endl;
    dfss(endp);

    for(ll i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}
