// JAI BAJARANG BALI
 
// manitianajay45
 
// sab moh maya hai..
 
// give me some sunshine, give me some rain, give me another chance to grow up once again
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
ll n,x,y;
 
 
bool good(ll z)
{
    return (z/x)+(z/y)>=n-1;
 
}
 
 
int main()
{
    // ll w,h,n;
    cin>>n>>x>>y;
    // n=n+1;
    if(n==1)
    {
        cout<<min(x,y)<<endl;
        return 0;
    }
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
    cout<<r+min(x,y)<<endl;
    return 0;
}
