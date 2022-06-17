// JAI BAJARANG BALI
 
// manitianajay45
 
// give me some sunshine, give me some rain, give me another chance to grow up once again
 
// sab moh maya hai...
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main()
{
    ll k,n;
    cin>>k>>n;
    ll arr[n];
    ll sm=0;
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
        sm+=arr[i];
    }
    sort(arr,arr+n);
 
        ll r=1e12;
        ll l=1;
        ll ans=0;
        while(l<=r){
 
 
            ll mid=(l+r)/2;
            
            ll req=mid*k;
            for(ll i=0;i<n;i++){
 
                req-=min(mid,arr[i]);
                if(req<=0)break;
            }
            if(req<=0){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        cout<<ans<<endl;
 
    return 0;
}
