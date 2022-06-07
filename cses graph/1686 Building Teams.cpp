// JAI BAJARANG BALI
 
// manitianajay45
 
// give me some sunshine, give me some rain ,give me another chance to grow up once again....
 
// sab moh maya hai....

/*
test case for "impossible":
3 3
1 2 
1 3
2 3

basically using level order traversal technique using bfs if on the odd level we will give 1 to all the elements and on even level we will give 2
or we can use it using dfs simply maintaining a fucntion
dfs(node,flag);
where flag will be reverse after each iteration 
color=flag?1:2;
*/
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll int
 
ll n, m;
 
vector<ll> graph[100005];
 
vector<bool> visited(100005, false);
 
int main()
{
    cin >> n >> m;
    vector<pair<ll,ll>> edges;
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        edges.push_back({u,v});
    }
 
    queue<ll> q;
    vector<ll> ans(n + 1, 1);
    for (ll i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            while (!q.empty())
            {
                q.pop();
            }
            q.push(i);
            q.push(-1);
            ll an = 0;
            while (q.size() > 1)
            {
                ll u = q.front();
                q.pop();
                if (u == -1)
                {
                    an++;
                    q.push(-1);
                    continue;
                }
 
                if (an % 2 == 1)
                {
                    ans[u] = 2;
                }
 
                visited[u] = true;
                for (auto i : graph[u])
                {
                    if (!visited[i])
                    {
                        q.push(i);
                        visited[i] = true;
                    }
                }
            }
        }
    }
    bool flag=false;
    for(ll i=0;i<m;i++){
        if(ans[edges[i].first]==ans[edges[i].second]){
            flag=true;
            break;
        }
    }
 
    if(flag){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
 
    for(ll i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
 
 
    return 0;
}
