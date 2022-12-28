// JAI BAJARANG BALI

// manitianajay45

// give me some sunshine, give me some rain, give me another chance to grow up once again....

// sab moh maya hai....

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;


    vector<ll> vec;

    ll temp=n;
    while(temp!=0){
        vec.push_back(temp%2);
        temp/=2;
    }

    reverse(vec.begin(),vec.end());
    ll cnt=vec.size() -1;

    ull ans=0;

    ll val=0;

    // ll ans1=0;
    // for(ll i=1;i<=n;i++){
    //     temp=i;
    //     while(temp!=0){
    //         ans1+=temp%2;
    //         temp/=2;
    //     }
    // }

    // cout<<ans1<<e
    ll vl=pow(2,cnt);
    for(auto i:vec){
        // cout<<i<<" ";
        
        if(i==1){
            if(cnt>=0){
                ans+=(ull)((cnt)*(ull)(vl/2));
                ans+=(ull)((ull)(vl)*(val));
            }
            val++;
        }
        vl/=2;


        cnt--;
    }
    // cout<<endl;
    ans+=val;


    cout<<ans<<endl;





    return 0;
}
