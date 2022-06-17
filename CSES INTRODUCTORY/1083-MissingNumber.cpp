// JAI BAJARANG BALI

// manitianajay45

// give me some sunshine, give me some rain, give me another chance to grow up once again....

// sab moh maya hai....

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
        ll n;
        cin >> n;
        ll val=0;
        for(ll i=0;i<n-1;i++){
            ll x;
            cin>>x;
            val=val^x;
            val=val^(i+1);
        }
        val^=n;
        cout<<val<<endl;
    return 0;
}
