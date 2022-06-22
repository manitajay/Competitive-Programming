// JAI BAJARANG BALI

// manitianajay45

// give me some sunshine, give me some rain ,give me another chance to grow up once again....

// sab moh maya hai....

#include <bits/stdc++.h>
using namespace std;

#define ll long long



int main()
{

    ios_base::sync_with_stdio(false);
    
    cin.tie(NULL);
    

    ll n,q;
    cin>>n>>q;
    // cout<<"YES"<<endl;
    vector<vector<ll>> vec(n+1,vector<ll>(n+1,0));
    for(ll i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(ll j=0;j<n;j++){
            if(s[j]=='*'){
                vec[i+1][j+1]=1;
            }else{
                vec[i+1][j+1]=0;
            }
        }

    }

    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            // vec[i][j]+=vec[i-1][j];
            vec[i][j]+=vec[i][j-1];
        }
    }

    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            vec[i][j]+=vec[i-1][j];
        }
    }
    // for(ll i=1;i<=n;i++){
    //     for(ll j=1;j<=n;j++){
    //         cout<<vec[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }



    while(q--){
        ll y1,x1,y2,x2;
        cin>>y1>>x1>>y2>>x2;
        ll ans=vec[y2][x2]-vec[y1-1][x2]-vec[y2][x1-1]+vec[y1-1][x1-1];
        cout<<ans<<endl;
        
    }
    return 0;
}
