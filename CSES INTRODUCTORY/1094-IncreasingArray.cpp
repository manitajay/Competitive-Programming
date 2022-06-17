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
    cin>>n;
    ll arr[n];
    ll ans=0;
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        if(i>0){
            if(arr[i]<arr[i-1]){
                ans+=(arr[i-1]-arr[i]);
                arr[i]=arr[i-1];
            }
        }

    }
    cout<<ans<<endl;

    return 0;
}
