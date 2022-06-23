// JAI BAJARANG BALI

// manitianajay45

// give me some sunshine, give me some rain ,give me another chance to grow up once again....

// sab moh maya hai....

#include <bits/stdc++.h>
using namespace std;

#define ll long long


struct node{
    ll prefix,suffix,mx,total;
};

vector<node> seg(800005, {0,0,0,0});


node merge(node a,node b){
    node c;
    c.prefix=max(a.total+b.prefix,a.prefix);
    c.suffix=max(a.suffix+b.total,b.suffix);
    c.total=a.total+b.total;
    c.mx=max(a.mx,b.mx);
    c.mx=max(c.mx,c.suffix);
    c.mx=max(c.mx,c.prefix);
    c.mx=max(c.mx,a.suffix+b.prefix);
    return c;
}



void set1(ll i,ll val,ll x,ll l,ll r){
    if(r-l==1){
        seg[x].total=val;
        seg[x].mx=max(0ll,val);
        seg[x].prefix=max(0ll,val);
        seg[x].suffix=max(0ll,val);
        return ;
    }
    ll mid=(l+r)/2;

    if(i<mid){
        set1(i,val,2*x+1,l,mid);
    }else{
        set1(i,val,2*x+2,mid,r);
    }
    seg[x]=merge(seg[2*x+1],seg[2*x+2]);
}


node ans(ll l,ll r,ll x,ll lf,ll rf){
    if(lf>=l && rf<=r){
        return seg[x];
    }else if(lf>=r || rf<=l){
        return {0,0,0,0};
    }
    ll mid=(lf+rf)/2;
    return merge(ans(l,r,2*x+1,lf,mid),ans(l,r,2*x+2,mid,rf));
}





int main()
{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    ll n, q;
    cin >> n >> q;
    
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin>>x;

        set1(i,x,0,0,n);
    }

    while(q--){
            ll i,u;
            cin>>i>>u;
            i--;
            set1(i,u,0,0,n);
            
        
    
        node an=ans(0,n,0,0,n);
        cout<<an.mx<<endl;
    }
    return 0;
}
