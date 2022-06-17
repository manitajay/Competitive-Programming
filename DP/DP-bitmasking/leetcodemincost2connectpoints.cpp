class Solution {
public:
    int dp[13][(1<<12)+5];
    int mn[13];
    int ans(vector<vector<int>>& cost,int n,int m,int i,int mask){
        if(dp[i][mask]!=-1){
            return dp[i][mask];
        }
        int an=INT_MAX;
        if(i==n){
            an=0;
            // cout<<an<<endl;
            for(int j=0;j<m;j++){
                if(!((1<<j)&mask)){
                    an+=(mn[j]);
                }
            }
            // cout<<an<<endl;
            return an;
        }
        
        
        
        for(int j=0;j<m;j++){
            an=min(an,cost[i][j]+ans(cost,n,m,i+1,(mask|(1<<j))));
        }
        return dp[i][mask]=an;
        
    }
    
   
    
    
    int connectTwoGroups(vector<vector<int>>& cost) {
        memset(dp,-1,sizeof(dp));
        memset(mn,101,sizeof(mn));
        int mx=INT_MAX;
        int n=cost.size();
        int m=cost[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mn[i]=min(mn[i],cost[j][i]);
            }
            // cout<<mn[i]<<" ";
        }
        cout<<endl;
        mx=ans(cost,n,m,0,0);
        return mx;
    }
};
