// JAI BAJARANG BALI

// manitianajay45

// give me some sunshine, give me some rain , give me another chance to grow up once again....

// sab moh maya hai....

/* 
  2SAT problem
  https://cses.fi/book/book.pdf
  page no - 160-162
/*



#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
ll n,m;

bool visited[200005][2];
string ans(200005,'*');
vector<pair<ll,ll>> graph[200005][2];
vector<pair<ll,ll>> order;
vector<pair<ll,ll>> graphr[200005][2];
ll vis[200005][2];
ll an=0;


void topo(ll v,ll tp){
    visited[v][tp]=true;
    for(auto u:graph[v][tp]){
        if(!visited[u.first][u.second]){
            topo(u.first,u.second);
        }
    }
    order.push_back({v,tp});
}
bool flag=true;

void dfs(ll v,ll tp){


    if(tp==0 && vis[v][1]==an){
        flag=false;
    }
    if(tp==1 && vis[v][0]==an){
        flag=false;
    }
    vis[v][tp]=an;
    if(ans[v]=='*'){
        if(tp==0){
            ans[v]='+';
        }else{
            ans[v]='-';
        }
    }
    
    for(auto u:graphr[v][tp]){
        if(vis[u.first][u.second]==0){
            dfs(u.first,u.second);
        }
    }

}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // ll n;
    cin >> n>>m;

    for (ll i = 0; i <n; i++)
    {
        ll u,v;
        char ui,vi;
        cin>>ui>>u>>vi>>v;

        ll fui,fvi;
        fui=(ui=='+')?1:0;
        fvi=(vi=='+')?1:0;
        if(fui==0){
            graph[u][1].push_back({v,fvi});
            graphr[v][fvi].push_back({u,1});
        }else{
            graph[u][0].push_back({v,fvi});
            graphr[v][fvi].push_back({u,0});
        }
        if(fvi==0){
            graph[v][1].push_back({u,fui});
            graphr[u][fui].push_back({v,1});
        }else{
            graph[v][0].push_back({u,fui});
            graphr[u][fui].push_back({v,0});
        }
        
       
    }
    for(ll i=1;i<=m;i++){
        if(!visited[i][0]){
            topo(i,0);
        }
        if(!visited[i][1]){
            topo(i,1);
        }
    }

    reverse(order.begin(),order.end());
    
    for(auto i:order){
        if(vis[i.first][i.second]==0){
            an++;
            dfs(i.first,i.second);
            if(!flag){
                break;
            }
            // an++;
        }
    }
    if(!flag){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    for(ll i=1;i<=m;i++){
        cout<<ans[i];
    }
    cout<<endl;
    

    return 0;
}
