// JAI BAJARANG BALI
 
// manitianajay45
 
// sab moh maya hai..
 
// give me some sunshine, give me some rain, give me another chance to grow up once again
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
ll w,h,n;
 
bool good(ll x)
{
    return (x/w)*(x/h)>=n;
}
 
 
int main()
{
    // ll w,h,n;
    cin>>w>>h>>n;
 
    ll l=0;
    ll r=1;
    while(!good(r))
    {
        r*=2;
    }    
 
    while(r>l+1)
    {
        ll mid=(l+r)/2;
        if(good(mid))
        {
            r=mid;
        }else{
            l=mid;
        }
    }
    cout<<r<<endl;
    return 0;
}
