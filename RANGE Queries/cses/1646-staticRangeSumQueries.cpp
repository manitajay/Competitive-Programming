// JAI BAJARANG BALI
 
// manitianajay45
 
// give me some sunshine, give me some rain ,give me another chance to grow up once again....
 
// sab moh maya hai....
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,q;
    cin>>n>>q;
    ll arr[n+1];
    arr[0]=0;
    for(ll i=1;i<=n;i++)
    {
        cin>>arr[i];
        arr[i]+=arr[i-1];
    }
    while(q--){
        ll l,r;
        cin>>l>>r;
        l--;
        ll ans=arr[r]-arr[l];
        cout<<ans<<endl;
    }
    return 0;
}
