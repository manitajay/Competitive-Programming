// JAI BAJARANG BALI

// manitianajay45

// give me some sunshine, give me some rain , give me another chacne to grow up once again....

// sab moh maya hai....

#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define mod 1000000007


int main(){
    string s;
    cin>>s;
    ll n=s.length();

    ll x=0;
    ll y=0;
    vector<ll> zrr(n,0);
    s+='*';
    for(ll i=1;i<n;i++){
        zrr[i]=max(0ll,min(zrr[i-x],(y-i+1)));

        while(i+zrr[i]<n && s[zrr[i]]==s[i+zrr[i]]){
            
            x=i;
            y=i+zrr[i];
            zrr[i]++;
        }

    }
    // for(ll i=0;i<n;i++){
    //     cout<<zrr[i]<<" ";
    // }
    // cout<<endl;

    for(ll i=n-1;i>=1;i--){
        if(i+zrr[i]==n){
            cout<<zrr[i]<<" ";
        }
    }
    cout<<endl;


    return 0;
    
}
