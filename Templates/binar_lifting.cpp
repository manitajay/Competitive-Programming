

ll dp[200005][20];



void binlift(){
    for(ll i=1;i<20;i++){
        for(ll j=0;j<n;j++){
            if(dp[j][i-1]==-1){
                dp[j][i]=-1;
                continue;
            }
            dp[j][i]=dp[dp[j][i-1]][i-1];
        }
    }
 
 
}
 
 
ll query(ll x,ll k){
    ll prev=x;
    for(ll i=20;i>=0;i--){
        if((k>>i)&1){
            // cout<<i<<"i"<<endl;
            prev=dp[prev][i];
            if(prev==-1){
                break;
            }
 
        }
    }    
    return prev;
}







int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);



 

    
    memset(dp,-1,sizeof(dp));

    for(ll i=0;i<n;i++){
        dp[i][0]=parent[i];
    }

    binlift();
   









    return 0;
}
