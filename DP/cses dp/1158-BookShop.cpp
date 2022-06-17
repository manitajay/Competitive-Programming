// JAI BAJARANG BALI
 
// manitianajay45
 
// give me some sunshine, give me some rain, give me another chance to grow up once again.....
 
// sab moh maya hai....
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll int
#define mod 1000000007
 
ll dp[1005][100005];
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n,x;
    cin>>n>>x;
 
    ll hrr[n+1],srr[n+1];
    for(ll i=1;i<=n;i++){
        cin>>hrr[i];
    }
 
    for(ll i=1;i<=n;i++){
        cin>>srr[i];
    }
 
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=x;j++){
            if(hrr[i]<=j){
                dp[i][j]=max(dp[i-1][j-hrr[i]]+srr[i],dp[i-1][j]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
 
 
    cout<<dp[n][x]<<endl;
    // for(ll i=1;i<=n;i++){
    //     for(ll j=1;j<=x;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
 
    
 
    return 0;
}
