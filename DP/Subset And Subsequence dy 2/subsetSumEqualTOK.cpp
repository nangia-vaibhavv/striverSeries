// //RECURSION => tc: O(2^n) space: o(n)
////memoization tc: O(n*target)  space: O(n*target)+O(N)
// bool solve(int ind, int target, vector<int>&arr,vector<vector<int>>&dp)
// {
//     if(target==0) return true;
//     if(ind==0) return (target==arr[0]);
//     if(dp[ind][target]!=-1) return dp[ind][target];
//     bool nottake=solve(ind-1,target,arr,dp);
//     bool take=false;
//     if(arr[ind]<=target) take=solve(ind-1,target-arr[ind],arr,dp);
//     return dp[ind][target]= take||nottake;
// }
// bool subsetSumToK(int n, int k, vector<int> &arr) {
//     vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
//     return solve(n-1,k,arr,dp);
// }



// same as memoiattion just remove aux space
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>>dp(n+1,vector<bool>(k+1,0));
    for(int i=0;i<n;i++)
    {
        dp[i][0]=true;
    }
    dp[0][arr[0]]=true;
    for(int ind=1;ind<n;ind++)
    {
        for(int target=1;target<=k;target++)
        {
             bool nottake=dp[ind-1][target];
             bool take=false;
             if(arr[ind]<=target) take=dp[ind-1][target-arr[ind]];
            dp[ind][target]=take || nottake;
        }
    }
    return dp[n-1][k];
}

