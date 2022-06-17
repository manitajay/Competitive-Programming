// JAI BAJARANG BALI
 
// manitianajay45
 
// sab moh maya hai..
 
// give me some sunshine, give me some rain, give me another chance to grow up once again
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
ll n,k;
 
 
bool notgood(double x,ll arr[])
{
    ll total=0;
    for(ll i=0;i<n;i++)
    {
        total+=((ll)(arr[i]/x));
    }
    if(total<k)
    {
        return true;
    }
    return false;
 
}
 
 
int main()
{
    // ll w,h,n;
    cin>>n>>k;
    ll arr[n];
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }
 
    double l=0;
    double r=1;
    while(!notgood(r,arr))
    {
        r*=2;
    }    
     cout << setprecision(20) ;
    while(r>l+0.0000001)
    {
        double mid=(l+r)/2.0;
        if(notgood(mid,arr))
        {
            r=mid;
        }else{
            l=mid;
        }
    }
    cout<<l<<endl;
    return 0;
}
