// JAI BAJARANG BALI
 
// manitianajay45
 
// give me some sunshine, give me some rain, give me another chance to grow up once again....
 
// sab moh maya hai....
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
ll n, m;
 
struct edge{
    ll u,v,c;
};
 
 
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    vector<edge> edges;
    for(ll i=0;i<m;i++){
        ll u,v,c;
        cin>>u>>v>>c;
        edges.push_back({u,v,c});
    }
    vector<ll> d(n+1);
    vector<ll> par(n+1,-1);
    ll x=-1;
    for(ll i=0;i<n;i++){
        x=-1;
        for(auto j:edges){
            if(d[j.v]>d[j.u]+j.c){
                d[j.v]=d[j.u]+j.c;
                x=j.v;
                par[j.v]=j.u;
            }
        }
 
    }
 
    if(x==-1){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    vector<ll> vec;
 
    for(ll i=0;i<n;i++){
        x=par[x];
    }
 
    ll st=x;
    
    while(1){
        vec.push_back(x);
        x=par[x];
        if(x==st){
            vec.push_back(x);
            break;
        }
        
    }
 
 
    reverse(vec.begin(),vec.end());
    for(auto i:vec){
        cout<<i<<" ";
    }
    cout<<endl;
 
 
 
 
 
    
    return 0;
}
