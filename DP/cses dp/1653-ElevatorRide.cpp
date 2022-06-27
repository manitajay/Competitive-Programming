// JAI BAJARANG BALI

// manitianajay45

// give me some sunshine, give me some rain ,give me another chance to grow up once again....

// sab moh maya hai....

#include <bits/stdc++.h>
using namespace std;

#define ll long long


int main()
{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);
    ll n,x;
    cin>>n>>x;
    ll arr[n];
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    ll mx=(1<<n);
    vector<pair<ll,ll>> dp(mx,{0,0});
    dp[0]={1,0};


    for(ll i=1;i<mx;i++){
        pair<ll,ll> res1={INT_MAX,INT_MAX};
        // cout<<"YES"<<endl;

        for(ll j=0;j<n;j++){
            if((i&(1<<j))==0){
                continue;
            }
            pair<ll,ll> res=dp[(i^(1<<j))];

            if(res.second+arr[j]<=x){
                res.second+=arr[j];

            }else{
                res.first++;
                res.second=min(res.second,arr[j]);

            }
            res1=min(res,res1);



        }
        dp[i]=res1;

    }

    // cout<<"YS"<<endl;

    // for(ll i=1;i<mx;i++){
        // cout<<dp[i].second<<" ";
    // }
    // cout<<endl;

    ll ans=dp[(mx-1)].first;
    cout<<ans<<endl;
    
    return 0;
}
