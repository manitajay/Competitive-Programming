// JAI BAJARANG BALI
 
// manitianajay45
 
// give me some sunshine, give me some rain, give me another chance to grow up once again....
 
// sab moh maya hai....
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007
ll n, m;
 
vector<pair<ll,ll>> graph[100005];
vector<bool> visited(100005,false);
bool flag=false;
vector<ll> dp(100005,-1);
vector<ll> dp1(100005,-1);
vector<ll> dp2(100005,INT_MAX);
vector<ll> dp3(100005,0);
 
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(ll i=0;i<m;i++){
        ll u,v,c;
        cin>>u>>v>>c;
        graph[u].push_back({v,c});
    }
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,1});
    dp[1]=0;
    dp1[1]=1;
    dp2[1]=0;
    dp3[1]=0;
    while(!pq.empty()){
        pair<ll,ll> pr=pq.top();
        pq.pop();
        if(visited[pr.second]){
            continue;
        }
        visited[pr.second]=true;
        for(auto i:graph[pr.second]){
            if(visited[i.first]){
                continue;
            }
            if(dp[i.first]==-1 || dp[i.first]>dp[pr.second]+i.second){
                dp[i.first]=dp[pr.second]+i.second;
                dp1[i.first]=dp1[pr.second];
                dp2[i.first]=dp2[pr.second]+1;
                dp3[i.first]=dp3[pr.second]+1;
                pq.push({dp[i.first],i.first});
            }else if(dp[i.first]==(dp[pr.second]+i.second)){
                dp1[i.first]=dp1[i.first]%mod + dp1[pr.second]%mod;
                dp1[i.first]%=mod;
                dp2[i.first]=min(dp2[i.first],dp2[pr.second]+1);
                dp3[i.first]=max(dp3[i.first],dp3[pr.second]+1);
                // pq.push({dp[i.first],i.first});

            }

        }

    }

    // for(ll i=1;i<=n;i++){
        // cout<<dp[i]<<" ";
    // }
    cout<<endl;
    cout<<dp[n]<<" "<<dp1[n]<<" "<<dp2[n]<<" "<<dp3[n]<<endl;
   
    
    return 0;
}
