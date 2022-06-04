// JAI BAJARANG BALI
 
// manitianajay45
 
// give me some sunshine, give me some rain, give me another chance to grow up once again
 
// sab moh maya hai....
 
// waiting....
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
// 1 2 0 3 4
 
ll ask(ll i, ll j, ll k)
{
    cout << "? " << i << " " << j << " " << k << endl;
    ll val;
    cin >> val;
    
    return val;
}
 
int main()
{
    ll t;
    cin >> t;
    while(t--){
    ll n;
    cin >> n;
    ll j = 0;
    vector<ll> ss;
 
    for (ll i = 1; i <= n; i++)
    {
        ss.push_back(i);
    }
 
    while ((ll)ss.size() > 2)
    {
        vector<ll> s1;
        vector<bool> visited(n+1,false);
        for (ll i = 0; i+4 <= (ll)ss.size(); i+=4)
        {
            ll a = ss[i];
            ll b = ss[i + 1];
            ll c = ss[i + 2];
            ll d = ss[i + 3];
 
            ll val[4];
            val[0] = ask(a, b, c);
            val[1] = ask(a, b, d);
            val[2] = ask(a, c, d);
            val[3] = ask(b, c, d);
 
            ll mn = 0;
            for (ll k = 0; k < 4; k++)
            {
                mn = max(mn, val[k]);
            }
            ll ans1, ans2;
            if(val[0]==mn && val[1]==mn){
                ans1=a;
                ans2=b;
            }else if(val[0]==mn && val[2]==mn){
                ans1=a;
                ans2=c;
            }else if(val[0]==mn && val[3]==mn){
                ans1=b;
                ans2=c;
            }else if(val[1]==mn && val[2]==mn){
                ans1=a;
                ans2=d;
            }else if(val[1]==mn && val[3]==mn){
                ans1=b;
                ans2=d;
            }else if(val[2]==mn && val[3]==mn){
                ans1=c;
                ans2=d;
            }
            if(!visited[ans1]){
                visited[ans1]=true;
                s1.push_back(ans1);
            }
            
            if(!visited[ans2]){
                visited[ans2]=true;
                s1.push_back(ans2);
            }
            
        }
 
        ll len=ss.size();
        if(len%4!=0 && len>=4){
            for(ll j=len-1;j>=len-len%4;j--){
                s1.push_back(ss[j]);
            }
        }
        
        if(s1.size()==3){
            for(ll k=1;k<=n;k++){
                if(s1[0]!=k && s1[1]!=k && s1[2]!=k){
                    s1.push_back(k);
                    break;
                }
            }
        }else if(s1.size()==1){
            for(ll k=1;k<=n;k++){
                if(s1[0]!=k){
                    s1.push_back(k);
                    break;
                }
            }
        }
        ss=s1;
    
 
 
        
    }
    
 
    cout<<"! ";
    for(auto i:ss){
        cout<<i<<" ";
    }
    
    cout<<endl;
    }
 
    return 0;
}
