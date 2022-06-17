// JAI BAJARANG BALI
 
// manitianajay45
 
// give me some sunshine, give me some rain, give me another chance to grow up once again....
 
// sab moh maya hai....
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll int
#define mod 1000000007
 
ll add(ll x, ll y)
{
    return (x % mod + y % mod) % mod;
}
 
ll mul(ll x, ll y)
{
    return ((x % mod) * (y % mod)) % mod;
}
ll n, x,i,j,val;
ll dp[105][1000005];
vector<ll> cn(105,0);
 
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> x;
    // cout<<"YES"<<endl;
    // cout<<"YES";
 
    for (i = 1; i <= n; i++)
    {
        
        cin >> val;
        cn[i]=val;
        
 
    }
    dp[0][0]=1;
   
    for (i = 1; i <= n; i++)
    {
        
        for (j = 0; j<=x; j++)
        {
            
            dp[i][j] =dp[i-1][j];
            
            val = j - cn[i];
            if(val>=0)
            {
                dp[i][j] = add(dp[i][j], dp[i][val]);
            }
        }
        
    }
    
    cout <<dp[n][x]<< endl;
 
    return 0;
}
