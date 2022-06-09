// JAI BAJARANG BALI

// manitianajay45

// give me some sunshine, give me some rain , give me another chance to grow up once again....

// sab moh maya hai....


// DSU


#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
ll n,m;

vector<ll> fn(200005,0);
vector<ll> cnt(2000005,0);

vector<ll> vec[200005];


ll mx;
ll sz=1;


void unite(ll u,ll v){
    // cout<<u<<" st"<<v<<endl;
    u=fn[u];
    v=fn[v];
    // cout<<u<<" "<<v<<endl;

    if(u!=v){
    if(cnt[u]!=0 && cnt[v]!=0){
        mx--;
    }
    if(cnt[u]<=cnt[v]){
        cnt[v]+=cnt[u];
        cnt[u]=0;
        sz=max(sz,cnt[v]);

        for(auto i:vec[u]){
            fn[i]=v;
            vec[v].push_back(i);
        }
    }else{
        cnt[u]+=cnt[v];
        cnt[v]=0;
        sz=max(sz,cnt[u]);

        for(auto i:vec[v]){
            fn[i]=u;
            vec[u].push_back(i);
        }
    }
    }
}






int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // ll n;
    cin >> n>>m;

    for(ll i=1;i<=n;i++){
        fn[i]=i;
        cnt[i]=1;
        vec[i].push_back(i);
    }
    // cout<<mx<<endl;
    mx=n;

    for (ll i = 0; i <m; i++)
    {
        ll u,v;
        cin>>u>>v;
        // mx--;
        unite(u,v);
        cout<<mx<<" "<<sz<<endl;

    }    

    return 0;
}
