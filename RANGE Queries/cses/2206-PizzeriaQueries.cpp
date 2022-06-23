// JAI BAJARANG BALI

// manitianajay45

// give me some sunshine, give me some rain ,give me another chance to grow up once again....

// sab moh maya hai....

#include <bits/stdc++.h>
using namespace std;

#define ll long long


vector<ll> seg(800005,INT_MAX);
vector<ll> seg1(800005,INT_MAX);




void set1(ll i,ll val,ll x,ll l,ll r){
    if(r-l==1){
        seg[x]=val;
        return ;
    }
    ll mid=(l+r)/2;

    if(i<mid){
        set1(i,val,2*x+1,l,mid);

        
    }else{
        set1(i,val,2*x+2,mid,r);
    }

    seg[x]=min(seg[2*x+1],mid-l+seg[2*x+2]);
}


ll ans(ll i,ll x,ll lf,ll rf){

    if(rf-lf==1){
        return seg[x];
    }
    ll mid=(lf+rf)/2;

    if(i<mid){
        return min(ans(i,2*x+1,lf,mid),seg[2*x+2]+mid-i);
    }
    return ans(i,2*x+2,mid,rf);
}


void set2(ll i,ll val,ll x,ll l,ll r){
    if(r-l==1){
        seg1[x]=val;
        return ;
    }
    ll mid=(l+r)/2;

    if(i<mid){
        set2(i,val,2*x+1,l,mid);

    }else{
        set2(i,val,2*x+2,mid,r);

    }
    seg1[x]=min(seg1[2*x+1],mid-l+seg1[2*x+2]);


}


ll ans1(ll i,ll x,ll lf,ll rf){

    if(rf-lf==1){
        return seg1[x];
    }
    ll mid=(lf+rf)/2;

    if(i<mid){
        return min(ans1(i,2*x+1,lf,mid),seg1[2*x+2]+mid-i);
    }
    return ans1(i,2*x+2,mid,rf);
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
        set2(n-i-1,x,0,0,n);
    }

    while(q--){

        ll tp;
        cin>>tp;
        if(tp==1){
            ll i,val;
            cin>>i>>val;
            i--;
            set1(i,val,0,0,n);
            set2(n-i-1,val,0,0,n);
            continue;
        }

        ll x;
        cin>>x;

        x--;
        ll an=ans(x,0,0,n);
        ll an1=ans1(n-x-1,0,0,n);
        an=min(an,an1);
        cout<<an<<endl;


    }
    return 0;
}
