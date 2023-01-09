
#define ll long long


ll n,m;



ll power(ll a,ll b,ll mod){
    ll val=a;


    ll ans=1;

    ll temp=b;
    while(temp!=0){
        if(temp%2){
            ans*=(val);
            ans%=mod;
        }
        val*=val;
        val%=mod;
        temp/=2;
    }

    return ans;




}

ll sum(ll x,ll y){

    return (x%m + y%m)%m;

}


ll mul(ll x,ll y){

    return ((x%m)*(y%m))%m;

}


ll subs(ll x,ll y){
    return (x%m - y%m + m)%m;
}



ll fact[3000005];
ll inver[3000005];

void calculate(){
    // cout<<"YES"<<endl;

    fact[0]=1;
    fact[0]%=m;


    for(ll i=1;i<=3000004;i++){
        fact[i]=(fact[i-1]*i)%m;
    }

    inver[3000004]=power(fact[3000004],m-2,m);

    for(ll i=3000004;i>0;i--){
        inver[i-1]=inver[i]*i;
        inver[i-1]%=m;
    }



}


ll nCr(ll n,ll r){
    return (((fact[n]*inver[r])%m)*inver[n-r])%m;
}
