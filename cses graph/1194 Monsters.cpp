// JAI BAJARANG BALI
 
// manitianajay45
 
// give me some sunshine, give me some rain, give me another chance to grow up once again....
 
// sab moh maya hai....
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll int
 
ll n, m;
ll i,j,x,y,xr,yr,X,Y;
pair<pair<ll,ll>,ll> pr;

ll lr, rr;
pair<ll,ll> prr;
bool flag=false;
ll cnt=0;
vector<string> grid(1001);
vector<vector<ll>> mn_dis(1001, vector<ll>(1001, -1));
vector<vector<pair<ll, ll>>> par(1001, vector<pair<ll, ll>>(1001));
 
bool issafe(ll x, ll y)
{
    if (x >= 0 && y >= 0 && x < n && y < m && (mn_dis[x][y]==-1) && grid[x][y]!='#')
    {
        return true;
    }
    return false;
}

 
bool issafe1(ll x, ll y, ll cnt)
{
    if (x >= 0 && y >= 0 && x < n && y < m && (cnt < mn_dis[x][y] || mn_dis[x][y]==-1) && grid[x][y]=='.')
    {
        return true;
    }
    return false;
}
 
ll xrr[4] = {-1, 0, 1, 0};
ll yrr[4] = {0, -1, 0, 1};
char ch[4] = {'U', 'L', 'D', 'R'};
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    queue<pair<pair<ll, ll>,ll>> q;
 
    for (i = 0; i < n; i++)
    {
        string s;        
        cin>>s;
        grid[i]=s;
 
        for (j = 0; j < m; j++)
        {
            if (s[j] == 'M')
            {
                q.push({{i, j},0});
                mn_dis[i][j] = 0;
            }
            if (s[j][j] == 'A')
            {
                // grid[x][y]='#';
                lr = i;
                rr = j;
            }
        }
    }
    
    cnt = 0;
 
    while (!q.empty())
    {
        pr = q.front();
        q.pop();
        mn_dis[pr.first.first][pr.first.second] = pr.second;
 
        for (i = 0; i < 4; i++)
        {
            x = pr.first.first + xrr[i];
            y = pr.first.second + yrr[i];
            if (issafe(x, y))
            {
                q.push({{x, y},pr.second+1});
            }
        }
    }
    // cout<<"YES"<<endl;
 
    // for(ll i=0;i<n;i++){
    //     for(ll j=0;j<m;j++){
    //         cout<<mn_dis[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    
    q.push({{lr, rr},0});
    cnt = 1;
 
    
    while (!q.empty())
    {
        pr = q.front();
        q.pop();
 
        if(grid[pr.first.first][pr.first.second]=='.' ){
            grid[pr.first.first][pr.first.second]='#';
        }
 
        if (pr.first.first == 0 || pr.first.second == 0 || pr.first.first == n - 1 || pr.first.second == m - 1)
        {
            X=pr.first.first;
            Y=pr.first.second;
            flag = true;
            break;
        }
        for (i = 0; i < 4; i++)
        {
            x = pr.first.first + xrr[i];
            y = pr.first.second + yrr[i];
            if (issafe1(x, y, pr.second+1))
            {
                q.push({{x, y},pr.second+1});
                par[x][y] = pr.first;
            }
        }
    }
    // cout<<X<<" "<<Y<<endl;
 
    if (!flag)
    {
        cout << "NO" << endl;
        return 0;
    }
 
    cout<<"YES"<<endl;
    // cout<<par[2][6].first<<" "<<par[2][6].second<<endl;
    
    string s="";
    while(grid[X][Y]!='A'){ 
        xr=X-par[X][Y].first;
        yr=Y-par[X][Y].second;
        for(i=0;i<4;i++){
            if(xr==xrr[i] && yr==yrr[i]){
                s+=ch[i];
                break;
            }
        }
        // cout<<X<<" s"<<Y<<endl;
        prr=par[X][Y];
        X=prr.first;
        Y=prr.second;
        // cout<<X<<" "<<Y<<endl;
    }
    reverse(s.begin(),s.end());
    cout<<s.length()<<endl;
    cout<<s<<endl;
 
    return 0;
}
