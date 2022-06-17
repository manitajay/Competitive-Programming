// JAI BAJARANG BALI
 
// manitianajay45
 
// give me some sunshine, give me some rain, give me another chance to grow up once again....
 
// sab moh maya hai....
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll int
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    vector<bool> ch(200005,false);
    vector<ll> vec;
 
    vec.push_back(0);
    ll sz=0;
    
    for(ll i=0;i<n;i++){
        // cout<<i<<endl;
        // cout<<sz<<endl;
        ll tm=sz;
        for(ll j=0;j<=tm;j++){
            // cout<<vec[j]<<" ";
            ll in=vec[j]+arr[i];
            if(!ch[in]){
                ch[in]=true;
                vec.push_back(in);
                sz++;
            }
        }
    }
    cout<<sz<<endl;
    sort(vec.begin(),vec.end());
    for(ll i=1;i<=sz;i++){
        cout<<vec[i]<<" ";
    }
 
 
 
    return 0;
}
