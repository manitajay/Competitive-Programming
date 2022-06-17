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
 
ll dp[1005][1005];
int main()
{
    ll n;
    cin>>n;
    vector<string> vec(n);
    for(ll i=0;i<n;i++){
        cin>>vec[i];
    }
    dp[1][1]=1;
    if(vec[0][0]=='*'){
        cout<<"0"<<endl;
        return 0;
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            if(vec[i-1][j-1]=='.'){
                dp[i][j]=add(dp[i][j],dp[i-1][j]);
                dp[i][j]=add(dp[i][j],dp[i][j-1]);
            }else{
                dp[i][j]=0;
            }
        }
    }
 
    cout<<dp[n][n]<<endl;
    
 
    return 0;
}
