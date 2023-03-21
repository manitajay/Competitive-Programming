#define ll long long
#define mod 998244353

vector<ll> seg(800005,-1e17);

void update(ll i,ll val,ll x,ll l,ll r){
    if(r-l==1){
        seg[x]=val;
        return;
    }
    ll mid=(r+l)/2;
    if(i<mid){
        update(i,val,2*x+1,l,mid);
    }else{
        update(i,val,2*x+2,mid,r);
    }
    seg[x]=max(seg[2*x+1],seg[2*x+2]);
}


ll query(ll l,ll r,ll x,ll lf,ll rf){
    if(lf>=l && rf<=r){
        return seg[x];
    }else if(rf<=l || lf>=r){
        return -1e17;
    }

    ll mid=(lf+rf)/2;
    return max(query(l,r,2*x+1,lf,mid),query(l,r,2*x+2,mid,rf));
}
