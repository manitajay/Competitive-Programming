// JAI BAJARANG BALI

// manitianajay45

// give me some sunshine, give me some rain , give me another chance to grow up once again....

// sab moh maya hai....

/*
in LCA method we are looking for LCA now we are basically looking for-
dis(LCA,u)+dis(LCA,v);
we had already equal level(u)==level(v);
dis+=(2*(LCA,u));
return dis;
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
ll n,q;


vector<ll> graph[200005];
vector<ll> par(200005,-1);

ll lvl=1;
vector<ll> level(200005,0);

ll dp[200005][21];

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


ll lca(ll tempu,ll tempv){
    // cout<<level[u]<<" "<<level[v]<<endl;
    ll u=tempu,v=tempv;
    ll an=abs(level[u]-level[v]);
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
    // cout<<an<<endl;
    // cout<<u<<" "<<v<<endl;
    if(u==v){
        // cout<<"UES"<<endl;
        return an;
    }
    ll ans=0;
    ll pre=0;
    ll anss=INT_MAX;
    for(ll i=20;i>=0;i--){
        if(dp[u][i]==dp[v][i]){
            // ans=dp[u][i];
            ans+=(1<<i);
            ans-=pre;
            anss=min(anss,ans);

            pre=(1<<i);
        }else{
            ans-=pre;
            ans+=(1<<i);
            pre=0;
            u=dp[u][i];
            v=dp[v][i];
        }
    }
    anss*=2;
    anss+=an;
    return anss;
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


    // for(ll i=1;i<=n;i++){
    //     cout<<dp[i][0]<<" ";
    // }
    // cout<<endl;


    // for(ll i=1;i<=n;i++){
        // cout<<level[i]<<" ";
    // }
    // cout<<endl;
    while(q--){
        ll u,v;
        cin>>u>>v;
        cout<<lca(u,v)<<endl;;
    }



    return 0;
}
