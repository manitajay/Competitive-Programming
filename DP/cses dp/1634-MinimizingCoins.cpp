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
 
vector<ll> dp(1000005,-1);
 
int main()
{
    ll n,x;
    cin>>n>>x;
    // cout<<"YES"<<endl;
    vector<ll> cn;
    // cout<<"YES";
 
    for(ll i=0;i<n;i++){
        ll val;
        cin>>val;
        cn.push_back(val);
        dp[val]=1;
    }
    // cout<<"YES";
    sort(cn.begin(),cn.end());
    for(ll i=1;i<=x;i++){
        if(dp[i]!=-1){
            continue;
        }
        for(ll j=0;j<(ll)cn.size();j++){
            ll val=i-cn[j];
            if(val<0){
                break;
            }else if(dp[val]==-1){
                continue;
            }else{
                if(dp[i]==-1)
                {
                    dp[i]=dp[val]+1;
                }else{
                    dp[i]=min(dp[i],dp[val]+1);
                }
            }
 
 
        }
 
 
    }
 
    cout<<dp[x]<<endl;
    
 
    return 0;
}
