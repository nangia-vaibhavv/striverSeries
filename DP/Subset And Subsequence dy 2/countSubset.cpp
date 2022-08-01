 int solve(int ind, int sum,vector<int>&num,vector<vector<int>>&dp)
    {
        if(sum==0)  return 1;
        if(ind==0) return num[0]==sum;
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        int nottake=solve(ind-1,sum,num,dp);
        int take=0;
        if(num[ind]<=sum)
            take=solve(ind-1,sum-num[ind],num,dp);
        return dp[ind][sum]=take+nottake;
    }
int findWays(vector<int> &num, int tar)
{
    // Write your code here.
      int n=num.size();
        vector<vector<int>>dp(n,vector<int>(tar+1,-1));
        return solve(n-1,tar,num,dp);
}