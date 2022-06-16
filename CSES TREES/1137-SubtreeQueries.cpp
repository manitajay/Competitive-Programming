// JAI BAJARANG BALI
 
// manitianajay45
 
// give me some sunshine, give me some rain , give me another chance to grow up once again....
 
// sab moh maya hai....
 
/*
basically approach is simple firslty we stored dfs traversal into a vector now we know queries;

query1(i,val):- update ith node val;

query2(i):-> sum of all the  node in subtree;  which will be equal to :- sum(vec[stnode],vec[stnode+child[stnode]);
where child[i] denotes the element in a subtree of ith node;

now we can constuct a segment tree to answer the queries;

*/
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007
ll n,q;

vector<ll> arr(200005,0);

vector<ll> graph[200005];

vector<ll> child(200005,1);
vector<bool> visited(200005,false);

vector<ll> vec;
vector<ll> pos(200005,0);


void dfs(ll v){
    visited[v]=true;
    vec.push_back(v);
    for(auto u:graph[v]){
        if(!visited[u]){
            dfs(u);
            child[v]+=child[u];
        }
    }
} 




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

    seg[x]=seg[2*x+1]+seg[2*x+2];
}

ll sum(ll l,ll r,ll x,ll lf,ll rf){
    if(lf>=l && rf<=r){
        return seg[x];
    }else if(lf>=r || rf<=l){
        return 0;
    }
    ll mid=(lf+rf)/2;
    return sum(l,r,2*x+1,lf,mid)+sum(l,r,2*x+2,mid,rf);
}
 


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>q;

    for(ll i=0;i<n;i++){
        cin>>arr[i];

    }


    for(ll i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v;
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(0);

    for(ll i=0;i<n;i++){
        pos[vec[i]]=i;
        st(i,arr[vec[i]],0,0,n);

    }
    // for(auto i:vec){
    //     cout<<i<<" ";
    // }
    // cout<<endl;

    while(q--){
        ll tp;
        cin>>tp;
        if(tp==1){
            ll s,x;
            cin>>s>>x;
            s--;
            s=pos[s];
            st(s,x,0,0,n);
        }else{
            ll s;
            cin>>s;
            s--;

            ll l=pos[s];
            ll r=l+child[s];
            // cout<<l<<" "<<r<<endl;
            // cout<<arr[l]<<" "<<arr[r-1]<<endl;
            ll ans=sum(l,r,0,0,n);
            cout<<ans<<endl;
        }
    }
 
    return 0;
}
