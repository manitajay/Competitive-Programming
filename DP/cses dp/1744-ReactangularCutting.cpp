// JAI BAJARANG BALI
 
// manitianajay45
 
// give me some sunshine, give me some rain, give me another chance to grow up once again....
 
// sab moh maya hai....
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll int
ll mdl=1000000;
#define mod 1000000007
ll x,y;
 
vector<vector<ll>> dp(505,vector<ll>(505,-1));
 
ll rec(ll a,ll b){
    if(a==b){
        return dp[a][b]=0;
    }
 
    if(dp[a][b]!=-1){
        return dp[a][b];
    }
 
    
    
    
    ll mn=mdl;
 
    for(ll i=1;i<b;i++){
        ll xx1,yy1,xx2,yy2;
        xx1=a;
        yy1=b-i;
        xx2=a;
        yy2=i;
        if(xx1>yy1){
            swap(xx1,yy1);
        }
        if(xx2>yy2){
            swap(xx2,yy2);
        }
        mn=min(mn,1+rec(xx1,yy1)+rec(xx2,yy2));
        
    }
    for(ll i=1;i<a;i++){
        ll xx1,yy1,xx2,yy2;
        xx1=a-i;
        yy1=b;
        xx2=i;
        yy2=b;
        if(xx1>yy1){
            swap(xx1,yy1);
        }
        if(xx2>yy2){
            swap(xx2,yy2);
        }
        mn=min(mn,1+rec(xx1,yy1)+rec(xx2,yy2));
    }
        
    
 
    
    return dp[a][b]=mn;
 
}
 
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    cin>>x>>y;
    // n=s1.length(),m=s2.length(); 
    if(x>y){
        swap(x,y);
    }  
    ll an=rec(x,y);
    
    cout<<an<<endl;
 
 
    return 0;
}
