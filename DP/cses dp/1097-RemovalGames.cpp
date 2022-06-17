// JAI BAJARANG BALI
 
// manitianajay45
 
// give me some sunshine, give me some rain, give me another chance to grow up once again....
 
// sab moh maya hai....
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
// ll dp[5005][5005];
 
 
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n;
 
    cin>>n;
    ll xrr[n+1];
 
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
 
    ll sm=0;
    for(ll i=1;i<=n;i++){
        cin>>xrr[i];
        sm+=xrr[i];
    }
    // ll ans=-1e9;
    ll ans;
    for(ll i=n;i>=1;i--){
        for(ll j=i;j<=n;j++){
 
                if(i==j){
                    dp[i][j]=xrr[i];
                    continue;
                }
                dp[i][j]=max(xrr[i]-dp[i+1][j],xrr[j]-dp[i][j-1]);
                
            
        }
    }
    ans=dp[1][n];
    sm+=ans;
    cout<<(sm/2)<<endl;
 
 
 
    return 0;
}
