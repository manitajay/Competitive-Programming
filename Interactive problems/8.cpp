// JAI BAJARANG BALI
 
// manitianajay45
 
// sab moh maya hai...
 
// give me some sunshine, give me some rain. give me another chance to grow up once again
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
ll n;
vector<pair<ll,ll>> ans;
vector<ll> ask(ll r)
{
    cout<<"? "<<r+1<<endl;
    cout<<endl;
    
    vector<ll> d(n);
    for(ll i=0;i<n;i++)
    {
        cin>>d[i];
        
    }
 
    return d;
    
}
 
int main()
{
    
    cin>>n;
    vector<ll> dl=ask(0);
    ll cnto=0,cnte=0;
    for(ll i=0;i<n;i++)
    {
        if(dl[i]%2==0)
        {
            cnte++;
        }else
        {
            cnto++;
        }
    }
    
    if(cnto>=cnte)
    {
        
        for(ll i=0;i<n;i++)
        {
            if(dl[i]%2==0)
            {
                vector<ll> vs(n);
                if(i==0)
                {
                    vs=dl;
                }else
                {
                    vs=ask(i);
                }
                for(ll j=0;j<n;j++)
                {
                    if(vs[j]==1)
                    {
                        ans.push_back(make_pair(i+1,j+1));
                    }
                }
                
            }
        }
    }else
    {
        for(ll i=0;i<n;i++)
        {
            if(dl[i]%2==1)
            {
                vector<ll> vs(n);
                if(i==0)
                {
                    vs=dl;
                }else
                {
                    vs=ask(i);
                }
                for(ll j=0;j<n;j++)
                {
                    if(vs[j]==1)
                    {
                        ans.push_back(make_pair(i+1,j+1));
                    }
                }
                
            }
        }
    }
 
 
    cout<<"!"<<endl;
    for(ll i=0;i<ans.size();i++)
    {
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
 
    
 
    return 0;
}
