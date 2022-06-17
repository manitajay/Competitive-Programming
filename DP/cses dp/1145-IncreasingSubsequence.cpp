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
 
int main()
{
    ll n;
    cin>>n;
    ll arr[n];
    // cin>>arr[i];
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<ll> dp(n+1,INT_MAX);
    dp[0]=INT_MIN;
    for(ll i=0;i<n;i++){
        ll j= upper_bound(dp.begin(),dp.end(),arr[i])-dp.begin();
        // j--;
        if(dp[j]>arr[i] && dp[j-1]<arr[i]){
            dp[j]=arr[i];
        }
        
        
    }
    ll ans=0;
    for(ll i=1;i<=n;i++){
        if(dp[i]<INT_MAX){
            ans=i;
        }else{
            break;
        }
    }
 
    cout<<ans<<endl;
}
