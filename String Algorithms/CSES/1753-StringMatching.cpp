// JAI BAJARANG BALI

// manitianajay45

// give me some sunshine, give me some rain , give me another chacne to grow up once again....

// sab moh maya hai....

#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define mod 1000000007


int main(){
    string s,t;
    cin>>s>>t;
    ll val=t.length();
    t+="#";
    t+=s;
    ll n=t.length();
    vector<ll> dp(n,0);
    dp[0]=0;
    ll ans=0;
    for(ll i=1;i<n;i++){
        
        ll temp=dp[i-1];
        while(temp>0 && t[temp]!=t[i]){
            temp=dp[temp-1];
        }

        dp[i]=temp;
        if(t[i]==t[temp]){
            dp[i]++;
        }
        

        if(dp[i]==val){
            ans++;
        }
    }
    cout<<ans<<endl;



    
}
