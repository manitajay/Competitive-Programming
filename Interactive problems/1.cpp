// JAI BAJARANG BALI
 
// manitianajay45
 
// give me some sunsushine, give me some rain,give me another chance to grow up once again....
 
// sab moh maya hai....
 
// waiting....

/*
  basically personally problem looks difficult to approach but after having look at constraint which are
queries<=31 and (a and b <= 2 x 10^9 ) by which i started thinking about bits.
so hint : bits. 
*/
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
 
 
ll ask(ll a,ll b){
    cout<<"? "<<a<<" "<<b<<endl;
    ll val;
    cin>>val;
    return val;
}
 
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        // ll val;
        // val=ask(1,3);
        vector<ll> bits;
        ll ans=0;
        ll cnt=0;
        
 
 
        for(ll i=0;i<30;i++){
            ll a=(1<<cnt) - ans;
            // cnt++;
            ll b=a + (1<<(cnt+1));
            ll val=ask(a,b);
            ll vll=(1<<(cnt));
 
            val/=vll;
            if(val%2==0){
                ans+=(1<<cnt);
            }
            cnt++;
        }
 
        cout<<"! "<<ans<<endl;
 
 
 
    }
    return 0;
}

