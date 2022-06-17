// JAI BAJARANG BALI

// manitianajay45

// give me some sunshine, give me some rain, give me another chance to grow up once again....

// sab moh maya hai....

#include <bits/stdc++.h>
using namespace std;

#define ll long long
string a,b;

ll dp[110][110][13][2][2][2];

ll rec(string x,string y,ll sm1,ll mul,ll sum,ll i,ll tight,ll uptight,ll prevzeros){
    if(sum>sm1 || (sm1-sum)>(y.length()-i)*9){
        return 0;
    }
    if(i==x.length()){
        
        if(mul==0 && sum==sm1){
            // cout<<sum<<endl;
            return 1;
        }
        return 0;
    }
    if(dp[mul][sum][i][tight][uptight][prevzeros]!=-1){
        return dp[mul][sum][i][tight][uptight][prevzeros];
    }
    
    
    ll lb=(tight==1)?(x[i]-'0'):0;
    ll ub=(uptight==1)?(y[i]-'0'):9;
    ll an=0;

    for(int j=lb;j<=ub;j++){
        ll pv=prevzeros;
        if(prevzeros==1 && j==0){
            an+=(rec(x,y,sm1,mul,sum+j,i+1,tight,0,prevzeros));

            continue;
        }else if(prevzeros==1){
            pv=0;
        }
        ll mulp=(mul*j)%sm1;
        ll tight1=((tight==1)&&(j==lb))?1:0;
        ll uptight1=((uptight==1)&&(j==ub))?1:0;
        an+=(rec(x,y,sm1,mulp,sum+j,i+1,tight1,uptight1,pv));
    }
    return dp[mul][sum][i][tight][uptight][prevzeros]=an;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    for(ll tt=1;tt<=t;tt++){
        cin>>a>>b;

        string temp="";
        ll val=b.length()-a.length();
        while(val--){
            temp+="0";
        }
        temp+=a;
        // cout<<temp<<endl;

        ll ans=0;
        for(ll sm1=1;sm1<=109;sm1++){
            memset(dp,-1,sizeof(dp));
            ans+=rec(temp,b,sm1,1,0,0,1,1,1);
        }
        cout<<"Case #"<<tt<<": ";
        cout<<ans<<endl;


    }

    return 0;
}
