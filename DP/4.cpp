// JAI BAJARANG BALI

// manitianajay45

// give me some sunshine, give me some rain, give me another chance to grow up once again....

// sab moh maya hai....

// waiting....

#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll DP[105][10005]={INT_MAX};

ll dp(ll n,ll arr[],ll brr[],ll i,ll s,ll sum){
    if(i>=n){
        return s*s +(sum-s)*(sum-s);
    }
    if(DP[i][s]!=INT_MAX){
        // cout<<DP[i][s]<<endl;
        return DP[i][s];
    }
    // cout<<"yES"<<endl;
    return DP[i][s]= min(dp(n,arr,brr,i+1,s+arr[i],sum),dp(n,arr,brr,i+1,s+brr[i],sum));

        
    


}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll arr[n],brr[n];
        ll ans=0;
        ll mx=-1;
        ll ina=-1;
        ll inb=-1;
        ll sum=0;
        
        for(ll i=0;i<n;i++){
            cin>>arr[i];
            sum+=arr[i];
            ans+=(arr[i]*arr[i])*(n-2);
        }
        for(ll i=0;i<n;i++){
            cin>>brr[i];
            sum+=brr[i];
            ans+=(brr[i]*brr[i])*(n-2);

        }
        for(ll i=0;i<=n;i++){
            for(ll j=0;j<=sum+2;j++){
                DP[i][j]=INT_MAX;
            }
        }

        if(n==1){
            cout<<"0"<<endl;
            continue;
        }

        ans+=dp(n,arr,brr,0,0,sum);
        cout<<ans<<endl;
        


        

    }
    return 0;
}
 
