// JAI BAJARANG BALI
 
// manitianajay45
 
// give me some sunshine, give me some rain, give me another chance to grow up once again....
 
// sab moh maya hai....
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007
 
ll add(ll x, ll y)
{
    return (x % mod + y % mod) % mod;
}
 
ll mul(ll x, ll y)
{
    return ((x % mod) * (y % mod)) % mod;
}
 
int main()
{
    ll n, m;
    cin >> n >> m;
    ll arr[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (m == 1)
    {
        cout << "1" << endl;
        return 0;
    }
    vector<vector<ll>> vec(n + 1, vector<ll>(m + 1, 0));
 
    if (arr[0] == 0)
    {
        for (ll i = 1; i <= m; i++)
        {
            vec[0][i] = 1;
        }
    }
    else
    {
        ll x = arr[0];
        vec[0][x] = 1;
    }
 
    for (ll i = 1; i < n; i++)
    {
        if (arr[i] == 0)
        {
            for (ll j = 1; j <= m; j++)
            {
                if (j == 1)
                {
                    vec[i][j] = add(vec[i - 1][j], vec[i][j]);
                    vec[i][j] = add(vec[i - 1][j + 1], vec[i][j]);
                }
                else if (j == m)
                {
 
                    vec[i][j] = add(vec[i - 1][j], vec[i][j]);
                    vec[i][j] = add(vec[i - 1][j - 1], vec[i][j]);
                }
                else
                {
 
                    vec[i][j] = add(vec[i - 1][j], vec[i][j]);
                    vec[i][j] = add(vec[i - 1][j + 1], vec[i][j]);
                    vec[i][j] = add(vec[i - 1][j - 1], vec[i][j]);
                }
            }
        }
        else
        {
            ll j = arr[i];
            if (j == 1)
            {
                vec[i][j] = add(vec[i - 1][j], vec[i][j]);
                vec[i][j] = add(vec[i - 1][j + 1], vec[i][j]);
            }
            else if (j == m)
            {
 
                vec[i][j] = add(vec[i - 1][j], vec[i][j]);
                vec[i][j] = add(vec[i - 1][j - 1], vec[i][j]);
            }
            else
            {
 
                vec[i][j] = add(vec[i - 1][j], vec[i][j]);
                vec[i][j] = add(vec[i - 1][j + 1], vec[i][j]);
                vec[i][j] = add(vec[i - 1][j - 1], vec[i][j]);
            }
        }
    }
    ll ans=0;
 
    for(ll i=1;i<=m;i++){
        ans=add(ans,vec[n-1][i]);
    }
    cout<<ans<<endl;
}
