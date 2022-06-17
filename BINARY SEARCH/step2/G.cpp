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
 
        ll r=(sm+k-1)/k;
        r++;
        ll l=1;
        while(l+1<r){
 
 
            ll mid=(l+r)/2;
            //check if this number of councils is possible
            ll req=mid*k;
            for(ll i=0;i<n;i++){
 
                req-=min(mid,arr[i]);
                if(req<=0)break;
            }
            if(req<=0){
 
                l=mid;
            }
            else r=mid;
        }
        cout<<l<<endl;
 
    return 0;
}
