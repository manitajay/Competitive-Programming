// JAI BAJARANG BALI

// manitianajay45

// give me some sunshine, give me some rain ,give me another chance to grow up once again....

// sab moh maya hai....

#include <bits/stdc++.h>
using namespace std;

#define ll long long


// ll st[200005][25];
vector<ll> seg(800005,0);

void st(ll i,ll val,ll x,ll l,ll r){
    if(r-l==1){
        seg[x]=val;
        return ;
    }
    ll mid=(l+r)/2;
    if(i<mid){
        st(i,val,2*x+1,l,mid);
    }else{
        st(i,val,2*x+2,mid,r);
    }
    seg[x]=seg[2*x+1]^seg[2*x+2];
}


ll sum(ll l,ll r,ll x,ll lf,ll rf){
    if(lf>=l && r>=rf){
        return seg[x];
    }else if(lf>=r || rf<=l){
        return 0;
    }
    ll mid=(lf+rf)/2;

    return sum(l,r,2*x+1,lf,mid)^sum(l,r,2*x+2,mid,rf);

}

int main()
{

    ios_base::sync_with_stdio(false);
    
    cin.tie(NULL);
    

    ll n,q;
    cin>>n>>q;
    // cout<<"YES"<<endl;
    
    for(ll i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        st(i,x,0,0,n);
    }
    // cout<<"YES"<<endl;

    while(q--){
       
        ll l,r;
        cin>>l>>r;
        l--;
        // r--;
        ll ans=sum(l,r,0,0,n);
        cout<<ans<<endl;
        
    }
    return 0;
}
