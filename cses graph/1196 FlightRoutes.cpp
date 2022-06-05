// JAI BAJARANG BALI

// manitianajay45

// give me some sunshine, give me some rain, give me another chance to grow up once again....

// sab moh maya hai....

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n, m, k;

vector<pair<ll, ll>> graph[100005];
vector<ll> shortest(100005, -1);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    for (ll i = 0; i < m; i++)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        graph[u].push_back({v, c});
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 1});
    vector<ll> ans;
    vector<ll> cnt(n+1,0);
    while (!pq.empty())
    {
        pair<ll, ll> p = pq.top();
        pq.pop();
        cnt[p.second]++;
        if (p.second == n)
        {
            ans.push_back(p.first);
        }
        if(cnt[n]==k){
            // cout<<"YES"<<endl;
            break;
        }

        if(cnt[p.second]<=k){
        for (auto i : graph[p.second])
        {
                pq.push({i.second + p.first, i.first});
            
        }
        }
    }
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout << endl;

    return 0;
}
