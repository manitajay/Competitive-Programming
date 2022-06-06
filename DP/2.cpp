// JAI BAJARANG BALI

// manitianajay45

// give me some sunshine, give me some rain give me another chance to grow up once again....

// sab moh maya hai....

// waiting....

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        ll n=s.length();
        vector<ll> dp(n+1,0);
        vector<ll> vec(26,-1);
        for(ll i=n-1;i>=0;i--){
            ll val=(ll)(s[i])-(ll)('a');
            ll in=vec[val];
            ll an=0;
            if(in!=-1)
            {
                an=dp[in+1];
            }else{
                an=-2;
            }

            dp[i]=max(dp[i+1],an+2);
            vec[val]=i;
            
        }


        cout<<(n-dp[0])<<endl;

    }
    return 0;
}
