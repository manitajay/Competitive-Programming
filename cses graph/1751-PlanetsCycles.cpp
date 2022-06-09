// JAI BAJARANG BALI

// manitianajay45

// give me some sunshine, give me some rain , give me another chance to grow up once again....

// sab moh maya hai....


/*
steps:-
1. firstly try to find out a cycle and its length then assign every node value equal to cycle length.
2. after that start traverse back to eveynodes parent and ans[par]=ans[child]+1; if(ans[par] not find before);

3. there would be one more case if we traversing node and we have already ans of a child then we started to traverse back from there:
  ans[par]=ans[child]+1; if(ans[par] not find before);
  
*/


#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
ll n;


vector<ll> graph[200005];
vector<ll> visited(200005,0);
vector<ll> par(200005,-1);
vector<pair<ll,bool>> ans(200005,{0,false});
ll cl=1;
void dfs(ll v){
    visited[v]=cl;
    for(auto u:graph[v]){
        if(visited[u]==0){
            par[u]=v;
            dfs(u);
        }

        if(visited[u]==cl){
            ll st=v;
            ll cyc=0;
            while(st!=u){
                cyc++;
                st=par[st];
            }
            st=v;
            cyc++;
            while(st!=u){
                ans[st].first=cyc;
                st=par[st];
            }
            // cyc++;
            ans[st].first=cyc;
            ans[st].second=true;
            ll prev=st;
            while(st!=-1){
                prev=st;
                st=par[st];
                if(!ans[st].second){
                    ans[st].first=ans[prev].first+1;
                    ans[st].second=true;
                }
            }
        }else if(visited[u]!=(-1*cl)){
            // cout<<"UES"<<endl;
            // cout<<u<<endl;
            ll st=v;
            ll prev=u;
            while(st!=-1 ){
                if(!ans[st].second){
                    ans[st].first=ans[prev].first+1;   
                    ans[st].second=true;
                } 
                prev=st;
                st=par[st];            
            }
            
            
        }
    }
    visited[v]=(-1*cl);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // ll n;
    cin >> n;

    for (ll i = 1; i <=n; i++)
    {
        ll x;
        cin>>x;
        
        graph[i].push_back(x);
    }   
    for(ll i=1;i<=n;i++){
        if(visited[i]==0){
            dfs(i);
            cl++;
        }
    }


    for(ll i=1;i<=n;i++){
        cout<<ans[i].first<<" ";
    }
    cout<<endl;



    return 0;
}
