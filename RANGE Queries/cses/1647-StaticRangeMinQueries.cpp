// JAI BAJARANG BALI

// manitianajay45

// give me some sunshine, give me some rain ,give me another chance to grow up once again....

// sab moh maya hai....

#include <bits/stdc++.h>
using namespace std;

#define ll long long


// ll st[200005][25];
vector<vector<ll>> st(200005,vector<ll>(25,INT_MAX));

int main()
{

    ios_base::sync_with_stdio(false);
    
    cin.tie(NULL);
    

    ll n,q;
    cin>>n>>q;
    ll arr[n+1];
    // cout<<st[1][1]<<endl;
    for(ll i=1;i<=n;i++)
    {
        cin>>arr[i];
        st[i][0]=arr[i];
    }


    for(ll i=1;i<25;i++){
        for(ll j=1;(j+(1<<i))<=n+1;j++){
            st[j][i]=min(st[j][i-1],st[j+(1<<(i-1))][i-1]);
        }
    }





    while(q--){
        ll l,r;
        cin>>l>>r;
        ll ans=st[l][0];
        for(ll i=24;i>=0;i--){
            if(((l+(1<<i))-1)<=r){
                // cout<<i<<" i"<<endl;
                ans=min(ans,st[l][i]);
                l+=(1<<i);
            }
        }
        cout<<ans<<endl;
        
    }
    return 0;
}
