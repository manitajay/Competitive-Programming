// JAI BAJARANG BALI
 
// manitianajay45
 
// give me some sunshine, give me some rain, give me another chance to grow up once again....
 
// sab moh maya hai....

/*
floyd-warshall algorithm:

https://cp-algorithms.com/graph/all-pair-shortest-path-floyd-warshall.html
*/
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INF 1e15
 
ll n, m,q;
 
vector<vector<ll>> dp(1001, vector<ll>(1001, INF));
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m>>q;
    for (ll i = 0; i < m; i++)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        dp[u][v]=min(dp[u][v],c);
        dp[v][u]=min(dp[v][u],c);
 
    }
 
 
    for(ll i=1;i<=n;i++){
        dp[i][i]=0;
    }
 
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            for(ll k=1;k<=n;k++){
                dp[j][k]=min(dp[j][k],dp[j][i]+dp[i][k]);
                
            }
        }
    }
 
    while(q--){
        ll l,r;
        cin>>l>>r;
        if(dp[l][r]<INF){
        cout<<dp[l][r]<<endl;
        }else{
            cout<<"-1"<<endl;
        }
    }
    return 0;
}

