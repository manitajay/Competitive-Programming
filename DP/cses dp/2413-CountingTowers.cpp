// JAI BAJARANG BALI
 
// manitianajay45
 
// give me some sunshine, give me some rain, give me another chance to grow up once again.....
 
// sab moh maya hai....
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007
 
// ll dp[1005][100005];
ll dp[5][1000005];
 
ll mul(ll x,ll y){
    return ((x%mod)*(y%mod))%mod;
}
 
ll add(ll x,ll y){
    return (x%mod + y%mod)%mod;
}
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    dp[0][1]=1;
    dp[1][1]=1;
    dp[2][1]=1;
    dp[3][1]=1;
    dp[4][1]=2;
    for(ll i=2;i<=1000002;i++){
        dp[4][i]=mul(2,dp[4][i-1]);
        ll val=mul(3,dp[0][i-1]);
        val=add(val,dp[1][i-1]);
        dp[4][i]=add(dp[4][i],val);
 
        dp[0][i]=add(dp[4][i-1],mul(3,dp[0][i-1]));
        dp[1][i]=add(dp[4][i-1] , dp[1][i-1]);
        dp[2][i]=add(dp[4][i-1] , dp[0][i-1]);
        dp[3][i]=add(dp[4][i-1] , dp[0][i-1]);
 
    }
    ll t;
    cin>>t;
 
    while(t--){
        ll n;
        cin>>n;
        cout<<dp[4][n]<<endl;
    }
 
    return 0;
}
