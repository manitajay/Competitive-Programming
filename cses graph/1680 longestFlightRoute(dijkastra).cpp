// JAI BAJARANG BALI

// manitianajay45

// give me some sunshine, give me some rain, give me another chance to grow up once again....

// sab moh maya hai....

/*
This code is giving tle but this is also a method to solve this problem
basically assign every node -1 weight and apply dijkastra.
*/

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

#define ll int


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vector<ll> graph[n + 1];
    vector<ll> par(n + 1, -1);
    vector<ll> d(n + 1, 0);
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    d[1] = 0;
    par[1]=-1;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 1});
    while (!pq.empty())
    {
        pair<ll, ll> pr = pq.top();
        pq.pop();
        if (d[pr.second] < pr.first)
        {
            continue;
        }
        for (auto i : graph[pr.second])
        {
            if (d[i] > d[pr.second] - 1)
            {
                d[i] = d[pr.second] - 1;
                pq.push({d[i], i});
                par[i] = pr.second;
            }
        }
    }

    if (d[n] == 0)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout << (-1 * d[n] + 1) << endl;
    vector<ll> ans;
    ll nd = n;
    while (nd != -1)
    {
        ans.push_back(nd);
        nd = par[nd];
    }
    reverse(ans.begin(), ans.end());
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
