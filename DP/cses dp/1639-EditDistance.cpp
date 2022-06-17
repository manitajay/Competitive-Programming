// JAI BAJARANG BALI
 
// manitianajay45
 
// give me some sunshine, give me some rain, give me another chance to grow up once again....
 
// sab moh maya hai....
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll int
#define mod 1000000007
ll n,m;
string s1,s2;
// ll dp[5005][5005];
vector<vector<ll>> dp(5005,vector<ll>(5005,-1));
 
ll rec(ll i,ll j){
    if(i==n || j==m){
        return dp[i][j]=abs(n-i+m-j);
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
 
 
    if(s1[i]==s2[j]){
    ll val4=rec(i+1,j+1);    
    ll val1=1+rec(i,j+1);
    ll val2=1+rec(i+1,j+1);
    ll val3=1+rec(i+1,j);
        return dp[i][j]=min(min(val1,val2),min(val3,val4));    
    }
 
    ll val1=1+rec(i,j+1);
    ll val2=1+rec(i+1,j+1);
    ll val3=1+rec(i+1,j);
    return dp[i][j]=min(val1,min(val3,val2));
}
 
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    cin>>s1>>s2;
    n=s1.length(),m=s2.length();   
    ll x=rec(0,0);
    
    cout<<x<<endl;
 
 
    return 0;
}
