// JAI BAJARANG BALI

// manitianajay45

// give me some sunshine, give me some rain , give me another chance to grow up once again....

// sab moh maya hai....

// LCA 

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
ll n,q;


vector<ll> graph[200005];

ll lvl=1;
vector<ll> level(200005,0);

ll dp[200005][21];

void dfs(ll v){
    level[v]=lvl;
    // cout<<v<<endl;

    for(auto u:graph[v]){
        if(level[u]==0){
            lvl++;
            dfs(u);
            lvl--;
        }
    }
    

}


ll lca(ll tempu,ll tempv){
    // cout<<level[u]<<" "<<level[v]<<endl;
    ll u=tempu,v=tempv;
    if(level[u]<level[v]){
        ll k=level[v]-level[u];
        // cout<<k<<endl;
        for(ll i=20;i>=0;i--){
            if(((k>>i)&1)){
                // cout<<i<<"i"<<endl;
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

    for(ll i=20;i>=0;i--){
        if(dp[u][i]==dp[v][i]){
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
    for(ll i=2;i<=n;i++){
        ll x;
        cin>>x;
        dp[i][0]=x;
        graph[x].push_back(i);
        // graph[x].push_back(i);
    }

    binlift();


    // cout<<"U";
    dfs(1);
    // cout<<"U";

    // for(ll i=1;i<=n;i++){
        // cout<<level[i]<<" ";
    // }
    // cout<<endl;
    while(q--){
        ll u,v;
        cin>>u>>v;
        cout<<lca(u,v)<<endl;
    }



    return 0;
}
