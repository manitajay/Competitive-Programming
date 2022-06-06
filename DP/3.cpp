// JAI BAJARANG BALI

// manitianajay45

// give me some sunshine, give me some rain give me another chance to grow up once again....

// sab moh maya hai....

// waiting....

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 998244353


ll add(ll x,ll y){
    return (x%mod + y%mod)%mod;
}

ll mul(ll x,ll y){
    return ((x%mod)*(y%mod))%mod;
}


ll c[1001][1001];

void cr(){
    for(ll i=0;i<=1000;i++){
        c[i][0]=1;
    }

    for(ll i=1;i<=1000;i++){
        for(ll j=1;j<=i;j++){
            c[i][j]=add(c[i-1][j],c[i-1][j-1]);
        }
    }
}



int main(){
    cr();
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    // cout<<c[4][5]<<endl;
    vector<ll> dp(n+1,0);

    ll mx=0;

    dp[n]=1;
    for(ll i=n-1;i>=0;i--){
        ll k=arr[i];


        if(k<=0){
            continue;
        }
       


        // ll an=1;

        // dp[i]=add(dp[i],(c[n-i-1][k]));
        for(ll j=i+k+1;j<=n;j++){
            dp[i]=add(dp[i],mul(c[j-i-1][k],(dp[j])));
        }
    }


    ll ans=0;
    for(ll i=0;i<=n-1;i++){
        ans=add(ans,dp[i]);
        // cout<<dp[i]<<" ";
    }
    // cout<<endl;
    cout<<ans<<endl;
    return 0;
}
