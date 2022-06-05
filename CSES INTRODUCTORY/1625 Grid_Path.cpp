// JAI BAJARANG BALI

// manitianajay45

// give me some sunshine, give me some rain, give me another chance to grow up once again....

// sab moh maya hai....


/*
try to Optimize as much as you can.

two cases that has to be terminated-
case 1(Adjacency case)- when next element in same direction as it track before if he can not move in that direction and its left and right or up and down issafe then we can terminate there.
1 1 1 1 1 1 1 
0 0 0 0 1* 0 1
0 0 0 0 1 1 1
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0

Case -II (corner case): 
1 1 1 1 1 1 1 
0 0 0 0 0 0 1
0 0 0 0 1 1 1
0 0 0 0 1 1 1
0 0 0 1* 0 0 1
0 0 0 1 1 1 1
0 0 0 0 0 0 0

here 1* is the last point where we are currently.

*/

#include <bits/stdc++.h>
using namespace std;

#define ll int

ll n = 6;
ll xrr[4] = {-1, 0, 1, 0};
ll yrr[4] = {0, -1, 0, 1};
string s = "ULDR";
bool visited[7][7];

ll dp[7][7];

bool issafe(ll x, ll y)
{
    if (x >= 0 && y >= 0 && x <= n && y <= n && !visited[x][y])
    {
        return true;
    }
    return false;
}

bool isch(ll x, ll y)
{
    if (x >= 0 && y >= 0 && x <= n && y <= n && visited[x][y])
    {
        return true;
    }
    return false;
}
string yy;

bool check(ll X, ll Y, ll x, ll y, ll i)
{
    ll xr = (X - x);
    ll yr = (Y - y);

    // if(issafe(X+xr,Y+yr)){
    // return false;
    // }

    

    if (issafe(X + xr, Y + yr))
    {

        if (xr != 0 && issafe(X + xr, Y) && issafe(X, Y + 1) && isch(X + xr, Y + 1))
        {
            return true;
        }

        if (xr != 0 && issafe(X + xr, Y) && issafe(X, Y - 1) && isch(X + xr, Y - 1))
        {
            return true;
        }

        if (yr != 0 && issafe(X, Y + yr) && issafe(X + 1, Y) && isch(X + 1, Y + yr))
        {
            return true;
        }

        if (yr != 0 && issafe(X, Y + yr) && issafe(X - 1, Y) && isch(X - 1, Y + yr))
        {
            return true;
        }
        return false;
    }
    if (xr == 0 && issafe(X + 1, Y) && issafe(X - 1, Y))
    {
        return true;
    }

    if (yr == 0 && issafe(X, Y + 1) && issafe(X, Y - 1))
    {
        return true;
    }
    if (X == n && Y == 0 && i != yy.length())
    {
        return true;
    }
    return false;
}

ll ans = 0;
void rec(ll x, ll y, ll i)
{

    // if(dp[x][y]!=-1){
    // return dp[x][y];
    // }
    visited[x][y] = true;

    // cout<<"YES"<<endl;

    if (i == yy.length())
    {
        // cout<<"yes"<<endl;
        if (x == n && y == 0)
        {
            ans++;
        }
        visited[x][y] = false;
        return;
    }

    if (x == n && y == 0)
    {
        // cout<<i<<endl;
        visited[x][y] = false;
        return;
    }

    for (ll j = 0; j < 4; j++)
    {
        ll X = x + xrr[j];
        ll Y = y + yrr[j];
        if (issafe(X, Y) && (s[j] == yy[i] || yy[i] == '?'))
        {

            if (!check(X, Y, x, y, i + 1))
            {
                // cout<<X<<" "<<Y<<endl;
                rec(X, Y, i + 1);
            }
        }
    }
    visited[x][y] = false;
    // return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> yy;
    memset(visited, false, sizeof(visited));
    memset(dp, -1, sizeof(dp));
    rec(0, 0, 0);
    cout << ans << endl;

    return 0;
}
