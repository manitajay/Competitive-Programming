// JAI BAJARANG BALI
 
// manitianajay45
 
// sab moh maya hai...
 
// give me some sunshine, give me some rain, give me another chance to grow up once again
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
ll m,n;
ll ans[100005]={0};
bool good(ll time, ll t[], ll z[] , ll y[])
{
    ll total=0;
    for(ll i=0;i<n;i++)
    {
        total+=((time/(z[i]*t[i] + y[i]))*z[i]);
        ll rem= time%(z[i]*t[i] + y[i]);
        if(rem/t[i]>z[i])
        {
            total+=z[i];
        }else{
            total+=(rem/t[i]);
        }
 
    }
    // cout<<total<<" ";
    // cout<<time<<endl;
    return total>=m;
 
}
 
void result(ll time, ll t[], ll z[] , ll y[],ll ans[])
{
    ll total=0;
 
    for(ll i=0;i<n;i++)
    {
        ans[i]+=(time/(z[i]*t[i] + y[i]))*z[i];
        ll rem= time%(z[i]*t[i] + y[i]);
        if(rem/t[i]>z[i])
        {
            ans[i]+=z[i];
        }else{
            ans[i]+=(rem/t[i]);
        }
        total+=ans[i];
        if(total>=m)
        {
            ans[i]-=(total-m);
            return;
        }
 
    }
    
 
}
 
int main()
{
    
    cin>>m>>n;
    ll t[n],z[n],y[n];
    ll mn=INT_MAX;
    ll b=0;
    for(ll i=0;i<n;i++)
    {
        cin>>t[i]>>z[i]>>y[i];
        if(mn>t[i])
        {
            mn=t[i];
            b=i;
        }
    }
    
    // memset(ans,0,sizeof(ans));
    
    ll l=-1;
    ll r=1e9;
    
    // cout<<"value of r: ";
    // cout<<r<<endl;
 
    while(r>l+1)
    {
        ll mid=(l+r)/2;
        if(good(mid,t,z,y))
        {
            r=mid;
        }else
        {
            l=mid;
        }
    }
    result(r,t,z,y,ans);
    cout<<r<<endl;
    for(ll i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
 
    
}
