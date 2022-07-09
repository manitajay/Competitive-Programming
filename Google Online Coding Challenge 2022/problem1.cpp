/*
  problem :
  given a n node tree with some value assign to each node you have to print no of paths starting from node 1 such that max frequency of value of that paths' node is >= half of the lenght of that path.
  
  constraint:
  1<=n<=10^5
  1<=val<=10^5
  
  
  test case:
  
    6
    1 6
    1 4
    4 3
    4 5
    4 2
    1 2 1 3 1 1
    
    
    now we know lest write all the paths 
    path1 1-2--> 1-4-2 (value wise 1 3 2 ) we can see frequency of 1 which is 1  is  equal to len/2(down) means 3/2=1;    --> true
    path2 1-3--> 1-4-3 (value wise 1 3 1 ) we can see frequency of 1 which is 2  is greater then len/2(down) means 3/2=1; --> true
    path3 1-4--> 1-4 (value wise 1 1 ) we can see frequency of 1 which is 2  is greater then len/2(down) means 2/2=1;     --> true
    path4 1-5--> 1-4-5 (value wise 1 3 1 ) we can see frequency of 1 which is 2  is greater then len/2(down) means 3/2=1; --> true
    path5 1-6--> 1-6 (value wise 1 1 ) we can see frequency of 1 which is 2  is greater then len/2(down) means 2/2=1;     --> true
    
    now we can clearly see all the paths satisfy the condition so answer will be 5;
    
    
    approach:-
    brute force:
     we can write simple dfs and maintain a cnt array which will store freq of nodes val;
     and manullay by iterating from 1 to n we can find max value of frequency so time comp will be O(n^2);
 
 
    optimal approach:
      now focus on count array how can we compute max in less time?
      segment trees?
      if we maintain a segment tree and then seg[0] will be max of that freq array so this query time comp--> O(1)
      and remember we need to update value  which will be in O(logn);
      so time comp--> O(nlogn);

*/



// JAI BAJARANG BALI

// manitianajay45

// give me some sunshine, give me some rain, give me another chance to grow up once again....

// sab moh maya hai....

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

ll n;


vector<ll> cnt(800005,0);
vector<ll> visited(100005,false);
vector<ll> crr(100005,0);
vector<ll> graph[100005];


void update(ll i,ll val,ll x,ll l,ll r){
    if(r-l==1){
        cnt[x]=val;
        return ;
    }

    ll mid=(l+r)/2;
    if(i<mid){
        update(i,val,2*x+1,l,mid);
    }else{
        update(i,val,2*x+2,mid,r);

    }
    cnt[x]=max(cnt[2*x+1],cnt[2*x+2]);
}

ll sz=1;


ll ans=0;
ll tl=1;

void dfs(ll v){

    visited[v]=true;
    for(auto i:graph[v]){
        if(!visited[i]){
            cnt[crr[i]]++;
            update(crr[i],cnt[crr[i]]+1,0,0,sz);
            tl++;
            ll mx=cnt[0];

            if(mx>=(tl)/2){
                ans++;
            }
            dfs(i);
            tl--;
            update(crr[i],cnt[crr[i]]-1,0,0,sz);

        }
    }


}

int main(){
    cin>>n;
    

    for(ll i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(ll i=1;i<=n;i++){
        cin>>crr[i];
    }

    while(sz<n){
        sz*=2;
    }
    update(crr[1],1,0,0,sz);

    dfs(1);
    cout<<ans<<endl;

    return 0;


}

