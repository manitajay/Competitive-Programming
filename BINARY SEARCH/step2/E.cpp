// JAI BAJARANG BALI
 
// manitianajay45
 
// sab moh maya hai...
 
// give me some sunshine, give me some rain, give me another chance to grow up once again
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
double c;
bool good(double root)
{
    return root*root + sqrt(root)>=c;
}
 
 
 
int main()
{
    
    
    cin>>c;
 
    double l=0,r=1.0;
    while(!good(r))
    {
        r*=2;
    }
    cout<< setprecision(20);
    while(r>l+0.0000001)
    {
        double mid=(l+r)/2.0;
        if(good(mid))
        {
            r=mid;
        }else{
            l=mid;
        }
    }
    cout<<r<<endl;
    
 
 
    
}
