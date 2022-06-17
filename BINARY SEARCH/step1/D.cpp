// JAI BAJARANG BALI
 
// manitianajay45
 
// sab moh maya hai..
 
// give me some sunshine, give me some rain, give me another chance to grow up once again
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
ll binarysearch1(ll arr[],ll l,ll r,ll val)
{
    if(r-l==1)
    {
        return r+1;
    }
    ll mid=(l+r)/2;
    if(arr[mid]>=val)
    {
        return binarysearch1(arr,l,mid,val);
    }else
    {
        return binarysearch1(arr,mid,r,val);
    }
    // return -1;
}
ll binarysearch2(ll arr[],ll l,ll r,ll val)
{
    if(r-l==1)
    {
        return l+1;
    }
    ll mid=(l+r)/2;
    if(arr[mid]>val)
    {
        return binarysearch2(arr,l,mid,val);
    }else
    {
        return binarysearch2(arr,mid,r,val);
    }
    // return -1;
}
 
 
 
 
int main()
{
    ll n,k;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    cin>>k;
    while(k--)
    {
        ll val1,val2;
        cin>>val1>>val2;
        cout<<binarysearch2(arr,-1,n,val2)-binarysearch1(arr,-1,n,val1)+1<<" ";    
    }
    return 0;
}
