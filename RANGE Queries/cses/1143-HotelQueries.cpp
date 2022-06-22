// JAI BAJARANG BALI

// manitianajay45

// give me some sunshine, give me some rain ,give me another chance to grow up once again....

// sab moh maya hai....

#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> seg(800005,0);


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

    seg[x]=max(seg[2*x+1],seg[2*x+2]);
}

ll in(ll val,ll x,ll l,ll r){
    if(r-l==1){
        return l;
    }

    ll mid=(l+r)/2;

    if(seg[2*x+1]>=val){
        return in(val,2*x+1,l,mid);
    }
    return in(val,2*x+2,mid,r);
}




int main()
{

    ios_base::sync_with_stdio(false);
    
    cin.tie(NULL);
    

    ll n,q;
    cin>>n>>q;
    ll arr[n];
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
        set1(i,arr[i],0,0,n);

    }

    // for(ll i=0;i<2*n-1;i++){
        // cout<<seg[i]<<" ";
    // }
    // cout<<endl;



    while(q--){
        ll v;
        cin>>v;
        if(seg[0]<v){
            cout<<"0"<<" ";
            continue;
        }
        ll i=in(v,0,0,n);
        arr[i]-=v;
        set1(i,arr[i],0,0,n);
        i++;
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
