// JAI BAJARANG BALI
 
// manitianajay45
 
// give me some sunshine, give me some rain, give me another chance to grow up once again....
 
// sab moh maya hai....
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
// ll dp[5005][5005];
#define mod 1000000007
 
ll dp[505][130000];
 
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n;
    cin>>n;
    ll sm=((n)*(n+1))/2;
 
    if(sm%2!=0){
        cout<<"0"<<endl;
        return 0;
    }
    // cout<<"YES"<<endl;
    sm/=2;
    // dp[1][1]=1;
 
    for(ll i=1;i<=n;i++){
        dp[i][0]=1;
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=sm;j++){
 
            if(j-i>=0){
                dp[i][j]=(dp[i-1][j]%mod+dp[i-1][j-i]%mod)%mod;
            }else{
                dp[i][j]=dp[i-1][j]%mod;
            }
        }
    }
 
    cout<<dp[n][sm]<<endl;
 
 
 
    return 0;
}
