// JAI BAJARANG BALI
 
// manitianajay45
 
// sab moh maya hai...
 
// give me some sunshine , give me some rain, give me another chance to grow up once again
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
double findmx(ll n,vector<pair<double,double>> vec,double pos)
{
    double mn= -DBL_MAX;
    double ans;
    for(ll i=0;i<n;i++)
    {
        double t= abs(vec[i].first-pos)/vec[i].second;
        if(t>mn)
        {
            mn=t;
            ans=vec[i].first;
        }
    }
    // cout<<mn<<" ";
 
    return ans;
 
}
 
void findmx1(ll n,vector<pair<double,double>> vec,double pos)
{
    double mn= -DBL_MAX;
    double ans;
    for(ll i=0;i<n;i++)
    {
        double t= abs(vec[i].first-pos)/vec[i].second;
        if(t>mn)
        {
            mn=t;
            ans=vec[i].first;
        }
    }
    cout<<mn<<" ";
 
 
}
 
int main()
{
 
    ll n;
    cin>>n;
    // double x[n],v[n];
    double l=-1000000000.0,r=1000000000.0;
 
    vector<pair<double,double>> vec;
    for(ll i=0;i<n;i++)
    {
        ll x,v;
        cin>>x>>v;
        vec.push_back(make_pair(x,v));
    }
 
    cout<< setprecision(7);
    sort(vec.begin(),vec.end());
    while(r>l+0.0000001)
    {
        double mid=(l+r)/2.0;
        if(findmx(n,vec,mid)<=mid)
        {
            r=mid;
        }else
        {
            l=mid;
        }
        
 
    }
    
    findmx1(n,vec,r);
 
 
 
    return 0;
}
