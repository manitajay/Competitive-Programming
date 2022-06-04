// JAI BAJARANG BALI
 
// manitianajay45
 
// give me some sunshine, give me some rain ,give me another chance to grow up once again
 
// sab moh maya hai....
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007
 
ll askand(ll a, ll b){
    cout<<"and "<<a<<" "<<b<<endl;
    ll val;
    cin>>val;
    return val;
}
 
ll askor(ll a,ll b){
    cout<<"or "<<a<<" "<<b<<endl;
    ll val;
    cin>>val;
    return val;
}
 
 
int main(){
    ll n,k;
    cin>>n>>k;
    vector<ll> v;
    ll a12,a23,a13;
    a12=askand(1,2) + askor(1,2);
    a23=askand(2,3) + askor(2,3);
    a13=askand(1,3) + askor(1,3);
 
    ll a1,a2,a3;
    a1=(a12-a23+a13)/2;
    a3=a13-a1;
    a2=a12-a1;
    v.push_back(a1);
    v.push_back(a2);
    v.push_back(a3);
 
    for(ll i=4;i<=n;i++){
        ll vl=askand(1,i) + askor(1,i);
        v.push_back(vl-a1);
    }
    sort(v.begin(),v.end());
 
    cout<<"finish "<<v[k-1]<<endl;
    return 0;
}
