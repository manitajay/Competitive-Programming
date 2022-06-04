// JAI BAJARANG BALI
 
// manitianajay45
 
// give me some sun shine, give me some rain, give me some little more chance to grow up once again 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007
 
 
ll ask(ll l, ll r)
{
    if (l >= r) 
    {
        return -1;
    }
    cout<<"? "<<l+1<<" "<<r+1<<endl;
    ll val;
    cin>>val;
    return val-1;
}
 
int main()
{
    ll n;
    cin>>n;
    ll smax;
    smax=ask(0,n-1);
    ll l,r;
    if(smax==0 || ask(0,smax)!=smax)
    {
        l=smax;
        r=n-1;
        ll m;
        
        while(r-l>1)
        {
            m=(l+r)/2;
            if(ask(smax,m)==smax)
            {
                r=m;
            }else
            {
                l=m;
            }
        }
        cout<<"! "<<r+1<<endl;
    }else
    {
        l=0;
        r=smax;
        ll m;
        
        while(r-l>1)
        {
            m=(l+r)/2;
            if(ask(m,smax)==smax)
            {
                l=m;
            }else
            {
                r=m;
            }
        }
        cout<<"! "<<l+1<<endl;
 
    }
    return 0;
}
