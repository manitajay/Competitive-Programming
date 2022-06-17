// JAI BAJARANG BALI
 
// manitianajay45
 
// give me some sunshine, give me some rain, give me another chance to grow up once again....
 
// sab moh maya hai....
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007
 
ll n,m;
 
ll dp[1005][(1<<11)];
// vector<ll> nm;
 
void generate_next_mask(ll currentmask,ll i,ll next_mask,vector<ll> &nm){
    if(i==n){
        nm.push_back(next_mask);
        return ;
    }
 
 
    if(((currentmask>>i)&1)==1){
        generate_next_mask(currentmask,i+1,next_mask,nm);
    }else{
        generate_next_mask(currentmask,i+1,next_mask+(1<<i),nm);
        if(i!=n-1&& ((currentmask>>(i+1))&1)==0){
            generate_next_mask(currentmask,i+2,next_mask,nm);
        }
    }
 
}
 
 
ll ans(ll i,ll mask){
    if(i==m){
        if(mask==0){
            return 1;
        }
        return 0;
    }
 
    if(dp[i][mask]!=-1){
        return dp[i][mask];
    }
    ll an=0;
    // nm.clear();
    vector<ll> nm;
    generate_next_mask(mask,0,0,nm);
    // cout<<nm.size()<<endl;
 
    for(ll j: nm){
        // cout<<j<<"j ";
        an=(an%mod+ans(i+1,j)%mod)%mod;
    }
    return dp[i][mask]=an;
 
}
 
 
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m;
    memset(dp,-1,sizeof(dp));
    cout<<ans(0,0)<<endl;
 
    return 0;
}
