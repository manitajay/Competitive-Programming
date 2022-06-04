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
        ll val;
        vector<ll> vec;
        ll prev = -1;
        ll ind1 = 0, ind2 = 0;
 
        ll x, y;
        for (ll i = 1; i <= N; i += 3)
        {
            val = ask(i, i + 1, i + 2);
            vec.push_back(val);
            if (prev >= 0 && prev != val)
            {
                ind1 = i - 3;
                x = prev;
                y = val;
                ind2 = i;
            }
            prev = val;
        }
        ll imp[N + 1];
        memset(imp,-1,sizeof(imp));
        ll lr, rr;
        ll i1 = ind1, i2 = ind1 + 1, i3 = ind1 + 2;
        ll j1 = ind2, j2 = ind2 + 1, j3 = ind2 + 2;
        if (x == 0)
        {
            val = ask(i1, j1, j2);
 
            if (val == 0)
            {
                imp[i1] = 0;
                lr = i1;
                val = ask(i1, j1, j3);
                if (val == 1)
                {
                    imp[j1] = 1;
                    imp[j3] = 1;
                    imp[j2] = 0;
                    rr = j1;
                }
                else
                {
                    imp[j1] = 0;
                    imp[j2] = 1;
                    imp[j3] = 1;
                    rr = j2;
                }
            }
            else
            {
                val = ask(i2, j1, j2);
                if (val == 0)
                {
                    imp[i2] = 0;
                    lr = i2;
                    val = ask(i2, j1, j3);
                    if (val == 1)
                    {
                        imp[j1] = 1;
                        imp[j3] = 1;
                        imp[j2] = 0;
                        rr = j1;
                    }
                    else
                    {
                        imp[j1] = 0;
                        imp[j2] = 1;
                        imp[j3] = 1;
                        rr = j2;
                    }
                }else{
                    imp[j1]=1;
                    imp[j2]=1;
                    rr=j1;
                    val=ask(i1,i2,rr);
                    if(val==0){
                        lr=i1;
                        imp[i1]=0;
                    }else{
                        val=ask(i1,i3,rr);
                        if(val==0){
                            lr=i1;
                            imp[i1]=0;
                        }else{
                            lr=i2;
                            imp[i2]=0;
                            imp[i3]=0;
                            imp[i1]=1;
                        }
                    }
                }
            }
        }else{
            val = ask(j1, i1, i2);
            if (val == 0)
            {
                imp[j1] = 0;
                lr = j1;
                val = ask(j1, i1, i3);
                if (val == 1)
                {
                    imp[i1] = 1;
                    imp[i3] = 1;
                    imp[i2] = 0;
                    rr = i1;
                }
                else
                {
                    imp[i1] = 0;
                    imp[i2] = 1;
                    imp[i3] = 1;
                    rr = i2;
                }
            }
            else
            {
                val = ask(j2, i1, i2);
                if (val == 0)
                {
                    imp[j2] = 0;
                    lr = j2;
                    val = ask(j2, i1, i3);
                    if (val == 1)
                    {
                        imp[i1] = 1;
                        imp[i3] = 1;
                        imp[i2] = 0;
                        rr = i1;
                    }
                    else
                    {
                        imp[i1] = 0;
                        imp[i2] = 1;
                        imp[i3] = 1;
                        rr = i2;
                    }
                }else{
                    imp[i1]=1;
                    imp[i2]=1;
                    rr=i1;
                    val=ask(j1,j2,rr);
                    if(val==0){
                        lr=j1;
                        imp[j1]=0;
                    }else{
                        val=ask(j1,j3,rr);
                        if(val==0){
                            lr=j1;
                            imp[j1]=0;
                        }else{
                            lr=j2;
                            imp[j2]=0;
                            imp[j3]=0;
                            imp[j1]=1;
                        }
                    }
                }
            }
        }
        ll ans = 0;
        // cout<<lr<<" "<<rr<<endl;
        // cout<<n<<" "<<m<<endl;
        vector<ll> v;
        ll d=0;
        for (ll i = 1; i <= N; i+=3)
        {
 
            ll a=i,b=i+1,c=i+2;
 
            if(a!=lr && a!=rr && b!=lr && b!=rr && c!=lr && c!=rr){
                ll fun=vec[d];
                if(fun==1){
                    ll val1=ask(a,b,lr);
                    ll val2=ask(a,c,lr);
                    if(val1==1 && val2==1){
                        imp[a]=1;
                        imp[b]=1;
                        imp[c]=1;
                    }else if(val1==1 && val2==0)
                    {
                        imp[a]=1;
                        imp[c]=0;
                        imp[b]=1;
                    }else if(val1==0 && val2==1){
                        imp[a]=1;
                        imp[b]=0;
                        imp[c]=1;
                    }else{
                        imp[a]=0;
                        imp[b]=1;
                        imp[c]=1;
                    }
                }else{
                    ll val1=ask(a,b,rr);
                    ll val2=ask(a,c,rr);
                    if(val1==0 && val2==0){
                        imp[a]=0;
                        imp[b]=0;
                        imp[c]=0;
                    }else if(val1==0 && val2==1)
                    {
                        imp[a]=0;
                        imp[c]=1;
                        imp[b]=0;
                    }else if(val1==1 && val2==0){
                        imp[a]=0;
                        imp[b]=1;
                        imp[c]=0;
                    }else{
                        imp[a]=1;
                        imp[b]=0;
                        imp[c]=0;
                    }
                }
            }else{
                if(a!=lr && a!=rr){
                    imp[a]=ask(a,lr,rr);
                }
                if(b!=lr && b!=rr){
                    imp[b]=ask(b,lr,rr);
                }
                if(c!=lr && c!=rr){
                    imp[c]=ask(c,lr,rr);
                }
            }
            d++;
            
        }
        for(ll i=1;i<=N;i++){
            if(imp[i]==0){
                ans++;
                v.push_back(i);
            }
        }
        cout << "! " << ans << " ";
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
 
    return 0;
}
 
// 0 0 1 0 1 1
