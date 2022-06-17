// JAI BAJARANG BALI
 
// manitianajay45
 
// give me some sunshine, give me some rain, give me another chance to grow up once again....
 
// sab moh maya hai....
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007
 
ll add(ll x, ll y)
{
    return (x % mod + y % mod) % mod;
}
 
ll mul(ll x, ll y)
{
    return ((x % mod) * (y % mod)) % mod;
}
 
vector<ll> dp(1000005,0);
 
int main()
{
    ll n;
    cin>>n;
 
    if(n==0){
        cout<<"0"<<endl;
    }
    // dp[1]=1;
    
    for(ll i=1;i<=n;i++){
        ll val=max(i-6,0ll);
        for(ll j=val;j<=i-1;j++){
            dp[i]=add(dp[i],dp[j]);
        }
        // dp[i]=add(dp[i],1);
        if(i<=6){
            dp[i]=add(dp[i],1);
        }
    }
 
    cout<<dp[n]<<endl;
 
    return 0;
}
