ll fact[500005];
 
ll sum(ll x,ll y){
    return (x%mod + y%mod)%mod;
}
 
ll mul(ll x,ll y){
    return ((x%mod)*(y%mod))%mod;
}
 
 
ll modInverse(ll a, ll m)
{
    ll m0 = m;
    ll y = 0, x = 1;
 
    if (m == 1)
        return 0;
 
    while (a > 1) {
        ll q = a / m;
        ll t = m;
        m = a % m, a = t;
        t = y;
        y = (x - mul(q, y)+mod)%mod;
        x = t;
    }
 
    if (x < 0)
        x = sum(x,m0);
 
    return x;
}
 
 
ll ncr(ll n,ll r){
    ll ans=(fact[n]);
    ans=mul(ans,modInverse(fact[n-r],mod));
    ans=mul(ans,modInverse(fact[r],mod));
    return ans;
}
