// JAI BAJARANG BALI
 
// manitianajay45
 
// give me some sunshine, give me some rain, give me another chance to grow up once again....
 
// sab moh maya hai....
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll int
#define mod 1000000007
 
ll add(ll x, ll y)
{
    return (x % mod + y % mod) % mod;
}
 
ll mul(ll x, ll y)
{
    return ((x % mod) * (y % mod)) % mod;
}
 
// vector<vector<ll>> dp(1000005,vector<ll>(101,0));
// ll dp[1000005][101];
// ll dp[1000005]={-1};
int main()
{
    ll n;
    cin>>n;
    vector<ll> dp(n+1,INT_MAX);
    // cout<<dp[2]<<endl;
    dp[n]=0;
 
    for(ll i=n;i>=0;i--){
        if(dp[i]!=INT_MAX){
            ll temp=i;
            while(temp!=0){
                ll rem=temp%10;
                // dp[i-rem]=min(dp[i-rem],)
                if(i-rem>=0){
                    dp[i-rem]=min(dp[i]+1,dp[i-rem]);
                }
                temp/=10;
            }
        }
    }
    cout<<dp[0]<<endl;
 
 
    return 0;
}
