// // tc o(n*w)+O(n)   
// int solve(int ind, int W,  vector<int> &profit, vector<int> &weight,  vector<vector<int>>&dp)
// {
//     if(ind==0)
//     {

//             return (W/weight[0])* profit[0];
//     }
//     if(dp[ind][W]!=-1) return dp[ind][W];
//    int  nottake=0+solve(ind-1, W,profit,weight,dp);
//     int take=-1e9;
//     if(weight[ind]<=W)
//     {
//         take=profit[ind]+solve(ind,W-weight[ind],profit, weight,dp);
//     }
//     return dp[ind][W]= max(take,nottake);
// }
// int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
// {
//     vector<vector<int>>dp(n,vector<int>(w+1,-1));
//     return solve(n-1,w,profit,weight,dp);
// }



int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>>dp(n,vector<int>(w+1,0));
    for(int W=0;W<=w;W++)
    {
         dp[0][W]=(W/weight[0])* profit[0];
    }
    for(int ind=1;ind<n;ind++)
    {
        for(int W=0;W<=w;W++)
        {
             int  nottake=0+dp[ind-1][W];
           int take=0;
         if(weight[ind]<=W)
          {
           take=profit[ind]+dp[ind][W-weight[ind]];
           }
            dp[ind][W]=max(take,nottake);
        }
    }
        return dp[n-1][w];
}
