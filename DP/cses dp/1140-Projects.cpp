// JAI BAJARANG BALI
 
// manitianajay45
 
// give me some sunshine, give me some rain, give me another chance to grow up once again....
 
// sab moh maya hai....
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
// ll dp[5005][5005];
#define mod 1000000007
 
ll dp[505][130000];
 
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n;
    cin>>n;
    vector<pair<pair<ll,ll>,ll>> vec;
    vector<ll> vec1;
    vec1.push_back(0);
    for(ll i=0;i<n;i++){
 
        ll a,b,x;
        cin>>a>>b>>x;
        vec1.push_back(a);
        vec1.push_back(b);
        vec.push_back({{a,b},x});
    }
 
    sort(vec1.begin(),vec1.end());
    vec1.push_back(0);
    vector<ll> v;
    for(ll i=1;i<=(ll)(vec1.size());i++){
        if(vec1[i]!=vec1[i-1]){
            v.push_back(vec1[i-1]);
        }
    }
    ll sz=v.size();
 
    for(ll i=0;i<n;i++){
        ll a=vec[i].first.first;
        ll b=vec[i].first.second;
        // ll c=vec[i].second;
        a=lower_bound(v.begin(),v.end(),a)-v.begin();
        b=lower_bound(v.begin(),v.end(),b)-v.begin();
        vec[i].first.first=b;
        vec[i].first.second=a;
 
    }
 
 
    sort(vec.begin(),vec.end());
 
    vector<ll> vc;
    for(ll i=0;i<n;i++){
        vc.push_back(vec[i].first.first);
    }
 
 
    vector<ll> dp(sz+1,0);
    for(ll i=1;i<=sz;i++){
        ll l=lower_bound(vc.begin(),vc.end(),i)-vc.begin();
        ll r=upper_bound(vc.begin(),vc.end(),i)-vc.begin();
        dp[i]=dp[i-1];
 
        // cout<<l<<" "<<r<<endl;
        for(ll j=l;j<r;j++){
            ll in=vec[j].first.second;
            ll w=vec[j].second;
            dp[i]=max(dp[i],dp[in-1]+w);
        }
    }
 
    cout<<dp[sz]<<endl;
 
    // sort(vec.begin(),vec.end());
 
 
 
 
 
    return 0;
}
