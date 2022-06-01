// JAI BAJARANG BALI
 
// manitianajay45
 
// give me some sunshine, give me some rain ,give me another chance to grow up once again....
 
// sab moh maya hai....
 
// waiting....
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
 
 
ll fac[19];
 
ll val_bound(string s,ll i){
    if(i==s.length()){
        return 0;
    }
    ll val=s[i]-'0';
    if(i==0){
        return (((val-1)*fac[s.length()-i-1]) + val_bound(s,i+1));
    }
 
    ll prev=s[i-1]-'0';
    if(prev<val){
        return (((val-1)*fac[s.length()-i-1]) + val_bound(s,i+1));
    }
    if(prev==val){
        return ((val)*fac[s.length()-i-1]);
    }
 
 
    return (((val)*fac[s.length()-i-1]) + val_bound(s,i+1));
}
 
 
int main(){
    fac[0]=1;
    for(ll i=1;i<=18;i++){
        fac[i]=(fac[i-1]*9);
    }
 
 
 
    string a,b;
    cin>>a>>b;
 
    ll n=a.length(),m=b.length();
 
 
    bool checkb=false;
    for(ll i=1;i<m;i++){
        if(b[i]==b[i-1]){
            checkb=true;
            break;
        }
    }
    ll val1=val_bound(a,0);
    ll val2=val_bound(b,0);
    if(!checkb){
        val2++;
    }
 
    
 
    if(n==m){
 
        
 
        ll ans=(val2-val1);
        cout<<ans<<endl;
        return 0;
        
    }
    ll ans=0;
 
    for(ll i=n;i<m;i++){
        ans=(ans+fac[i]);
    }
    ans=(ans-val1);
 
    ans=(ans+val2);
    cout<<ans<<endl;
 
 
 
    
 
 
    return 0;
}
