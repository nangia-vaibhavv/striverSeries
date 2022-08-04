 int solve(int ind, int target, vector<int>&num, vector<vector<int>>&dp)
    {
        if(ind==0)
        {
            if(target%num[0]==0)
              return target/num[0];
            return 1e9;
        }
     if(dp[ind][target]!=-1) return dp[ind][target];
       int nottake=0+solve(ind-1,target,num,dp);
        int take=INT_MAX;
        if(num[ind]<=target)
        {
//             take same index again, for infinite supply take stands at same index
            take=1+solve(ind,target-num[ind],num,dp);
        }
        return dp[ind][target]= min(take,nottake);
    }
int minimumElements(vector<int> &num, int x)
{
    int n=num.size();
     vector<vector<int>>dp(n,vector<int>(x+1,-1));
    int ans=solve(n-1,x,num,dp);
    if(ans>=1e9)return -1;
   else return ans; 
    // Write your code here.
}