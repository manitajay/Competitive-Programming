// JAI BAJARANG BALI
 
// manitianajay45
 
// sab moh maya hai..
 
// give me some sunshine, give me some rain, give me another chance to grow up once again
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
ll binarysearch(ll arr[],ll l,ll r,ll val)
{
    if(r-l==1)
    {
        return r+1;
    }
    ll mid=(l+r)/2;
    if(arr[mid]>=val)
    {
        return binarysearch(arr,l,mid,val);
    }else
    {
        return binarysearch(arr,mid,r,val);
    }
    // return -1;
    
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
    while(k--)
    {
        ll val;
        cin>>val;
        cout<<binarysearch(arr,-1,n,val)<<endl;
        
    }
    return 0;
}
