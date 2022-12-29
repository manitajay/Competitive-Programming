// JAI BAJARANG BALI

// manitianajay45

// give me some sunshine, give me some rain, give me another chance to grow up once again....

// sab moh maya hai....

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long int
#define mod 1000000007

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;
    ll n=s.length();

    string ans="";

    map<char,ll> mp1;
    mp1['A']=1;
    mp1['C']=1;
    mp1['G']=1;
    mp1['T']=1;

    map<char,ll> mp2;
    mp2=mp1;
    ll cnt=0;
    for(ll i=0;i<n;i++){
        
        if(mp2[s[i]]==1){
            mp2[s[i]]=0;
            cnt++;
        }
        if(cnt==4){

            // cout<<i<<endl;
            cnt=0;
            mp2=mp1;
            ans+=s[i];
        }
    }

    // cout<<ans<<endl;
    bool check=false;

    for(auto i:mp2){
        // cout<<i.first<<" "<<i.second<<endl;
        if(i.second==1){
            ans+=(i.first);
            check=true;
            break;
        }
    }

    if(!check){
        ans+="A";
    }


    cout<<ans<<endl;






    return 0;
}
