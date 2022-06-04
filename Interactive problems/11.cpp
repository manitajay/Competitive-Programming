// JAI BAJARANG BALI

// manitianajay45

// give me some sunshine, give me some rain, give me another chance to grow up once again....

// sab moh maya hai....

/*


    In this problem value means total length of functional railway line.
max value means using all functional line we can traverse through all railway station and value should be maximum (basically spanning tree with max value);
and min value vice versa

for example

        1---(1)-----2---(4)---4---(5)---5 
         \              /
           (2)     (3)
             \      /
               3

now max value= 2+ 3 +4+5;(in case of all functional railway lines (11111));
min value= 1+2 +4 +5    (in case of all functional railway lines (11111));

now approach is 

firstly we will find out all edges in m queries in each query we will fix a single railway line functional and other line will be not functional (10000,01000,00100,00010,00001);
now we have value of every edge

now we will sort it and put active intial j values for all 1<=J<=m;
and can find out which railway line must active and which don't need to be;
bcs order is sorted so the maximum will not included if a cycle created.




*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll ask(string s){
    cout<<"? "<<s<<endl;

    ll val;
    cin>>val;
    return val;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;


    string s="";
    for(ll i=0;i<m;i++){
        s+="0";
    }

    ll mx=INT_MAX;

    vector<pair<ll,ll>> edges;

    for(ll i=0;i<m;i++){
        s[i]='1';
        ll val=ask(s);
        edges.push_back({val,i});
        
        s[i]='0';
    }



    sort(edges.begin(),edges.end());

    ll ans=0;
    
    for(ll i=0;i<(ll)edges.size();i++){
        s[edges[i].second]='1';
        ll vl=ask(s);

        if(vl-ans==edges[i].first){
            ans+=edges[i].first;
        }else{
            s[edges[i].second]='0';

        }



    }

    cout<<"! "<<ans<<endl;
    return 0;
}
