// JAI BAJARANG BALI

// manitianajay45

// give me some sunshine, give me some rain, give me another chance to grow up once again....

// sab moh maya hai....

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n,m;

vector<ll> graph[100005];
vector<bool> visited(100005,false);
vector<ll> parent(100005,-1);
vector<ll> vec;


void dfs(ll u,ll pr){

    visited[u]=true;
    parent[u]=pr;
    if(vec.size()>=4){
        
        return ;
    }

    for(auto i: graph[u]){
        if(visited[i] && vec.size()<=3){
            ll nd=u;
            vec.clear();
            vec.push_back(i);


            while(nd!=i)
            {
                vec.push_back(nd);
                nd=parent[nd];
            }
            vec.push_back(i);

            
            reverse(vec.begin(),vec.end());
        }else{
            dfs(i,u);
        }
    }


}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;

    for(ll i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(ll i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i,-1);
            // cout<<"NO"<<endl;
            if(vec.size()>=4){
                cout<<vec.size()<<endl;
                for(auto j:vec){
                    cout<<j<<" ";
                }
                cout<<endl;
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;



    return 0;
}
