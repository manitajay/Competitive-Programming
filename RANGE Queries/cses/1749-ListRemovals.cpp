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

    seg[x]=seg[2*x+1]+seg[2*x+2];
}
ll vll=0;
ll in(ll val,ll x,ll l,ll r){
    if(r-l==1){
        return l;
    }

    ll mid=(l+r)/2;

    if(vll+seg[2*x+1]>=val){
        return in(val,2*x+1,l,mid);
    }
    vll+=seg[2*x+1];
    return in(val,2*x+2,mid,r);

}




int main()
{

    ios_base::sync_with_stdio(false);
    
    cin.tie(NULL);
    

    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
        set1(i,1,0,0,n);

    }

    // for(ll i=0;i<2*n-1;i++){
    //     cout<<seg[i]<<" ";
    // }
    // cout<<endl;


    ll q=n;
    while(q--){
        ll v;
        cin>>v;
        vll=0;
        
        ll i=in(v,0,0,n);
        // cout<<i<<" i";
        
        cout<<arr[i]<<" ";

        set1(i,0,0,0,n);
    }
    cout<<endl;
    return 0;
}
