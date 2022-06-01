// JAI BAJARANG BALI
 
// manitianajay45
 
// give me some sunshine, give me some rain, give me another chance to grow up once again....
 
// sab moh maya hai....
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007
 
 
ll dp[20][10][2][2];
 
 
ll rec(string a,ll i,ll prev,bool tight,bool check0){
    if(i>=a.length()){
        return 1;
    }
 
    if(prev!=-1 && dp[i][prev][tight][check0]!=-1){
        return dp[i][prev][tight][check0];
    }
    ll val=a[i]-'0';
    ll ans=0;
    // cout<<ans<<endl;
    for(ll j=0;j<=9;j++){
        if(tight && check0 && j<=val){
            ans+=rec(a,i+1,j,j==val,check0 && (j==0));
        }else if(tight && !check0 && j<=val && prev!=j){
            ans+=rec(a,i+1,j,j==val,check0);
        }else if(!tight && check0){
            ans+=rec(a,i+1,j,0,check0 && (j==0));
        }else if(!tight && !check0 && j!=prev){
            ans+=rec(a,i+1,j,0,0);
        }
    }
 
    return dp[i][prev][tight][check0]= ans;
 
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll a,b;
    cin>>a>>b;
    memset(dp,-1,sizeof(dp));
    // cout<<dp[10][9][0][1]<<endl;
    a--;
    string aa=to_string(a);
    string bb=to_string(b);
 
 
    ll ans=rec(bb,0,-1,1,1);
    memset(dp,-1,sizeof(dp));
    
    ans-=rec(aa,0,-1,1,1);
    cout<<ans<<endl;
 
 
 
 
    return 0;
}
