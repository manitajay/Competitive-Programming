// JAI BAJARANG BALI
 
// manitianajay45
 
// sab moh maya hai...
 
// give me some sunshine , give me some rain, give me another chance to grow up once again
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
bool sumseg(ll arr[],ll n,ll sum,ll k)
{
    ll val=0;
    ll cnt=0;
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        val+=arr[i];
        if(val>sum)
        {
            val=arr[i];
            cnt++;
        }
        ans=max(ans,val);
    }
    // cout<<ans<<endl;
    return (cnt<k);
 
}
 
void sumseg1(ll arr[],ll n,ll sum,ll k)
{
    ll val=0;
    ll cnt=0;
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        val+=arr[i];
        if(val>sum)
        {
            val=arr[i];
            cnt++;
        }
        ans=max(ans,val);
    }
    cout<<ans<<endl;
    
 
}
 
 
int main()
{
 
    ll n,k;
    cin>>n>>k;
    ll arr[n];
    ll mn=INT_MIN;
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
        mn=max(arr[i],mn);
    }
    // cout<<mn<<endl;
    ll l=mn,r=1;
    while(!sumseg(arr,n,r,k))
    {
        r*=2;
    }
 
    // cout<<r<<endl;
 
    while(r>l+1)
    {
        ll mid=(l+r)/2;
        if(sumseg(arr,n,mid,k))
        {
            r=mid;
        }else
        {
            l=mid;
        }
    }
    // cout<<r<<endl;
    sumseg1(arr,n,r,k);
 
 
    return 0;
}
