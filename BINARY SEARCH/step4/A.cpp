// JAI BAJARANG BALI
 
// manitianajay45
 
// sab moh maya hai....
 
// give me some sunshine, give me some rain, give me another chance to grow up once again
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007
ll n,d;
ll arr[100005];
 
 
bool ischeck(double x){
    double brr[n];
    for(ll i=0;i<n;i++){
        brr[i]=(double)arr[i]-x;
        if(i>=1){
            brr[i]+=brr[i-1];
        }
    }
    double mn=0.0;
    for(ll i=d-1;i<n;i++){
        if(brr[i]>=mn){
            return true;
        }
        mn=min(mn,brr[i-d+1]);
    }
    return false;
    
 
}
 
pair<ll,ll> find(double x){
    double brr[n];
    for(ll i=0;i<n;i++){
        brr[i]=(double)arr[i]-x;
        if(i>=1){
            brr[i]+=brr[i-1];
        }
    }
    double mn=0.0;
    ll in=-1;
    for(ll i=d-1;i<n;i++){
        if(brr[i]>=mn){
            // return true;
            return {in,i};
            
        }
        if(brr[i-d+1]<mn){
            in=i-d+1;
            mn=brr[i-d+1];
        }
        // mn=min(mn,brr[i-d+1]);
    }
    return {-1,-1};
    
 
}
 
int main(){
    
    cin>>n>>d;
    
    ll l1=101,r1=0;
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        l1=min(l1,arr[i]);
        r1=max(r1,arr[i]);
    }
    double l=(double)l1;
    double r=(double)r1;
 
    while(r>l+0.00000001){
        double mid=(l+r)/2.0;
        // cout<<mid<<endl;
        if(ischeck(mid)){
            l=mid;
        }else{
            r=mid;
        }
    }
 
    pair<ll,ll> pr=find(l);
    cout<<pr.first+2<<" "<<pr.second+1<<endl;
    
    return 0;
}
