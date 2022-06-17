// JAI BAJARANG BALI
 
// manitianajay45
 
// sab moh maya hai..
 
// give me some sunshine, give me some rain, give me another chance to grow up once again
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
bool binarysearch(ll arr[],ll l,ll r,ll val)
{
   
    if(l>r)
    {
        return false;
    }
    ll mid=(l+r)/2;
    if(arr[mid]==val)
    {
        return true;
    }else if(arr[mid]>val)
    {
        return binarysearch(arr,l,mid-1,val);
    }else
    {
        return binarysearch(arr,mid+1,r,val);
    }
    
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
        if(binarysearch(arr,0,n,val))
        {
            cout<<"YES"<<endl;
        }else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
