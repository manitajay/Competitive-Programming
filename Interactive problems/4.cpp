// JAI BAJARANG BALI
 
// manitianajay45
 
// give me some sunshine, give me some rain, give me another chance to grow up once again
 
// sab moh maya hai....
 
// waiting....
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
ll ask(ll a, ll b, ll c)
{
 
    cout << "? " << a << " " << b << " " << c << endl;
    ll val;
    cin >> val;
    return val;
}
 
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll N;
        cin >> N;
        ll val = ask(1, 2, 3);
        ll x, y;
        for (ll i = 2; i <= N-2; i++)
        {
            ll xh = ask(i, (i + 1), (i + 2));
            if (xh != val)
            {
                x=i;
                y=i+1;
                break;
            }
        }
 
 
        ll n = x;
        ll m=y;
        ll imp[N+1];
        ll fn1, fn2;
        for (ll i = 1; i <= N; i++)
        {
            if (n != i && m != i)
            {
                ll fn = ask(n, m, i);
                if (fn == 1)
                {
                    fn1 = i;
                }
                else
                {
                    fn2 = i;
                }
                imp[i] = fn;
            }
        }
        val = ask(n, fn1, fn2);
        imp[n] = val;
        val = ask(m, fn1, fn2);
        imp[m] = val;
        ll ans = 0;
 
        // cout<<n<<" "<<m<<endl;
        vector<ll> v;
        for (ll i = 1; i <= N; i++)
        {
            if (imp[i] == 0)
            {
                // cout<<i<<" ";
                v.push_back(i);
                ans++;
            }
        }
        cout << "! " << ans << " ";
        for(auto i:v){
            cout<<i<<" ";
        }
        cout << endl;
    }
 
    return 0;
}
 
// 0 1 1 0 1 0
