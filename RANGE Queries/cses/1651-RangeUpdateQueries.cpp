// JAI BAJARANG BALI

// manitianajay45

// give me some sunshine, give me some rain ,give me another chance to grow up once again....

// sab moh maya hai....

#include <bits/stdc++.h>
using namespace std;

#define ll long long


// ll st[200005][25];
vector<ll> seg(800005,0);

ll st(ll i,ll x,ll l,ll r){
    if(r-l==1){
        return seg[x];
    }
    ll mid=(l+r)/2;
    if(i<mid){
        
        return seg[x]+st(i,2*x+1,l,mid);
    }
    
    return seg[x]+st(i,2*x+2,mid,r);
    
}


void set1(ll l,ll r,ll val,ll x,ll lf,ll rf){
    if(lf>=l && r>=rf){
        seg[x]+=val;
        return ;
    }else if(lf>=r || rf<=l){
        return;
    }
    ll mid=(lf+rf)/2;

    set1(l,r,val,2*x+1,lf,mid);
    set1(l,r,val,2*x+2,mid,rf);

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
        set1(i,i+1,x,0,0,n);
    }
    // cout<<"YES"<<endl;

    // for(ll i=0;i<2n-1;i++){
    //     cout<<seg[i]<<" ";
    // }
    // cout<<endl;*

    while(q--){
        ll tp;
        cin>>tp;
        if(tp==1){
            ll a,b,u;
            cin>>a>>b>>u;
            a--;
            set1(a,b,u,0,0,n);
            continue;
        }
        ll i;
        cin>>i;
        i--;
        ll ans=st(i,0,0,n);
        cout<<ans<<endl;
        
    }
    return 0;
}
