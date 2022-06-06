// JAI BAJARANG BALI

// manitianajay45

// give me some sunshine, give me some rain, give me another chance to grow up once again....

// sab moh maya hai....

// waiting....

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll solve(ll k, ll coins[], ll crr[], ll n)
{

    ll dp[k + 1];
    memset(dp, 0, sizeof(dp));

    for (ll i = 1; i <= n; i++)
    {
        for (ll w = k; w >= 0; w--)
        {

            if (coins[i - 1] <= w)

                dp[w] = max(dp[w], dp[w - coins[i - 1]] + crr[i - 1]);
        }
    }
    return dp[k];
}


int main()
{
    ll t;
    cin >> t;
    ll cost[1025];
    memset(cost,1000000,sizeof(cost));
    cost[1] = 0, cost[2] = 1;
    for (int i = 3; i < 1024; i++) {
        for (int j = i - 1; j >= 1; j--) {
            int z = i - j;
            int x = j / z;
            if (x > 0 && (j + (j / x)) == i) {
                cost[i] = min(cost[i], 1 + cost[j]);
            }
        }
    }
    // for(ll i=1;i<=10;i++)
    // {
    //     cout<<cost[i]<<" ";
    // }

    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        // ll arr[n];
        ll brr[n];
        ll crr[n];

        for (ll i = 0; i < n; i++)
        {
            cin >> brr[i];
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> crr[i];
        }

        ll coins[n];
        // memset(coins, 0, sizeof(coins));
        ll vlll = 0;
        for (ll i = 0; i < n; i++)
        {
            coins[i]=cost[brr[i]];
            vlll+=(cost[brr[i]]);
        }
        k = min(k, vlll);

        // cout<<endl;
        // for (ll i = 0; i < n; i++)
        // {
        //     cout << coins[i] << " ";
        // }
        // cout << endl;
        ll ans = solve(k, coins, crr, n);
        cout << ans << endl;
    }
    return 0;
}
