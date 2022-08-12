int solve(int ind, int w,vector<int>&wt, vector<int>&val,vector<vector<int>>&dp)
{
    if(ind==0)
    {
        if(wt[0]<=w) return val[0];
        else return 0;
    }
    if(dp[ind][w]!=-1) return dp[ind][w];
    int nottake=0+solve(ind-1,w,wt,val,dp);
   int take=INT_MIN;
    if(wt[ind]<=w)
    {
        take=val[ind]+solve(ind-1,w-wt[ind],wt,val,dp);
    }
    return dp[ind][w]= max(take,nottake);
}
int knapsack(vector<int> wt, vector<int> val, int n, int maxWeight) 
{
//     vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
//     return solve(n-1,maxWeight,wt,val,dp);	
        vector<vector<int>>dp(n,vector<int>(maxWeight+1,0));
    for(int w=wt[0];w<=maxWeight;w++)
    {
        dp[0][w]=val[0];
    }
    for(int ind=1;ind<n;ind++)
    {
        for(int w=0;w<=maxWeight;w++)
        {
            int nottake=dp[ind-1][w];
            int take=INT_MIN;
            if(wt[ind]<=w)
             {
               take=val[ind]+dp[ind-1][w-wt[ind]];
              }
            dp[ind][w]=max(take,nottake);
        }
    }
    return dp[n-1][maxWeight];
}