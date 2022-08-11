class Solution {
public:
    bool solve(int ind, int target, vector<int>&arr,vector<vector<int>>&dp)
    {
    if(target==0) return true;
    if(ind==0) return arr[0]==target;
    if(dp[ind][target]!=-1) return dp[ind][target];
    int nottake=solve(ind-1,target,arr,dp);
    int take=false;
    if(arr[ind]<=target)
        take=solve(ind-1,target-arr[ind],arr,dp);
    return dp[ind][target]=take||nottake;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(sum%2==0){
            int k=sum/2;
            vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return solve(n-1,k,nums,dp);
        }
        return false;
       
    }
};