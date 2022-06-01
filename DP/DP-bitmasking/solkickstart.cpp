// JAI BAJARANG BALI

// manitianajay45

// give me some sunshine, give me some rain ,give me another chance to grow up once again....

// sab moh maya hai....

// waiting....

#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll n;
string s;
bool dp[50005][(1<<6)+4];

vector<bool> checkpalli6(1<<6,false);
vector<bool> checkpalli5(1<<5,false);


bool ans(ll i,ll k5,ll k6){
    if(i>=5 && checkpalli5[k5]){
        return false;
    }
    if(i>=6 && checkpalli6[k6]){
        return false;
    }

    if(i==n){
        return true;

    }
    if(dp[i][k6]){
        return false;
    }

    dp[i][k6]=true;


    if(s[i]=='0' || s[i]=='?'){
        ll nk5=(k5<<1)&((1<<5) -1);

        ll nk6=(k6<<1)&((1<<6) -1);

        if(ans(i+1,nk5,nk6)){
            return true;
        }
        
    }
    
    if(s[i]=='1' || s[i]=='?'){
        ll nk5=((k5<<1) +1 )&((1<<5) -1);

        ll nk6=((k6<<1)+1)&((1<<6) -1);

        if(ans(i+1,nk5,nk6)){
            return true;
        }
        
    }
    return false;
}



int main(){

    for(ll i=0;i<(1<<5);i++){
        ll c=5;
        ll temp=i;
        string s="";
        while(c--){
            s+=(temp%2)?"1":"0";
            temp/=2;
        }
        string t=s;
        reverse(s.begin(),s.end());
        if(t==s){
            checkpalli5[i]=true;
        }
    }

    
    for(ll i=0;i<(1<<6);i++){
        ll c=6;
        ll temp=i;
        string s="";
        while(c--){
            s+=(temp%2)?"1":"0";
            temp/=2;
        }
        string t=s;
        reverse(s.begin(),s.end());
        if(t==s){
            checkpalli6[i]=true;
        }
    }

    ll t;
    cin>>t;
    for(ll tt=1;tt<=t;tt++){
        memset(dp,0,sizeof(dp));
        cin>>n;
        cin>>s;
        // cout<<n<<s<<endl;
        cout<<"Case #"<<tt<<": ";

        ll check=ans(0,0,0);

        if(check){
            cout<<"POSSIBLE"<<endl;
            continue;
        }

        cout<<"IMPOSSIBLE"<<endl;

        


        
    }
    return 0;
}
