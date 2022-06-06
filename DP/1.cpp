// JAI BAJARANG BALI

// manitianajay45

// give me some sunshine, give me some rain ,give me another chance to grow up once again....

// sab moh maya hai....

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

ll dp[40005][500];

int main()
{
    ll t;
    cin >> t;
    ll N = 40005;
    vector<ll> vec;
    vector<ll> ans(N, 0);
    vector<bool> pali(N, false);
    vec.push_back(0);
    for (ll i = 1; i < N; i++)
    {
        ll temp = i;
        bool flag = false;
        vector<ll> bits;
        while (temp != 0)
        {
            ll val = temp % 10;
            bits.push_back(val);
            temp /= 10;
        }

        bool check = true;
        ll sz = bits.size();
        for (ll i = 0; i < (sz / 2); i++)
        {
            if (bits[i] != bits[sz - i - 1])
            {
                check = false;
                break;
            }
        }
        pali[i] = check;
        if (check)
        {
            vec.push_back(i);
        }
    }
    ll siz = vec.size();
    // dp[0][0] = 1;
    // cout << "YES" << endl;
    // dp[1][1] = 1;
    // siz=400;
    // cout << siz << endl;

    for (int j = 1; j <= siz; j++)
        dp[0][j] = 1;
    for (int i = 1; i < N; i++)
    {
        dp[i][0] = 0;
        for (int j = 1; j <= siz; j++)
        {
            if (vec[j] <= i)
                dp[i][j] = (dp[i][j - 1] + dp[i - vec[j]][j]) % mod;
            else
                dp[i][j] = dp[i][j - 1];
        }
    }
    // cout << "YES" << endl;

    while (t--)
    {
        ll n;
        cin >> n;
        cout << dp[n][siz-1] << endl;
    }
    return 0;
}
