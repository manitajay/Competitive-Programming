// JAI BAJARANG BALI

// manitianajay45

// sab moh maya hai....

// give me some sunshine, give me some rain, give me another chance to grow up once again

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

ll mulm(ll a,ll b){
    return ((a%mod)*(b%mod))%mod;
}

ll summ(ll a,ll b){
    return (a%mod + b%mod)%mod;
}

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = mulm(res , a);
        a = mulm(a,a);
        b >>= 1;
    }
    return res;
}


int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        if(k==0){
            cout<<"1"<<endl;
            continue;
        }
        if(n%2==1){


            ll ans=1;
            
            ans=mulm(ans,((binpow(2,(n-1)))+1));
            ll temp=ans;
            for(ll i=1;i<=k-1;i++){
                ans=mulm(ans,temp);
                ans%=mod;
                // ans+=binpow(2,i*(n-1));
            }
            cout<<ans%mod<<endl;
            
        }else{
            ll ans=1;
            
            ans=mulm(ans,((binpow(2,(n-1)))-1));
            ll temp=ans;
            // cout<<ans<<endl;
            for(ll i=1;i<=k-1;i++){
                ans=mulm(ans,temp);
                ans%=mod;
                // ans+=binpow(2,i*(n-1));
            }
            // cout<<ans<<endl;
            ll val1=1;
            for(ll i=1;i<=k;i++){
                if(i>=2){
                    val1=mulm(val1,binpow(2,(n-1))-1);
                    // cout<<"val1"<<val1<<endl;
                }
                ans=summ(ans,mulm(val1,binpow(2,(n)*(k-i))));
                // cout<<ans<<endl;
                // cout<<ans<<endl;
                ans%=mod;
            }
            cout<<ans%mod<<endl;
        }
    }
    return 0;
}
