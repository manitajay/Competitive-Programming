// JAI BAJARANG BALI
 
// manitianajay45
 
// give me some sunshine, give me some rain, give me another chance to grow up once again....
 
// sab moh maya hai....
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
ll n, m;
vector<string> vec(1005);
 
vector<vector<bool>> visited(1005, vector<bool>(1005, false));
 
bool issafe(ll x, ll y)
{
 
    if (x >= 0 && y >= 0 && x <= n - 1 && y <= m - 1 && !visited[x][y] && vec[x][y] == '.')
    {
        return true;
    }
    return false;
}
 
ll xrr[4] = {-1, 0, 0, 1};
ll yrr[4] = {0, -1, 1, 0};
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (ll i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        vec[i] = s;
    }
 
    ll ans = 0;
    queue<pair<ll, ll>> q;
 
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            
            if (!visited[i][j] && vec[i][j] == '.')
            {
                
                bool flag = true;
                visited[i][j] = true;
                ans++;
                q.push({i, j});
 
                while (!q.empty())
                {
                    pair<ll,ll> pr=q.front();
                    q.pop();
 
 
                    ll x =pr.first;
                    ll y =pr.second;
 
                    for (ll k = 0; k < 4; k++)
                    {
                        ll X = x + xrr[k];
                        ll Y = y + yrr[k];
                        if (issafe(X, Y))
                        {
                            q.push({X, Y});
                            visited[X][Y] = true;
                        }
                    }
                }
                
            }
        }
 
 
    }
 
    // for(ll i=0;i<n;i++){
    //     for(ll j=0;j<m;j++){
    //         cout<<visited[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
 
    cout << ans << endl;
    return 0;
}
