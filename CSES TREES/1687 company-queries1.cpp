// JAI BAJARANG BALI
 
// manitianajay45
 
// give me some sunshine, give me some rain, give me another chance to grow up once again....
 
// sab moh maya hai....

/*
Binary  lifting.
https://cp-algorithms.com/graph/lca_binary_lifting.html

https://www.youtube.com/watch?v=FAfSArGC8KY&list=PLb3g_Z8nEv1j_BC-fmZWHFe6jmU_zv-8s&index=7&ab_channel=KartikArora

will suggest you to not watch complete video just take idea about binary lifting and try to implement by your self it is just same as sparse table.
*/
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

vector<ll> graph[200005];

vector<ll> ans(200005,0);

vector<bool> visited(200005,false);

ll dp[200005][20];

ll n,q;



void binlift(){
    for(ll i=1;i<20;i++){
        for(ll j=1;j<=n;j++){
            if(dp[j][i-1]==-1){
                dp[j][i]=-1;
                continue;
            }
            dp[j][i]=dp[dp[j][i-1]][i-1];
        }
    }


}


ll query(ll x,ll k){
    ll prev=x;
    for(ll i=20;i>=0;i--){
        if((k>>i)&1){
            // cout<<i<<"i"<<endl;
            prev=dp[prev][i];
            if(prev==-1){
                break;
            }

        }
    }    
    return prev;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>q;
    ll arr[n+1];
    arr[1]=-1;
    memset(dp,-1,sizeof(dp));
    dp[1][0]=-1;
    for(ll i=2;i<=n;i++){
        cin>>arr[i];
        dp[i][0]=arr[i];
        
    }

    // for(ll i=1;i<=n;i++)
    // {
    //     for(ll j=0;j<=3;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<"YES"<<endl;

    binlift();
    while(q--){
        ll x,k;
        cin>>x>>k;

        ll ans=query(x,k);
        cout<<ans<<endl;
    }








   
    
    return 0;
}
