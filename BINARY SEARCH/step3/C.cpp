// JAI BAJARANG BALI
 
// manitianajay45
 
// sab moh maya hai..
 
// give me some sunshine give me some rain, give me another chance to grow up once again
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
bool good(ll arr[],ll n,ll val,ll k)
{
    ll ch=arr[0];
    ll cnt=1;
    for(ll i=1;i<n;i++)
    {
        if(arr[i]-ch >=val)
        {
            cnt++;
            ch=arr[i];
        }
    }
    return (cnt>=k);
}
 
void ans(ll arr[],ll n,ll val)
{
    ll ch=arr[0];
    ll res=INT_MAX;
    for(ll i=1;i<n;i++)
    {
        if((arr[i]-ch) >= val)
        {
            
            res=min(res,arr[i]-ch);
            ch=arr[i];
        }
    }
    cout<<res<<endl;
}
 
 
int main()
{
    ll n,k;
    cin>>n>>k;
 
    ll arr[n];
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    ll l=0,r=1e9;
 
    while(r>l+1)
    {
        ll mid=(l+r)/2;
        if(good(arr,n,mid,k))
        {
            l=mid;
        }else
        {
            r=mid;
 
        }
 
 
    }
    ans(arr,n,l);
    return 0;
 
}
