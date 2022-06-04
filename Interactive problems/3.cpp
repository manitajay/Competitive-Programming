// JAI BAJARANG BALI
 
// manitianajay45
 
// give me some sunshine, give me some rain, give me another chance to grow up once again
 
// sab moh maya hai....
 
// waiting....
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
ll ask(ll i)
{
 
    cout << "? " << i << endl;
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
        ll n;
        cin >> n;
        ll prr[n + 1];
        bool fl = false;
        vector<bool> flag(n + 1, false);
        ll cnt = 0;
 
        // ask(1);
        // ll i = 1;
        for (ll i = 1; i <= n; i++)
        {
            if (!flag[i])
            {
                ll in=ask(i);
                ll val=ask(i);
                if(in==val){
                    prr[in]=val;
                    continue;
                }
                while(!flag[val]){
                    prr[in]=val;
                    flag[val]=true;
                    in=val;
                    val=ask(i);
                }
            }
        }
        cout << "! ";
        for (ll i = 1; i <= n; i++)
        {
            cout << prr[i] << " ";
        }
        cout << endl;
    }
 
    return 0;
}
