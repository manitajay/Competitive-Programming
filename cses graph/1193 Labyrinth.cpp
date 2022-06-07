// JAI BAJARANG BALI
 
// manitianajay45
 
// give me some sunshine, give me some rain, give me another chance to grow up once again....
 
// sab moh maya hai....
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
ll n,m;
vector<string> grid(1005);
 
pair<ll,ll> par[1005][1005];
 
bool issafe(ll x,ll y){
    if(x>=0 && y>=0 && x<n && y<m && (grid[x][y]=='.' || grid[x][y]=='B')){
        return true;
    }
    return false;
}
 
ll xrr[4]={-1,0,1,0};
ll yrr[4]={0,-1,0,1};
char ch[4]={'U','L','D','R'};
 
 
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    ll stx,sty;
    
    for(ll i=0;i<n;i++){
        cin>>grid[i];
        for(ll j=0;j<grid[i].length();j++){
            if(grid[i][j]=='A'){
                stx=i;
                sty=j;
            }
        }
    }
 
 
    queue<pair<ll,ll>> q;
 
    q.push({stx,sty});
    bool flag=false;
    ll X,Y;
    while(!q.empty()){
        pair<ll,ll> pr=q.front();
        q.pop();
 
        for(ll i=0;i<4;i++){
            ll x=pr.first+xrr[i];
            ll y=pr.second+yrr[i];
 
            if(issafe(x,y)){
                q.push({x,y});
                par[x][y]={pr.first,pr.second};
                if(grid[x][y]=='B'){
                    X=x,Y=y;
                    flag=true;
                    break;
                }
                grid[x][y]='#';
            }
 
        }
 
        if(flag){
            break;
        }
    }
 
    if(!flag){
        cout<<"NO"<<endl;
        return 0;
    }
 
    cout<<"YES"<<endl;
 
    string s="";
    while(grid[X][Y]!='A'){
        pair<ll,ll> pr=par[X][Y];
 
        ll xr=X-pr.first;
        ll yr=Y-pr.second;
        // cout<<xr<<" "<<yr<<endl;
 
        for(ll i=0;i<4;i++){
            if(xr==xrr[i] && yr==yrr[i]){
                s+=ch[i];
                break;
            }
        }
 
        X=pr.first;
        Y=pr.second;
 
 
    }
    reverse(s.begin(),s.end());
    cout<<s.length()<<endl;
    cout<<s<<endl;
 
 
 
 
 
 
 
    return 0;
}
