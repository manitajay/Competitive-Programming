// JAI BAJARANG BALI
 
// manitianajay45
 
// sab moh maya hai...
 
// give me some sunshine, give me some rain, give me another chance to grow up once again
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
bool good(ll arr[],ll mid,string t,string p)
{
    ll check=p.length();
    ll len=t.length();
    for(ll i=0;i<mid;i++)
    {
        t[arr[i]-1]='0';
    }
    // cout<<len<<endl;
    ll tr=0,pr=0;
    while(tr<len && pr<check)
    {
        if(t[tr]==p[pr])
        {
            pr++;
        }
        tr++;
    }
    return (pr>=check);
 
}
 
 
 
int main()
{
    
    string t,p;
    cin>>t>>p;
    ll len=t.length();
    ll arr[len];
    for(ll i=0;i<len;i++)
    {
        cin>>arr[i];
    }
    ll l=-1,r=len;
    // cout<<r<<endl;
    while(r>l+1)
    {
        ll mid=(l+r)/2;
        if(good(arr,mid,t,p))
        {
            l=mid;
 
        }else
        {
            r=mid;
            
        }
    }
    // if(good(arr,l,t,p))
    cout<<l<<endl;
 
    return 0;
}
 
